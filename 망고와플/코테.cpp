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


///PUBG �ڵ��׽�Ʈ
#include <iostream>
using namespace std;

class list
{
public:
	list(int _val) : next(nullptr), val(_val) {};

	list* next;
	int val;
};

void printList(list* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

list* solution(list* start)
{

	list* prev = nullptr;
	list* current = start;
	list* next = start->next;

	while (current)
	{
		//���� list�� next�� current�� �ٲ��ش�.
		current->next = prev;

		prev = current;
		current = next;
		if (current)
		{
			next = current->next;
		}
	}
	return prev;
}

int main()
{
	list* temp = new list(1);

	list* temp1 = new list(2);
	temp->next = temp1;
	list* temp2 = new list(3);
	temp1->next = temp2;
	list* temp3 = new list(4);
	temp2->next = temp3;
	list* temp4 = new list(5);
	temp3->next = temp4;
	list* temp5 = new list(6);
	temp4->next = temp5;

	printList(temp);

	temp = solution(temp);
	printList(temp);

}
//////////////////////////////////////////////////////////////////////////

///���� �� ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // strcpy ����� ���� �ʿ�
char* MyStrCpy(char* a, const char* b)
{
	int sizeA = strlen(a);
	int sizeB = strlen(b);
	for (int i = 0; i < sizeB + 1; i++)
	{
		a[i] = b[i];
	}
	return a;
}

int main() {
	const char* source = "Hello, GPT!";
	char* destination = new char[strlen(source) + 1];

	MyStrCpy(destination, source);  // ����

	std::cout << "Copied string: " << destination << std::endl;
	return 0;
}

///��ģ ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char* MyStrCpy(char* a, const char* b)
{

	// whlie���� ���� �����Ѵ�.
	int index = 0;
	while (b[index])
	{
		a[index] = b[index];
		index++;
	}
	//������ null���ڿ����� �������ش�.
	a[index] = b[index];
	return a;
}

int main() {
	const char* source = "Hello, GPT!";
	char* destination = new char[strlen(source) + 1];

	MyStrCpy(destination, source);  // ����

	std::cout << "Copied string: " << destination << std::endl;
	return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	int Arr[100];
	for (int i = 0; i < 100; i++)
	{
		Arr[i] = i;
	}

	vector<int> vec(100, 0);
	for (int i = 0; i < 100; i++)
	{
		vec[i] = i;
	}

	array<int, 100> stdArr = { 0 };
	for (int i = 0; i < 100; i++)
	{
		stdArr[i] = i;
	}

	for (const auto e : Arr)
	{
		cout << e << endl;
	}

	for (const auto e : vec)
	{
		cout << e << endl;
	}
	for (const auto e : stdArr)
	{
		cout << e << endl;
	}


	return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
	int temp = 10;
	int temp2 = 50;
	int* a = &temp;

	const int* pa = &temp;	//������ �� �� ���� �Ұ�. �ּҰ��� ���� ����
	int const* pa1 = &temp;	//������ �� �� ���� �Ұ�. �ּҰ��� ���� ����
	int* const pb = &temp;	//������ �� �� ���� ����. �ּҰ� ������ �Ұ�

	const int& ra = temp;	 //�б� ���� ����
	int const& ra1 = temp;	 //�б� ���� ����
	int& const ra2 = temp;	 //����, ���� ��ü�� const�� �ɼ� ����, �ǹ̰� �Ұ���

	//*pa = 80;
	pa = &temp2;

	pa1 = &temp2;
	*pa1 = 23;

	*pb = 80;
	//pb = &temp2;

	ra = 1;
	ra1 = 1;
	ra2 = 1;
	cout << temp;


}
/// �ؽ� ���� ����//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////1
#include <iostream>
#include <vector>

int getSwitchSum(int n, const std::vector<std::pair<int, int>>& operations) {
	std::vector<int> switches(n + 1, 0); // 1-based indexing

	for (int i = 0; i < static_cast<int>(operations.size()); ++i) {
		int left = operations[i].first;
		int right = operations[i].second;

		for (int j = left; j <= right; ++j) {
			// ����: 0 -> 1, 1 -> 0
			if (switches[j] == 0)
				switches[j] = 1;
			else
				switches[j] = 0;
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (switches[i] == 1) {
			sum += i;
		}
	}

	return sum;
}

int main() {
	int n = 7;
	std::vector<std::pair<int, int>> operations;
	operations.push_back({ 1, 4 });
	operations.push_back({ 2, 6 });
	operations.push_back({ 1, 6 });

	int result = getSwitchSum(n, operations);
	std::cout << result << std::endl; // ���: 9

	return 0;
}
//////////////////////////////////////////////////////////////////////////2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // pow �Լ� ���

// ���Ŀ� �� �Լ� (value ���� ��������)
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second > b.second;
}

std::vector<int> sortByBinaryValue(const std::vector<std::vector<int>>& bitArrays)
{
	std::vector<std::pair<int, int>> result;

	for (int i = 0; i < bitArrays.size(); ++i)
	{
		std::vector<int> temp(32, 0); // �ִ� 32��Ʈ���� ó��

		for (int j = 0; j < (bitArrays[i].size()); ++j)
		{
			int bitIndex = bitArrays[i][j];
			temp[bitIndex] = 1;
		}

		int value = 0;
		for (int j = 0; j < temp.size(); ++j)
		{
			if (temp[j] == 1)
			{
				value += std::pow(2, j); // 2^j
			}
		}

		result.push_back(std::make_pair(i, value));
	}

	std::sort(result.begin(), result.end(), compare);

	std::vector<int> sortedIndices;
	for (int i = 0; i < static_cast<int>(result.size()); ++i) {
		sortedIndices.push_back(result[i].first);
	}

	return sortedIndices;
}

int main() {
	std::vector<std::vector<int>> bitArrays;
	bitArrays.push_back(std::vector<int>{0, 2});
	bitArrays.push_back(std::vector<int>{2, 3});
	bitArrays.push_back(std::vector<int>{2, 1});

	std::vector<int> result = sortByBinaryValue(bitArrays);

	for (int i = 0; i < static_cast<int>(result.size()); ++i) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
//////////////////////////////////////////////////////////////////////////3
#include <iostream>
#include <vector>
#include <algorithm>

int maxTeamScore(std::vector<int> score, int teamSize, int k) {
	int total = 0;

	for (int t = 0; t < teamSize; ++t) {
		int n = static_cast<int>(score.size());

		//int leftMax = -1, leftIndex = -1;
		int leftIndex = 0;
		int leftMax = score[0]; // ������ k <= score.size()
		//int rightMax = -1, rightIndex = -1;
		int rightIndex = n - 1;
		int rightMax = score[n - 1];
		// ���� k�� �� �ִ�
		for (int i = 0; i < std::min(k, n); ++i) {
			if (score[i] > leftMax) {
				leftMax = score[i];
				leftIndex = i;
			}
		}

		// ���� k�� �� �ִ�
		for (int i = n - std::min(k, n); i < n; ++i) {
			if (score[i] > rightMax) {
				rightMax = score[i];
				rightIndex = i;
			}
		}

		// ��: �� ū ���� ����, ������ ���� �ε��� �켱
		int chosenIndex;
		if (rightMax > leftMax) {
			chosenIndex = rightIndex;
		}
		else if (leftMax > rightMax) {
			chosenIndex = leftIndex;
		}
		else {
			chosenIndex = std::min(leftIndex, rightIndex);
		}

		total += score[chosenIndex];
		score.erase(score.begin() + chosenIndex); // ���õ� ��� ����
	}

	return total;
}

int main() {
	std::vector<int> score = { 10, 20, 10, 15, 5, 30, 20 };
	int teamSize = 2;
	int k = 3;

	int result = maxTeamScore(score, teamSize, k);
	std::cout << result << std::endl; // ���: 50

	return 0;
}
//////////////////////////////////////////////////////////////////////////4
#include <iostream>
#include <vector>
#include <algorithm>

int getMaxBreakTime(int totalTime, int k,
	const std::vector<int>& start,
	const std::vector<int>& end) {
	int n = static_cast<int>(start.size());

	// ��ǥ ���� ����Ʈ: (start, end)
	std::vector<std::pair<int, int>> talks;
	for (int i = 0; i < n; ++i) {
		talks.push_back({ start[i], end[i] });
	}

	// �ð� ������ ����
	std::sort(talks.begin(), talks.end());

	int maxBreak = 0;

	// ��ǥ�� �ϳ��� �������� �ʾ��� �� �� �ð� ���� ���
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int gap = talks[i].first - cur;
		if (gap > maxBreak) {
			maxBreak = gap;
		}
		cur = std::max(cur, talks[i].second);
	}
	maxBreak = std::max(maxBreak, totalTime - cur);

	// ��ǥ�� �ִ� k�� ������ �� �� ���̽��� Ž��
	for (int i = 0; i < n; ++i) {
		for (int removed = 1; removed <= k && i + removed <= n; ++removed) {
			int curTime = 0;
			int localBreak = 0;

			for (int j = 0; j < n; ++j) {
				if (j >= i && j < i + removed) continue; // ��ǥ ����

				int gap = talks[j].first - curTime;
				if (gap > localBreak) {
					localBreak = gap;
				}
				curTime = std::max(curTime, talks[j].second);
			}

			localBreak = std::max(localBreak, totalTime - curTime);
			maxBreak = std::max(maxBreak, localBreak);
		}
	}

	return maxBreak;
}

int main() {
	int totalTime = 15;
	int k = 2;
	std::vector<int> start = { 4, 6, 7, 10 };
	std::vector<int> end = { 5, 7, 8, 11 };

	int result = getMaxBreakTime(totalTime, k, start, end);
	std::cout << result << std::endl; // ���: 6

	return 0;
}
//////////////////////////////////////////////////////////////////////////5
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int getMinimumCost(int minWeight, const std::vector<int>& cost) {
	const int INF = INT_MAX / 2;
	int maxWeight = 1 << cost.size(); // �ִ� ���� ���� (2^n)

	// dp[w] = ���� w�� ����� ���� �ּ� ���
	std::vector<int> dp(maxWeight + 1, INF);
	dp[0] = 0;

	int n = static_cast<int>(cost.size());

	for (int i = 0; i < n; ++i) {
		int weight = 1 << i;
		for (int w = weight; w <= maxWeight; ++w) {
			dp[w] = std::min(dp[w], dp[w - weight] + cost[i]);
		}
	}

	// minWeight �̻� �߿��� ���� ���� ��� ã��
	int answer = INF;
	for (int w = minWeight; w <= maxWeight; ++w) {
		answer = std::min(answer, dp[w]);
	}

	return answer;
}

int main() {
	std::vector<int> cost = { 2, 5, 7, 11, 25 };
	int minWeight = 26;

	int result = getMinimumCost(minWeight, cost);
	std::cout << result << std::endl; // ��� ��: 37

	return 0;
}
//////////////////////////////////////////////////////////////////////////6
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

typedef std::pair<int, int> pii;

struct Edge {
	int u, v, w;
};

int heuristic(int current, int goal) {
	return 0; // A*���� h(n) = 0 �� ���ͽ�Ʈ��� ����
}

int AStar(int start, int end, const std::vector<std::vector<pii>>& graph, std::vector<int>& dist) {
	int n = graph.size();
	dist.assign(n, INT_MAX);
	dist[start] = 0;

	// A* �켱���� ť: f(n) = g(n) + h(n)
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
	pq.push({ dist[start] + heuristic(start, end), start });

	while (!pq.empty()) {
		int f = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < static_cast<int>(graph[u].size()); ++i) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v] + heuristic(v, end), v });
			}
		}
	}

	return dist[end];
}

