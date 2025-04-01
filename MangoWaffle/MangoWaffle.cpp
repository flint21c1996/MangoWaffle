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