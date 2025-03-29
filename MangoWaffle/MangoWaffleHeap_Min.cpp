#include "MangoWaffleHeap_Min.h"

//push() ȣ�� �Ǿ����� ���� sort�� ���Ͽ�
//�� ������ index�� ���� �ְ� �θ�� ��� ���Ѵ�.
void MangoWaffleHeap::SortHeap_Push()
{
	int index = heap.size() - 1;
	int parentIndex = ParentIndex(index);

	//index�� 0�� �ǰų� heap[index]�� ���� �θ��� ������ �� Ŭ������ �ݺ��Ѵ�.
	while (index > 0 && heap[parentIndex] > heap[index])
	{
		std::swap(heap[parentIndex], heap[index]);
		index = parentIndex;
		parentIndex = ParentIndex(index);
	}
}

//���� pop()�� ȣ��Ǿ����� ���� sort�� ���ؼ�
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
