//요세푸스 문제
/*
N명의 사람이 원 형태로 서있다. 각 사람은 1부터 N까지 번호표를 갖고있다. 그리고 임의의 숫자 K가 주어졌을 때 다음과 같이 사람을 없앤다.
- 1번 번호표를 가진 사람 기준 시계 방향으로 K번째 사람을 없앤다.
- 없앤 사람 다음 사람을 기준으로 하고 다시 K번째 사람을 없앤다.
N과 K가 주어질때 마지막에 살아있는 사람의 번호를 반환하는 Solution()함수를 구현하시오.
*/

#include<iostream>
#include <queue>
using namespace std;


int solution(int N, int k)
{
	int result;

	queue<int> q;
	
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		for (int i = 1; i < k; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		q.pop();
	}
	result = q.front();
	return result;

}

void main()
{
	cout << solution(5, 2) << endl;
}