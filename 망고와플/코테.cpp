#include <iostream>
using namespace std;

int len;
char* g_Queue = nullptr;
int in_Index = 0;
int out_Index = 0;

void ResetStack() ///스택 초기화 시키고~~~
{
    for (int i = 0; i < len; i++)
    {
        g_Queue[i] = ' ';
    }
}

void PrintStack() /// 스택 출력하는 함수~ in/out에 하나씩 넣어주면 좋아
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
    if (g_Queue[in_Index] != ' ')///안에 뭐가 차있으면 인뎃스 숫자도 증가 안하고 가득찼다고 말하게
    {
        cout << endl << "큐가 가득 찼습니다" << endl;
        return;
    }

    g_Queue[in_Index] = data; ///넣고 인덱스 하나 증가시켜
    in_Index++;
    if (in_Index + 1 > len) ///만약 증가시킨게 첨에 지정한 크기보다 크다? 그럼 첨으로 돌려보내
    {
        in_Index = 0;
    }
    PrintStack();
}

int PopDataToStack()
{
    if (g_Queue[out_Index] == ' ')                                                  ///in_Index랑 같은 원리
    {
        cout << endl << "큐가 비었습니다! 뺄 수가 없습니다." << endl;
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

    cout << endl << "큐에서 " << _result << "을 뺐습니다." << endl;
    PrintStack();

    return _result;
}

int main()
{
    cout << "큐의 사이즈를 입력해주세요." << endl;
    cin >> len;
    g_Queue = new char[len];

    ResetStack();

    while (true)
    {
        cout << "큐에 넣을 문자를 입력해주세요. -입력시 문자를 뽑습니다." << endl;
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

	//우선 시작지점음 0,0으로하고 도착지점을 4,4라고하자.
	Point startPoint = { 0, 0, 0 };
	myqueue.push(startPoint);
	maps[startPoint.x][startPoint.y] = 0;

	//위, 아래, 왼쪽, 오른쪽을 배열로 미리 나누어두자.
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

			//큐의 맨 앞부분을 꺼낸다
			startPoint = myqueue.front();
			myqueue.pop();

			//만약 도착지점이라면
			if (startPoint.x == 4 && startPoint.y == 4)
			{
				return ++startPoint.answer;
			}

			//현재 위치를 0으로 만들어준다.
			maps[startPoint.y][startPoint.x] = 0;

			//그리고 검사를 수행하자.
			for (int i = 0; i < 4; i++)
			{
				Point temp = startPoint;
				temp.x += move_x[i];
				temp.y += move_y[i];
				if (temp.x >= 0 && temp.y >= 0 && temp.x < 5 && temp.y < 5 && maps[temp.y][temp.x] == 1)
				{
					//queue에 넣어주자
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
		for (int j = 0; j < i; j++) {  // j를 기준으로 왼쪽, 오른쪽 나누기
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