int main() {
	int n = 5; // ��� ��
	int m = 7; // ���� ��

	std::vector<Edge> edges = {
		{1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1},
		{1, 5, 3}, {1, 3, 2}, {5, 3, 1}
	};

	std::vector<std::vector<pii>> graph(n + 1);
	for (int i = 0; i < m; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w }); // �����
	}

	std::vector<int> distFromStart, distToEnd;

	// A*: 1������ �� ������
	AStar(1, n, graph, distFromStart);

	// A*: N������ �� ������
	AStar(n, 1, graph, distToEnd);

	int shortest = distFromStart[n];

	// �� ������ �ִ� ��ο� ���ԵǴ��� Ȯ��
	std::vector<std::string> result;

	for (int i = 0; i < m; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;

		bool isOnShortest =
			(distFromStart[u] + w + distToEnd[v] == shortest) ||
			(distFromStart[v] + w + distToEnd[u] == shortest);

		result.push_back(isOnShortest ? "YES" : "NO");
	}

	for (int i = 0; i < static_cast<int>(result.size()); ++i) {
		std::cout << result[i] << std::endl;
	}

	return 0;
}
//////////////////////////////////////////////////////////////////////////////5
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


/*
 * Complete the 'getMinimumCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER minWeight
 */

 //���԰� 2^n�� �������� �ְ� cost[i]�� �� �������� ����
 //���� �������� ������ ��� �ִ�(��������)
 //�� �������� ��� �� ���԰� minwieght�� �ǰ� �ؾ��Ѵ�.
 //�̶� ���� �ִ��� ���� ����Ѵ�.
