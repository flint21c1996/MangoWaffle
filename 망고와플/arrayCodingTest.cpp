#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//정수배열 arr을 오름차순으로 정렬해서 반환하는 solution함수를 완성해라
//제약조건
//arr의 길이는 2이상 10^5이하이다.
// arr 원소 값은 -100,000이상 100,000이하이다.

vector<int> solution(vector<int> arr)
{
	sort(arr.begin(), arr.end());
	return arr;
}

int main()
{
	vector<int>arr = { 1, -5, 2, 4, 3 };
	vector<int> value = solution(arr);
}

//문제만 놓고보면 간단해보이나 제약조건을 주의깊게 봐야한다.
//단순히 O(N^2) 정렬알고리즘을 사용했다면 이 문제는 통과할수 없었다.
// sort함수의 경우 기본적으로 퀵소트, 너무 많은 재귀 혹은 최악의 경우가 발생할 가능성이 있을때는 힙정렬, 배열의 길이가 짧을경우 선택정렬을 수행한다.
//

//-------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//정수배열 lst가 주어진다. 배열의 중복값을 제거하고 배열데이터를 내림차순으로 정렬해서 반환하는 solution함수를 구현하라.
//제약
// 길이는 2~1000
// 원소값은 -100,000 ~ 100,000

bool compare(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int> lst)
{
	sort(lst.begin(), lst.end(), compare);
	lst.erase(unique(lst.begin(), lst.end()), lst.end());	///unique 함수에 대해 기억하자.

	return lst;
}

int main()
{
	vector<int> temp = { 2,1,1,3,2,5,4 };
	auto e = solution(temp);
}

//-------------------------------------두 개 뽑아서 더하기------------------------------------
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (i != j)
			{
				answer.push_back(numbers[i] + numbers[j]);
			}
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}
//-------------------------------------모의고사------------------------------------
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> _1 = { 1,2,3,4,5 };
	vector<int> _2 = { 2,1,2,3,2,4,2,5 };
	vector<int> _3 = { 3,3,1,1,2,2,4,4,5,5 };
	vector<int> vals = { 0,0,0 };

	//나머지 연산(모듈러 연산을 통해 접근해보자.)
	//정답이 맞았는지 확인 -> 맞았을경우 해당 변수를 증가시켜야한다.
	for (int i = 0; i < answers.size(); i++)
	{
		if (_1[i % 5] == answers[i])
		{
			vals[0]++;
		}
		if (_2[i % 8] == answers[i])
		{
			vals[1]++;
		}
		if (_3[i % 10] == answers[i])
		{
			vals[2]++;
		}
	}

	//제일 많이 맞춘사람의 답을 찾자.
	int temp = *max_element(vals.begin(), vals.end());	///algorithm 헤더내의 저런 함수를 알고있는것이 많은 도움이 될듯하다. 물론 없어도 풀수는 있다.
	for (int i = 0; i < vals.size(); i++)
	{
		if (temp == vals[i])
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}
//------------------------------------실패율--------------------------------------
//아래의 문제는 핮ㄴ번 더 풀어보면 좋을듯하다.
#include <string>
#include <vector>
#include <algorithm>
#include<tuple>

using namespace std;

bool compare(tuple<int, float> a, tuple<int, float> b)
{
	if (get<1>(a) == get<1>(b))
	{
		return get<0>(a) < get<0>(b);
	}
	return get<1>(a) > get<1>(b);
}
//N = 전체 스테이지의 개수, stages 사용자가 현재 멈춰있는 스테이지 1~N+1 / N+1의 경우 전체 다깸
vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<int> peopleStop(N, 0);
	vector<int> peopleStage(N, 0);
	vector<tuple<int, float>> result(N);
	for (int i = 0; i < stages.size(); i++)
	{
		//스테이지를 클리어한 사람
		for (int j = 0; j < stages[i] - 1; j++)
		{
			peopleStage[j]++;
		}

		//스테이지에 멈춰있는 사람
		if (stages[i] != N + 1)
		{
			peopleStop[stages[i] - 1]++;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		if ((peopleStop[i] + peopleStage[i]) == 0)
		{
			result[i] = { i,0 };
		}
		else
			result[i] = { i, static_cast<float>(peopleStop[i]) / (peopleStop[i] + peopleStage[i]) };
	}
	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < result.size(); i++)
	{
		answer.push_back(get<0>(result[i]) + 1);
	}

	return answer;
}
int main()
{
	int n = 5;
	vector<int> a = { 2, 1, 2, 6, 2, 4, 3, 3 };
	auto e = solution(5, a);
	return 0;
}
//------------------------------------방문 길이--------------------------------------
//아래의 문제는 한번 더 풀어보면 좋을듯하다. >> 조금 더 최적화 할수 있으면 좋았을껄
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//이차원 배열을 통해 풀어보자.
//배열을 할당받고, 캐릭터가 걷는길의 배열을 바꾸자.

int _x[4] = { 0,0,-1,1 }; //상,하,좌,우
int _y[4] = { 1,-1,0,0 };

int solution(string dirs) {
	int answer = 0;
	//가로세로 0~10까지의 이중배열을 만들자.
	bool path[11][11][4];
	pair<int, int> pos = { 5,5 };
	for (int i = 0; i < dirs.size(); i++)
	{
		pair<int, int> tempPos = pos;
		//string값에 따라 tempPos값에 특정인자를 더하고 빼준다.
		if (dirs[i] == 'U')
		{
			tempPos.first += _x[0];
			tempPos.second += _y[0];
		};
		if (dirs[i] == 'D')
		{
			tempPos.first += _x[1];
			tempPos.second += _y[1];
		};
		if (dirs[i] == 'L')
		{
			tempPos.first += _x[2];
			tempPos.second += _y[2];
		};
		if (dirs[i] == 'R')
		{
			tempPos.first += _x[3];
			tempPos.second += _y[3];
		};

		//만약 포지션이 범위를 벗어난다면 continue한다.
		if (tempPos.first < 0 || tempPos.first>10 || tempPos.second < 0 || tempPos.second>10)
		{
			continue;
		}
		//벗어나지 않았을경우 배열의 3차원 공간의 값을 바꿔준다.
		if (dirs[i] == 'U')
		{
			path[tempPos.first][tempPos.second][1] = false;
			path[pos.first][pos.second][0] = false;
		}
		if (dirs[i] == 'D')
		{
			path[tempPos.first][tempPos.second][0] = false;
			path[pos.first][pos.second][1] = false;
		}
		if (dirs[i] == 'L')
		{
			path[tempPos.first][tempPos.second][3] = false;
			path[pos.first][pos.second][2] = false;
		}
		if (dirs[i] == 'R')
		{
			path[tempPos.first][tempPos.second][2] = false;
			path[pos.first][pos.second][3] = false;
		}

		pos = tempPos;
	}

	//path배열의 전체를 순환하면서 true의 값을 저장하고 2로 나눈다.
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (path[i][j][k] == false)
				{
					answer++;
				}
			}
		}
	}
	answer /= 2;
	return answer;
}

int main()
{
	string a = "LULLLLLLU";
	int b = solution(a);
	std::cout << b;
}
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
