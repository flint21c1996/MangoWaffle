#pragma once
#include <vector>
#include <iostream>
class MangoWaffleHeap
{
public:
	MangoWaffleHeap() {};
	~MangoWaffleHeap() {};

private:
	std::vector<int> heap;

public:
	int asd();
public:
	//부모의 index를 반환한다.
	int ParentIndex(int _index)
	{
		return (_index - 1) / 2;
	}

	//왼쪽 자식의 index를 반환한다.
	int LeftIndex(int _index)
	{
		int result = (_index * 2) + 1;
		if (result < heap.size())
			return result;
		else
			return 0;
	}

	//오른쪽 자식의 index를 반환한다.
	int RightIndex(int _index)
	{
		int result = (_index * 2) + 2;
		if (result < heap.size())
			return result;
		else
			return 0;
	}

	//힙이 비었는가?
	bool IsEmpty()
	{
		return heap.empty();
	}
	void push(int value)
	{
		heap.push_back(value);
		SortHeap_Push();
	}
	int pop()
	{
		if (IsEmpty())
		{
			std::cout << "empty" <<std::endl;
			return -1;
		}
		int returnValue = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		SortHeap_Pop(0);
		return returnValue;
	}
	void printHeap()
	{
		for (int i = 0; i < heap.size(); i++) 
		{
			std::cout << heap[i] << " ";
		}
		std::cout << std::endl;
	}
private:
	void SortHeap_Push();
	void SortHeap_Pop(int _index);
};