long getMinimumCost(vector<int> cost, int minWeight)
{
	int size = cost.size();

	int tempWeight = minWeight * 4;

	//���Ը� ����� ���� �ּ� ���
	vector<int> dp(tempWeight + 1, 100000000);    //ū ���� �ʱ�ȭ

	//�ƹ��͵� �Ȼ�����
	dp[0] = 0;

	for (int i = 0; i < size; i++)
	{
		//���� = 2�� ����
		int weight = pow(2, i);

		for (int j = weight; j <= tempWeight; j++)
		{
			if (dp[j - weight] + cost[i] < dp[j])
			{
				dp[j] = dp[j - weight] + cost[i];
			}
		}
	}

	//minweight �̻��� �͵� �߿� ���� �Ѱ� ã��..
	int result = 100000000;
	for (int i = minWeight; i <= tempWeight; i++)
	{
		if (dp[i] < result)
		{
			result = dp[i];
		}
	}
	return result;

}
int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string cost_count_temp;
	getline(cin, cost_count_temp);

	int cost_count = stoi(ltrim(rtrim(cost_count_temp)));

	vector<int> cost(cost_count);

	for (int i = 0; i < cost_count; i++) {
		string cost_item_temp;
		getline(cin, cost_item_temp);

		int cost_item = stoi(ltrim(rtrim(cost_item_temp)));

		cost[i] = cost_item;
	}

	string minWeight_temp;
	getline(cin, minWeight_temp);

	int minWeight = stoi(ltrim(rtrim(minWeight_temp)));

	long result = getMinimumCost(cost, minWeight);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

