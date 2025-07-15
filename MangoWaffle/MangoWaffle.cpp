#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	//return값이 들어갈 백터
	vector<int> answer(prices.size(), -1);
	//1. 우선 반복문을 돌면서 스택에 넣는다.
	//2. 스택의 맨위가 현재보다 작을 경우 pop을 하고 해당 숫자가 몇개인지 계산한다.
	//3. 그 수 만큼 반복문을 돌리며 return배열을 채운다.

	//int 스택
	stack<int> tempStack;
	//popCount
	int popCount = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		//스택이 비어있다면..? 바로 넣어준다.
		if (tempStack.empty())
		{
			tempStack.push(prices[i]);
			continue;
		}
		//스택의 맨위보다 현재 초의 가격이 높다면? 스택에 push
		else if (tempStack.top() <= prices[i])
		{
			tempStack.push(prices[i]);
		}
		//스택의 맨위보다 현재 초의 가격이 낮다면? 스택에서 pop을 해주고 int popCount를 하나 증가시킨다.
		else
		{
			for (int j = i; !tempStack.empty()&&tempStack.top() > prices[i]; j--)
			{
				tempStack.pop();
				popCount++;
			}
			for (int k = 1; popCount != 0;)
			{
				if (answer[i - k] == -1)
				{
					answer[i - k] = k;
					popCount--;
				}
				k++;

			}
			tempStack.push(prices[i]);
		}

	}
	int index = prices.size()-1;
	int temp = 0;
	while (!tempStack.empty())
	{
		if (answer[index] == -1)
		{
			answer[index] = temp;
			tempStack.pop();

		}
		index--;
		temp++;
	}
	return answer;
}

int main()
{
	vector<int> prices = { 2,3,4,2,2,1,3 };
	vector<int> answer = solution(prices);

	int a = 10;
}