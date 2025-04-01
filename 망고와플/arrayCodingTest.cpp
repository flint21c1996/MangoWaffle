#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//�����迭 arr�� ������������ �����ؼ� ��ȯ�ϴ� solution�Լ��� �ϼ��ض�
//��������
//arr�� ���̴� 2�̻� 10^5�����̴�.
// arr ���� ���� -100,000�̻� 100,000�����̴�.

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

//������ ������ �����غ��̳� ���������� ���Ǳ�� �����Ѵ�.
//�ܼ��� O(N^2) ���ľ˰����� ����ߴٸ� �� ������ ����Ҽ� ������.
// sort�Լ��� ��� �⺻������ ����Ʈ, �ʹ� ���� ��� Ȥ�� �־��� ��찡 �߻��� ���ɼ��� �������� ������, �迭�� ���̰� ª����� ���������� �����Ѵ�.
//

//-------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//�����迭 lst�� �־�����. �迭�� �ߺ����� �����ϰ� �迭�����͸� ������������ �����ؼ� ��ȯ�ϴ� solution�Լ��� �����϶�.
//����
// ���̴� 2~1000
// ���Ұ��� -100,000 ~ 100,000

bool compare(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int> lst)
{
	sort(lst.begin(), lst.end(), compare);
	lst.erase(unique(lst.begin(), lst.end()), lst.end());	///unique �Լ��� ���� �������.

	return lst;
}

int main()
{
	vector<int> temp = { 2,1,1,3,2,5,4 };
	auto e = solution(temp);
}

//-------------------------------------�� �� �̾Ƽ� ���ϱ�------------------------------------
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
//-------------------------------------���ǰ��------------------------------------
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

	//������ ����(��ⷯ ������ ���� �����غ���.)
	//������ �¾Ҵ��� Ȯ�� -> �¾������ �ش� ������ �������Ѿ��Ѵ�.
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

	//���� ���� �������� ���� ã��.
	int temp = *max_element(vals.begin(), vals.end());	///algorithm ������� ���� �Լ��� �˰��ִ°��� ���� ������ �ɵ��ϴ�. ���� ��� Ǯ���� �ִ�.
	for (int i = 0; i < vals.size(); i++)
	{
		if (temp == vals[i])
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}
//------------------------------------������--------------------------------------
//�Ʒ��� ������ �F���� �� Ǯ��� �������ϴ�.
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
//N = ��ü ���������� ����, stages ����ڰ� ���� �����ִ� �������� 1~N+1 / N+1�� ��� ��ü �ٱ�
vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<int> peopleStop(N, 0);
	vector<int> peopleStage(N, 0);
	vector<tuple<int, float>> result(N);
	for (int i = 0; i < stages.size(); i++)
	{
		//���������� Ŭ������ ���
		for (int j = 0; j < stages[i] - 1; j++)
		{
			peopleStage[j]++;
		}

		//���������� �����ִ� ���
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
//------------------------------------�湮 ����--------------------------------------
//�Ʒ��� ������ �ѹ� �� Ǯ��� �������ϴ�. >> ���� �� ����ȭ �Ҽ� ������ ��������
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