//////////////////////////////////////////////////////////////////////////�ֽİ���
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	//return���� �� ����
	vector<int> answer(prices.size(), -1);
	//1. �켱 �ݺ����� ���鼭 ���ÿ� �ִ´�.
	//2. ������ ������ ���纸�� ���� ��� pop�� �ϰ� �ش� ���ڰ� ����� ����Ѵ�.
	//3. �� �� ��ŭ �ݺ����� ������ return�迭�� ä���.

	//int ����
	stack<int> tempStack;
	//popCount
	int popCount = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		//������ ����ִٸ�..? �ٷ� �־��ش�.
		if (tempStack.empty())
		{
			tempStack.push(prices[i]);
			continue;
		}
		//������ �������� ���� ���� ������ ���ٸ�? ���ÿ� push
		else if (tempStack.top() <= prices[i])
		{
			tempStack.push(prices[i]);
		}
		//������ �������� ���� ���� ������ ���ٸ�? ���ÿ��� pop�� ���ְ� int popCount�� �ϳ� ������Ų��.
		else
		{
			for (int j = i; !tempStack.empty() && tempStack.top() > prices[i]; j--)
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
	int index = prices.size() - 1;
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
////////////////////////////////////////////////////////////////////////// ũ���� �����̱� ����
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	//�ϴ� �ش� ������ ������ ���� �˰����� ¥��.
	//���� stack�� �ְ� ������ ��� result���� ������Ű��

	int weight = board[0].size();   //����
	int height = board.size();      //����

	int targetCharacter = 0;         //���� ���� ���� ����
	stack<int> box;                 //���� ������ ���� �ڽ�

	//������ ���� �˰����� ���� for���� ���ؼ� ¥����.
	//ũ������ ������, moves, ����
	for (int i = 0; i < moves.size(); i++)
	{
		//����, �� ����������
		for (int j = 0; j < height; j++)
		{
			//���� ũ���ο� ������ ���� ���
			if (targetCharacter == 0)
			{
				targetCharacter = board[j][moves[i] - 1];
				//������ ���� �ڸ��� 0���� �ʱ�ȭ ���Ѿ���
				board[j][moves[i] - 1] = 0;

			}
		}

		//���� ��� ������ ������ �Ŀ��� ������ ���� ���
		if (targetCharacter == 0)
		{
			continue;
		}

		//�ڽ��� ����ų� 
		if (box.empty())
		{
			box.push(targetCharacter);
			targetCharacter = 0;
		}

		//�������� ������ ���� ��� �ڽ��� �ִ´�.
		else if (box.top() != targetCharacter)
		{
			box.push(targetCharacter);
			targetCharacter = 0;
		}

		//�������� �������
		else if (box.top() == targetCharacter)
		{
			box.pop();
			targetCharacter = 0;
			answer += 2;
		}

	}

	return answer;
}

