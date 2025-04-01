#include <string>
#include <vector>
#include <iostream>
using namespace std;

//������ �迭�� ���� Ǯ���.
//�迭�� �Ҵ�ް�, ĳ���Ͱ� �ȴ±��� �迭�� �ٲ���.

int _x[4] = { 0,0,-1,1 }; //��,��,��,��
int _y[4] = { 1,-1,0,0 };

int solution(string dirs) {
	int answer = 0;
	//���μ��� 0~10������ ���߹迭�� ������.
	bool path[11][11][4];
	pair<int, int> pos = { 5,5 };
	for (int i = 0; i < dirs.size(); i++)
	{
		pair<int, int> tempPos = pos;
		//string���� ���� tempPos���� Ư�����ڸ� ���ϰ� ���ش�.
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

		//���� �������� ������ ����ٸ� continue�Ѵ�.
		if (tempPos.first < 0 || tempPos.first>10 || tempPos.second < 0 || tempPos.second>10)
		{
			continue;
		}
		//����� �ʾ������ �迭�� 3���� ������ ���� �ٲ��ش�.
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

	//path�迭�� ��ü�� ��ȯ�ϸ鼭 true�� ���� �����ϰ� 2�� ������.
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