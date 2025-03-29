#include "MangoWaffleHeap_Min.h"

//push() 호출 되었을때 힙의 sort를 위하여
//맨 마지막 index에 값을 넣고 부모와 계속 비교한다.
void MangoWaffleHeap::SortHeap_Push()
{
	int index = heap.size() - 1;
	int parentIndex = ParentIndex(index);

	//index가 0이 되거나 heap[index]의 값이 부모의 값보다 더 클때까지 반복한다.
	while (index > 0 && heap[parentIndex] > heap[index])
	{
		std::swap(heap[parentIndex], heap[index]);
		index = parentIndex;
		parentIndex = ParentIndex(index);
	}
}

//힙에 pop()가 호출되었을때 힙의 sort을 위해서
void MangoWaffleHeap::SortHeap_Pop(int _index)
{
	int rightIndex = RightIndex(_index);
	int leftIndex = LeftIndex(_index);
	if (rightIndex && leftIndex)
	{
		int changeIndex = heap[rightIndex] <= heap[leftIndex] ? rightIndex : leftIndex;

		if (heap[changeIndex] < heap[_index])
		{
			std::swap(heap[changeIndex], heap[_index]);
			SortHeap_Pop(changeIndex);
		}
	}
	else if (!rightIndex && leftIndex)
	{
		int changeIndex = leftIndex;
		if (heap[changeIndex] < heap[_index])
		{
			std::swap(heap[changeIndex], heap[_index]);
			return;
		}
	}
	else
	{
		return;
	}

}