//////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	//Z��ɾ ���� ������ ����� index�� �����Ѵ�.
	stack<int> deleteList;

	//ũ�⸸ŭ O�� �־��ش�.
	answer.append(n, 'O');

	//ó���� ���õ� ���� ��ġ
	int target = k;

	for (int i = 0; i < cmd.size(); i++)
	{
		string targetCmd = cmd[i];
		if (targetCmd[0] == 'U')
		{
			int x = stoi(targetCmd.substr(2));
			while (x > 0 && target > 0)
			{
				target--;
				if (answer[target] == 'O')
					x--;
			}
		}
		else if (targetCmd[0] == 'D')
		{
			int x = stoi(targetCmd.substr(2));
			while (x > 0 && target < n - 1)
			{
				target++;
				if (answer[target] == 'O')
					x--;
			}
		}
		else if (targetCmd[0] == 'C')
		{
			answer[target] = 'X';
			deleteList.push(target);

			//����ִ� �������� ã�ƾ��Ѵ�.
			int nextTarget = target + 1;
			while (nextTarget < n && answer[nextTarget] == 'X')
			{
				nextTarget++;
			}

			if (nextTarget < n)
			{
				target = nextTarget;
			}
			else
			{
				// ������ �������� �̵�
				int prevTarget = target - 1;
				while (prevTarget >= 0 && answer[prevTarget] == 'X')
				{
					prevTarget--;
				}
				target = prevTarget;
			}

		}
		else if (targetCmd[0] == 'Z')
		{
			int temp = deleteList.top();
			deleteList.pop();
			answer[temp] = 'O';
		}

	}


	return answer;
}

int main()
{
	int a = 8;
	int b = 2;
	vector<string> c = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	string temp = solution(a, b, c);
}
//////////////////////////////////////////////////////////////////////////
//�似Ǫ�� ����
/*
N���� ����� �� ���·� ���ִ�. �� ����� 1���� N���� ��ȣǥ�� �����ִ�. �׸��� ������ ���� K�� �־����� �� ������ ���� ����� ���ش�.
- 1�� ��ȣǥ�� ���� ��� ���� �ð� �������� K��° ����� ���ش�.
- ���� ��� ���� ����� �������� �ϰ� �ٽ� K��° ����� ���ش�.
N�� K�� �־����� �������� ����ִ� ����� ��ȣ�� ��ȯ�ϴ� Solution()�Լ��� �����Ͻÿ�.
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
//////////////////////////////��ɰ���////////////////////////////////////////////
//https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	queue<int*> q;

	for (int i = 0; i < progresses.size(); i++)
	{
		q.push(&progresses[i]);
	}

	while (!q.empty())
	{
		for (int i = 0; i < progresses.size(); i++)
		{
			progresses[i] += speeds[i];
		}
		int result = 0;

		while (!q.empty() && *(q.front()) >= 100)
		{
			result++;
			q.pop();
		}
		if (result > 0)
		{
			answer.push_back(result);
		}
	}

	return answer;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////