#include <iostream>
using namespace std;

int len;
char* g_Queue = nullptr;
int in_Index = 0;
int out_Index = 0;

void ResetStack() ///���� �ʱ�ȭ ��Ű��~~~
{
    for (int i = 0; i < len; i++)
    {
        g_Queue[i] = ' ';
    }
}

void PrintStack() /// ���� ����ϴ� �Լ�~ in/out�� �ϳ��� �־��ָ� ����
{
    cout << endl << "--------------------------------------------------" << endl;

    for (int i = 0; i < len; i++)
    {
        // if (g_Queue[i] == ' ') continue;
        cout << '[' << g_Queue[i] << ']' << ' ';
    }

    cout << endl << "--------------------------------------------------" << endl;
    cout << endl;
}

void PushDataToStack(char data)
{
    if (g_Queue[in_Index] != ' ')///�ȿ� ���� �������� �ε��� ���ڵ� ���� ���ϰ� ����á�ٰ� ���ϰ�
    {
        cout << endl << "ť�� ���� á���ϴ�" << endl;
        return;
    }

    g_Queue[in_Index] = data; ///�ְ� �ε��� �ϳ� ��������
    in_Index++;
    if (in_Index + 1 > len) ///���� ������Ų�� ÷�� ������ ũ�⺸�� ũ��? �׷� ÷���� ��������
    {
        in_Index = 0;
    }
    PrintStack();
}

int PopDataToStack()
{
    if (g_Queue[out_Index] == ' ')                                                  ///in_Index�� ���� ����
    {
        cout << endl << "ť�� ������ϴ�! �� ���� �����ϴ�." << endl;
        return 0;
    }

    char _result = ' ';
    _result = g_Queue[out_Index];
    g_Queue[out_Index] = ' ';
    out_Index++;
    if (out_Index + 1 > len)
    {
        out_Index = 0;
    }
    PrintStack();

    cout << endl << "ť���� " << _result << "�� �����ϴ�." << endl;
    PrintStack();

    return _result;
}

int main()
{
    cout << "ť�� ����� �Է����ּ���." << endl;
    cin >> len;
    g_Queue = new char[len];

    ResetStack();

    while (true)
    {
        cout << "ť�� ���� ���ڸ� �Է����ּ���. -�Է½� ���ڸ� �̽��ϴ�." << endl;
        char j;
        cin >> j;

        if (j == '-')
        {
            PopDataToStack();
        }
        else
        {
            PushDataToStack(j);
        }

        cout << endl;
        cout << endl;
    }

    delete[] g_Queue;

    return 0;
}

//////////////////////////////////////////////////////////////////////////
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
struct Point
{
	int x;
	int y;
	int answer;
};
int solution(vector<vector<int>> maps)
{
	std::queue<Point> myqueue;

	//�켱 ���������� 0,0�����ϰ� ���������� 4,4�������.
	Point startPoint = { 0, 0, 0 };
	myqueue.push(startPoint);
	maps[startPoint.x][startPoint.y] = 0;

	//��, �Ʒ�, ����, �������� �迭�� �̸� ���������.
	int move_x[4] = { 0,0,-1,1 };
	int move_y[4] = { -1,1,0,0 };

	while (!(startPoint.x == 4 && startPoint.y == 4))
	{
		if (myqueue.empty())
		{
			return -1;
		}
		for (int j = 0; j < myqueue.size(); j++)
		{

			//ť�� �� �պκ��� ������
			startPoint = myqueue.front();
			myqueue.pop();

			//���� ���������̶��
			if (startPoint.x == 4 && startPoint.y == 4)
			{
				return ++startPoint.answer;
			}

			//���� ��ġ�� 0���� ������ش�.
			maps[startPoint.y][startPoint.x] = 0;

			//�׸��� �˻縦 ��������.
			for (int i = 0; i < 4; i++)
			{
				Point temp = startPoint;
				temp.x += move_x[i];
				temp.y += move_y[i];
				if (temp.x >= 0 && temp.y >= 0 && temp.x < 5 && temp.y < 5 && maps[temp.y][temp.x] == 1)
				{
					//queue�� �־�����
					temp.answer++;
					myqueue.push(temp);
				}
			}
		}

	}
}

int main()
{
	vector<vector<int>> maps = {
	{1, 0, 1, 1, 1},
	{1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1},
	{0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1}
	};
	// 	maps = { {1, 0, 1, 1, 1},
	// 			 {1, 0, 1, 0, 1},
	// 			 {1, 0, 1, 1, 1},
	// 			 {1, 1, 1, 0, 1},
	// 			 {0, 0, 0, 0, 1} };
	std::cout << solution(maps);
	return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
	vector dp(n, 0);
	dp[0] = 1;

	int temp = 1;
	for (int i = 1; i < n; i++)
	{
		temp = 0;
		for (int j = 0; j < i; j++) {  // j�� �������� ����, ������ ������
			temp += dp[j] * dp[i - 1 - j];
		}
		dp[i] = temp;
	}

	return temp % 10007;
}

int main()
{
	cout << solution(5) << endl;
}