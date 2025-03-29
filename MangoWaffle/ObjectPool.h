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
	//������Ʈ�� �߰��Ѵ�.
	bool AddObject(unsigned int _index, T& _object);

	//������Ʈ�� �����.
	bool EraseObject(unsigned int _index);

	//Ǯ�� ����.
	void ClearPool();

	//������Ʈ Ǯ�� ����� �����Ѵ�.
	void ResizeVec(unsigned int _size);

	//Ư�� ������Ʈ�� �ּҸ� ��ȯ�Ѵ�.
	T GetObject(unsigned int _index);

	//Ư�� ������Ʈ�� ������Ʈ�Ѵ�.
	bool UpdateObject(unsigned int _index, T& _object);

	//������Ʈ Ǯ�� ��ȯ�Ѵ�.
	const std::tuple<std::vector<T>*, std::vector<bool>*> GetObjectPool();

	//������Ʈ�� �������� ��� �ش� �޸𸮸� �����Ѵ�.
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
