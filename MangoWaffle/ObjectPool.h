#pragma once
#include "ObjectPool.h"
#include <vector>
#include <type_traits>	//is_pointer
#include <tuple>

#ifdef _DEBUG
#include <iostream>
#define DEBUG_LOG(message) std::cout<<message<<std::endl
#endif // DEBUG

template<typename T>
class ObjectPool
{
public:
	ObjectPool(int _size)
	{
		ResizeVec(_size);
		mSize = _size;
	};
	~ObjectPool()
	{
		ClearPool();
	}
private:
	std::vector<T> mObjectVec;
	std::vector<bool> misAvailableVec;
	unsigned int mSize;
public:
	//오브젝트를 추가한다.
	bool AddObject(unsigned int _index, T& _object);

	//오브젝트를 지운다.
	bool EraseObject(unsigned int _index);

	//풀을 비운다.
	void ClearPool();

	//오브젝트 풀의 사이즈를 변경한다.
	void ResizeVec(unsigned int _size);

	//특정 오브젝트의 주소를 반환한다.
	T GetObject(unsigned int _index);

	//특정 오브젝트를 업데이트한다.
	bool UpdateObject(unsigned int _index, T& _object);

	//오브젝트 풀을 반환한다.
	const std::tuple<std::vector<T>*, std::vector<bool>*> GetObjectPool();

	//오브젝트가 포인터일 경우 해당 메모리를 해제한다.
	bool DeleteObjMemory(unsigned int _index);
};


template<typename T>
bool ObjectPool<T>::DeleteObjMemory(unsigned int _index)
{
	if constexpr (std::is_pointer<T>::value)
	{
		if (mObjectVec[_index])
		{
			delete mObjectVec[_index];
			return true;
		}
		else
		{
			DEBUG_LOG("DeleteObjMemory - AlreadyNull");
			return false;
		}
	}
	else
	{
		DEBUG_LOG("DeleteObjMemory - NotPointer");
		return false;
	}
}

template<typename T>
bool ObjectPool<T>::UpdateObject(unsigned int _index, T& _object)
{
	if (mSize <= _index)
	{
		DEBUG_LOG("UpdateObject - NotExist");
		return false;
	}
	if (misAvailableVec[_index])
	{
		DEBUG_LOG("UpdateObject - NotExist");
		return false;
	}
	else
	{
		mObjectVec[_index] = _object;
		return true;
	}
}

template<typename T>
const std::tuple<std::vector<T>*, std::vector<bool>*> ObjectPool<T>::GetObjectPool()
{
	return { &mObjectVec, &misAvailableVec };
}

template<typename T>
T ObjectPool<T>::GetObject(unsigned int _index)
{
	if (mSize <= _index)
	{
		DEBUG_LOG("UpdateObject - OverSize");
		return T();
	}
	if (misAvailableVec[_index])
	{
		DEBUG_LOG("GetObject - NotExist");
		return T();
	}
	else
	{
		return mObjectVec[_index];
	}
}

template<typename T>
void ObjectPool<T>::ResizeVec(unsigned int _size)
{
	mObjectVec.resize(_size);
	misAvailableVec.resize(_size);

	if (_size > mSize)
	{
		for (unsigned int i = mSize; i < _size; i++)
		{
			misAvailableVec[i] = true;
		}
		mSize = _size;
	}
}


template<typename T>
void ObjectPool<T>::ClearPool()
{
	for (int i = 0; i < mObjectVec.size(); i++)
	{
		EraseObject(i);
	}
	ResizeVec(0);
}


template<typename T>
bool ObjectPool<T>::EraseObject(unsigned int _index)
{
	if (mSize <= _index)
	{
		DEBUG_LOG("UpdateObject - OverSize");
		return false;
	}

	if (misAvailableVec[_index])
	{
		DEBUG_LOG("EraseObject - NotExist");
		return false;
	}
	else
	{
		misAvailableVec[_index] = true;
		return true;
	}
}

template<typename T>
bool ObjectPool<T>::AddObject(unsigned int _index, T& _object)
{
	if (_index < mSize)
	{
		if (misAvailableVec[_index])
		{
			mObjectVec[_index] = _object;
			misAvailableVec[_index] = false;
			return true;
		}
		else
		{
			DEBUG_LOG("AddObject - NotAvailable");
			return false;
		}
	}
	else
	{
		ResizeVec(_index + 1);
		return AddObject(_index, _object);
	}
}
