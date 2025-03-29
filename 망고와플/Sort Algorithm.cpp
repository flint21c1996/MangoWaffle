#include <iostream>
#include <vector>
using namespace std;

void MW_BubbleSort(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (vec[j - 1] > vec[j])
			{
				swap(vec[j - 1], vec[j]);
			}
		}
	}
}

void MW_SelectionSort(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		int minValIndex = i;
		for (int j = i; j < size; j++)
		{
			if (vec[j] < vec[minValIndex])
			{
				minValIndex = j;
			}
		}
		swap(vec[i], vec[minValIndex]);
	}
}

void MW_InsertionSort(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 1; i < size; i++)
	{
		int targetNum = vec[i];	//타겟 대상
		int j = i - 1;
		while (j >= 0 && vec[j] > targetNum)	//j가 0보다 크거나 타겟보다 클 경우만 동작하도록
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = targetNum;					//타겟넘버를 알맞은 위치에 삽입
	}
}
void MW_Merge(vector<int>& vec, int startIndex, int middleIndex, int endIndex)
{
	vector<int> temp;

	//시작점과 중간지점, 끝나는 지점의 분할된 벡터끼리 비교를 하고, 새로운 벡터에 넣어주어야 한다.
	int firstTarget = startIndex;
	int secondTarget = middleIndex + 1;
	while (firstTarget <= middleIndex && secondTarget <= endIndex)
	{
		//첫번째 타겟 두번째 타겟보다 작을 경우
		if (vec[firstTarget] < vec[secondTarget])
		{
			temp.push_back(vec[firstTarget]);
			firstTarget++;
		}
		//두번째 타겟이 첫번째 타겟과 같거나 작을 경우
		else
		{
			temp.push_back(vec[secondTarget]);
			secondTarget++;
		}
	}
	///비교가 끝난후 남아있는 수들이 있을경우 추가작업
	while (firstTarget <= middleIndex)		//첫번째 분할된 벡터에 남아있을경우
	{
		temp.push_back(vec[firstTarget]);
		firstTarget++;
	}
	while (secondTarget <= endIndex)		//두번째 분할된 벡터에 남아있을경우 
	{
		temp.push_back(vec[secondTarget]);
		secondTarget++;
	}

	///tempVec의 안에 있는 값을 다시 원래 벡터에 넣어주어야한다.
	for (int i = 0; i < temp.size(); i++)
	{
		vec[startIndex + i] = temp[i];
	}
	return;
}

void MW_MergeSort(vector<int>& vec, int startIndex, int endIndex)
{
	if (startIndex < endIndex)								 ///재귀 종료의 조건문 각 배열의 크기가 0이되면 종료가된다.
	{
		int middleIndex = (startIndex + endIndex) / 2;
		MW_MergeSort(vec, startIndex, middleIndex);			//재귀를 돌며 분할한다.
		MW_MergeSort(vec, middleIndex + 1, endIndex);			//재귀를 돌며 분할한다.

		MW_Merge(vec, startIndex, middleIndex, endIndex);
	}
}

void MW_QuickSort(vector<int>& vec, int start, int end)
{

	if (start >= end) return;

	int pivot = vec[start];
	int low = start + 1;
	int high = end;

	while (low <= high) //둘이 엇갈리지 않을때까지 반복한다.
	{
		while (low <= end && vec[low] <= pivot)	//pivot보다 작으면 low를 계속 증가시킬수 있게
		{
			low++;
		}
		while (high > start && vec[high] >= pivot)	//pivot보다 클 경우 high를 계속 감소시킨다.
		{
			high--;
		}

		if (low < high) //low, high 모두 멈췄을 경우 swap해준다.
		{
			swap(vec[low], vec[high]);
		}
	}

	swap(vec[start], vec[high]); // 피봇을 알맞은 자리로

	MW_QuickSort(vec, start, high - 1); // 피봇기준 왼쪽 정렬
	MW_QuickSort(vec, high + 1, end);   // 피봇기준 오른쪽 정렬

}
void heapify(vector<int>& vec, int vecSize, int index)
{
	int size = vecSize;
	int largestIndex = index;			//자식들과 부모중 가장 큰데이터의 index를 갖는 변수
	int leftChildIndex = index * 2 + 1;
	int rightChildIndex = index * 2 + 2;

	if (leftChildIndex <size && vec[leftChildIndex] > vec[largestIndex])
	{
		largestIndex = leftChildIndex;
	}
	if (rightChildIndex <size && vec[rightChildIndex] > vec[largestIndex])
	{
		largestIndex = rightChildIndex;
	}
	//만약 largest !=index일 경우 재귀를 돌며 최대힙 조건을 맞춰준다.
	if (index != largestIndex)
	{
		swap(vec[index], vec[largestIndex]);
		heapify(vec, size, largestIndex);
	}
}

void MW_HeapSort(vector<int>& vec)
{
	int size = vec.size();

	///일단 주어진 vecter을 최대힙을 만든다.
	//가장 비단말 노드부터 시작하여 루트 노드까지 반복적으로 heapify함수를 호출.
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(vec, size, i);
	}

	///루드 노트를 맨뒤로 보내고 heapify함수를 호출한다.
	for (int i = size - 1; i > 0; i--)
	{
		swap(vec[0], vec[i]);
		heapify(vec, i, 0);
	}
}

int main()
{
	vector<int> vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_BubbleSort(vec);
	vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_SelectionSort(vec);
	vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_InsertionSort(vec);
	vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_MergeSort(vec, 0, vec.size() - 1);
	vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_QuickSort(vec, 0, vec.size() - 1);
	vec = { 9,5,7,8,3,1,4,6,7,2,2 };
	MW_HeapSort(vec);
	int a = 10;
}