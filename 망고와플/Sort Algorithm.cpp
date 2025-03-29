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
		int targetNum = vec[i];	//Ÿ�� ���
		int j = i - 1;
		while (j >= 0 && vec[j] > targetNum)	//j�� 0���� ũ�ų� Ÿ�ٺ��� Ŭ ��츸 �����ϵ���
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = targetNum;					//Ÿ�ٳѹ��� �˸��� ��ġ�� ����
	}
}
void MW_Merge(vector<int>& vec, int startIndex, int middleIndex, int endIndex)
{
	vector<int> temp;

	//�������� �߰�����, ������ ������ ���ҵ� ���ͳ��� �񱳸� �ϰ�, ���ο� ���Ϳ� �־��־�� �Ѵ�.
	int firstTarget = startIndex;
	int secondTarget = middleIndex + 1;
	while (firstTarget <= middleIndex && secondTarget <= endIndex)
	{
		//ù��° Ÿ�� �ι�° Ÿ�ٺ��� ���� ���
		if (vec[firstTarget] < vec[secondTarget])
		{
			temp.push_back(vec[firstTarget]);
			firstTarget++;
		}
		//�ι�° Ÿ���� ù��° Ÿ�ٰ� ���ų� ���� ���
		else
		{
			temp.push_back(vec[secondTarget]);
			secondTarget++;
		}
	}
	///�񱳰� ������ �����ִ� ������ ������� �߰��۾�
	while (firstTarget <= middleIndex)		//ù��° ���ҵ� ���Ϳ� �����������
	{
		temp.push_back(vec[firstTarget]);
		firstTarget++;
	}
	while (secondTarget <= endIndex)		//�ι�° ���ҵ� ���Ϳ� ����������� 
	{
		temp.push_back(vec[secondTarget]);
		secondTarget++;
	}

	///tempVec�� �ȿ� �ִ� ���� �ٽ� ���� ���Ϳ� �־��־���Ѵ�.
	for (int i = 0; i < temp.size(); i++)
	{
		vec[startIndex + i] = temp[i];
	}
	return;
}

void MW_MergeSort(vector<int>& vec, int startIndex, int endIndex)
{
	if (startIndex < endIndex)								 ///��� ������ ���ǹ� �� �迭�� ũ�Ⱑ 0�̵Ǹ� ���ᰡ�ȴ�.
	{
		int middleIndex = (startIndex + endIndex) / 2;
		MW_MergeSort(vec, startIndex, middleIndex);			//��͸� ���� �����Ѵ�.
		MW_MergeSort(vec, middleIndex + 1, endIndex);			//��͸� ���� �����Ѵ�.

		MW_Merge(vec, startIndex, middleIndex, endIndex);
	}
}

void MW_QuickSort(vector<int>& vec, int start, int end)
{

	if (start >= end) return;

	int pivot = vec[start];
	int low = start + 1;
	int high = end;

	while (low <= high) //���� �������� ���������� �ݺ��Ѵ�.
	{
		while (low <= end && vec[low] <= pivot)	//pivot���� ������ low�� ��� ������ų�� �ְ�
		{
			low++;
		}
		while (high > start && vec[high] >= pivot)	//pivot���� Ŭ ��� high�� ��� ���ҽ�Ų��.
		{
			high--;
		}

		if (low < high) //low, high ��� ������ ��� swap���ش�.
		{
			swap(vec[low], vec[high]);
		}
	}

	swap(vec[start], vec[high]); // �Ǻ��� �˸��� �ڸ���

	MW_QuickSort(vec, start, high - 1); // �Ǻ����� ���� ����
	MW_QuickSort(vec, high + 1, end);   // �Ǻ����� ������ ����

}
void heapify(vector<int>& vec, int vecSize, int index)
{
	int size = vecSize;
	int largestIndex = index;			//�ڽĵ�� �θ��� ���� ū�������� index�� ���� ����
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
	//���� largest !=index�� ��� ��͸� ���� �ִ��� ������ �����ش�.
	if (index != largestIndex)
	{
		swap(vec[index], vec[largestIndex]);
		heapify(vec, size, largestIndex);
	}
}

void MW_HeapSort(vector<int>& vec)
{
	int size = vec.size();

	///�ϴ� �־��� vecter�� �ִ����� �����.
	//���� ��ܸ� ������ �����Ͽ� ��Ʈ ������ �ݺ������� heapify�Լ��� ȣ��.
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(vec, size, i);
	}

	///��� ��Ʈ�� �ǵڷ� ������ heapify�Լ��� ȣ���Ѵ�.
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