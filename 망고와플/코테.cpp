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


///PUBG 코딩테스트
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
		//다음 list의 next를 current로 바꿔준다.
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

///내가 쓴 답
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // strcpy 사용을 위해 필요
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

	MyStrCpy(destination, source);  // 복사

	std::cout << "Copied string: " << destination << std::endl;
	return 0;
}

///고친 답
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char* MyStrCpy(char* a, const char* b)
{

	// whlie문을 돌며 복사한다.
	int index = 0;
	while (b[index])
	{
		a[index] = b[index];
		index++;
	}
	//마지막 null문자열까지 복사해준다.
	a[index] = b[index];
	return a;
}

int main() {
	const char* source = "Hello, GPT!";
	char* destination = new char[strlen(source) + 1];

	MyStrCpy(destination, source);  // 복사

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

	const int* pa = &temp;	//역참조 후 값 수정 불가. 주소값은 변경 가능
	int const* pa1 = &temp;	//역참조 후 값 수정 불가. 주소값은 변경 가능
	int* const pb = &temp;	//역참조 후 값 수정 가능. 주소값 변경은 불가

	const int& ra = temp;	 //읽기 전용 참조
	int const& ra1 = temp;	 //읽기 전용 참조
	int& const ra2 = temp;	 //오류, 참조 다체는 const가 될수 없음, 의미가 불가능

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
/// 넥슨 코테 연습//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////1
#include <iostream>
#include <vector>

int getSwitchSum(int n, const std::vector<std::pair<int, int>>& operations) {
	std::vector<int> switches(n + 1, 0); // 1-based indexing

	for (int i = 0; i < static_cast<int>(operations.size()); ++i) {
		int left = operations[i].first;
		int right = operations[i].second;

		for (int j = left; j <= right; ++j) {
			// 반전: 0 -> 1, 1 -> 0
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
	std::cout << result << std::endl; // 출력: 9

	return 0;
}
//////////////////////////////////////////////////////////////////////////2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // pow 함수 사용

// 정렬용 비교 함수 (value 기준 내림차순)
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second > b.second;
}

std::vector<int> sortByBinaryValue(const std::vector<std::vector<int>>& bitArrays)
{
	std::vector<std::pair<int, int>> result;

	for (int i = 0; i < bitArrays.size(); ++i)
	{
		std::vector<int> temp(32, 0); // 최대 32비트까지 처리

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
		int leftMax = score[0]; // 어차피 k <= score.size()
		//int rightMax = -1, rightIndex = -1;
		int rightIndex = n - 1;
		int rightMax = score[n - 1];
		// 앞쪽 k개 중 최대
		for (int i = 0; i < std::min(k, n); ++i) {
			if (score[i] > leftMax) {
				leftMax = score[i];
				leftIndex = i;
			}
		}

		// 뒤쪽 k개 중 최대
		for (int i = n - std::min(k, n); i < n; ++i) {
			if (score[i] > rightMax) {
				rightMax = score[i];
				rightIndex = i;
			}
		}

		// 비교: 더 큰 점수 선택, 같으면 앞쪽 인덱스 우선
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
		score.erase(score.begin() + chosenIndex); // 선택된 사람 제거
	}

	return total;
}

int main() {
	std::vector<int> score = { 10, 20, 10, 15, 5, 30, 20 };
	int teamSize = 2;
	int k = 3;

	int result = maxTeamScore(score, teamSize, k);
	std::cout << result << std::endl; // 출력: 50

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

	// 발표 구간 리스트: (start, end)
	std::vector<std::pair<int, int>> talks;
	for (int i = 0; i < n; ++i) {
		talks.push_back({ start[i], end[i] });
	}

	// 시간 순으로 정렬
	std::sort(talks.begin(), talks.end());

	int maxBreak = 0;

	// 발표를 하나도 제거하지 않았을 때 빈 시간 구간 계산
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int gap = talks[i].first - cur;
		if (gap > maxBreak) {
			maxBreak = gap;
		}
		cur = std::max(cur, talks[i].second);
	}
	maxBreak = std::max(maxBreak, totalTime - cur);

	// 발표를 최대 k개 제거할 때 각 케이스를 탐색
	for (int i = 0; i < n; ++i) {
		for (int removed = 1; removed <= k && i + removed <= n; ++removed) {
			int curTime = 0;
			int localBreak = 0;

			for (int j = 0; j < n; ++j) {
				if (j >= i && j < i + removed) continue; // 발표 제거

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
	std::cout << result << std::endl; // 출력: 6

	return 0;
}
//////////////////////////////////////////////////////////////////////////5
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int getMinimumCost(int minWeight, const std::vector<int>& cost) {
	const int INF = INT_MAX / 2;
	int maxWeight = 1 << cost.size(); // 최대 가능 무게 (2^n)

	// dp[w] = 무게 w를 만들기 위한 최소 비용
	std::vector<int> dp(maxWeight + 1, INF);
	dp[0] = 0;

	int n = static_cast<int>(cost.size());

	for (int i = 0; i < n; ++i) {
		int weight = 1 << i;
		for (int w = weight; w <= maxWeight; ++w) {
			dp[w] = std::min(dp[w], dp[w - weight] + cost[i]);
		}
	}

	// minWeight 이상 중에서 가장 작은 비용 찾기
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
	std::cout << result << std::endl; // 출력 예: 37

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
	return 0; // A*에서 h(n) = 0 → 다익스트라와 동일
}

int AStar(int start, int end, const std::vector<std::vector<pii>>& graph, std::vector<int>& dist) {
	int n = graph.size();
	dist.assign(n, INT_MAX);
	dist[start] = 0;

	// A* 우선순위 큐: f(n) = g(n) + h(n)
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
	int n = 5; // 노드 수
	int m = 7; // 간선 수

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
		graph[v].push_back({ u, w }); // 양방향
	}

	std::vector<int> distFromStart, distToEnd;

	// A*: 1번에서 각 노드까지
	AStar(1, n, graph, distFromStart);

	// A*: N번에서 각 노드까지
	AStar(n, 1, graph, distToEnd);

	int shortest = distFromStart[n];

	// 각 간선이 최단 경로에 포함되는지 확인
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

 //무게가 2^n인 아이템이 있고 cost[i]는 그 아이템의 가격
 //같은 아이템을 여러개 살수 있다(상점같이)
 //그 아이템을 골라 총 무게가 minwieght가 되게 해야한다.
 //이때 돈을 최대한 적게 써야한다.
long getMinimumCost(vector<int> cost, int minWeight)
{
	int size = cost.size();

	int tempWeight = minWeight * 4;

	//무게를 만들기 위한 최소 비용
	vector<int> dp(tempWeight + 1, 100000000);    //큰 수로 초기화

	//아무것도 안샀을때
	dp[0] = 0;

	for (int i = 0; i < size; i++)
	{
		//무게 = 2의 제곱
		int weight = pow(2, i);

		for (int j = weight; j <= tempWeight; j++)
		{
			if (dp[j - weight] + cost[i] < dp[j])
			{
				dp[j] = dp[j - weight] + cost[i];
			}
		}
	}

	//minweight 이상인 것들 중에 제일 싼거 찾아..
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

//////////////////////////////////////////////////////////////////////////주식가격
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
////////////////////////////////////////////////////////////////////////// 크레인 인형뽑기 게임
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	//일단 해당 가로의 인형을 고르는 알고리즘을 짜자.
	//이후 stack에 넣고 터졌을 경우 result값을 증가시키자

	int weight = board[0].size();   //가로
	int height = board.size();      //세로

	int targetCharacter = 0;         //지금 현재 잡은 인형
	stack<int> box;                 //잡은 인형을 넣을 박스

	//인형을 고르는 알고리즘을 이중 for문을 통해서 짜보자.
	//크레인의 움직임, moves, 가로
	for (int i = 0; i < moves.size(); i++)
	{
		//세로, 맨 위에서부터
		for (int j = 0; j < height; j++)
		{
			//지금 크레인에 잡힌게 없을 경우
			if (targetCharacter == 0)
			{
				targetCharacter = board[j][moves[i] - 1];
				//인형을 뽑은 자리를 0으로 초기화 시켜야함
				board[j][moves[i] - 1] = 0;

			}
		}

		//인형 잡는 로직을 실행한 후에서 잡힌게 없을 경우
		if (targetCharacter == 0)
		{
			continue;
		}

		//박스가 비었거나 
		if (box.empty())
		{
			box.push(targetCharacter);
			targetCharacter = 0;
		}

		//인형끼리 터지지 않을 경우 박스에 넣는다.
		else if (box.top() != targetCharacter)
		{
			box.push(targetCharacter);
			targetCharacter = 0;
		}

		//인형끼리 터질경우
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

	//Z명령어를 위해 지워진 행들의 index를 저장한다.
	stack<int> deleteList;

	//크기만큼 O를 넣어준다.
	answer.append(n, 'O');

	//처음에 선택된 행의 위치
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

			//살아있는 다음행을 찾아야한다.
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
				// 없으면 위쪽으로 이동
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
//////////////////////////////기능개발////////////////////////////////////////////
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
#include <iostream>
#include <vector>
using namespace std;

//1번문제 이건 투포인터를 써서 양끝에서 중앙을 향해 배열을 순회하는 방식으로 설계하였다.
//하지만 배열 자체를 바꿀 필요는 없으므로 그냥 카운팅 풀이를 하는게 나아보이기도 한다.
int Solution1(vector<int>& arr)
{
	int E = 0;
	for (int x : arr)
	{
		if ((x & 1) == 0)
		{
			++E;		//짝수 개수 증가.
		}
	}

	int SwapNum = 0;
	for (int i = 0; i < E; ++i)
	{
		if (arr[i] & 1)
		{
			++SwapNum;
		}
	}

	return SwapNum;
}


void main()
{
	vector<int> a = { 8,3,2,1,4,7 };

	cout << Solution1(a) << endl;
}
//////////////////////////////////////////////////////////////////////////
///4번문제
#include <iostream>
#include <vector>
using namespace std;

int minDeletions(vector<int>& arr)
{
	int n = (int)arr.size();
	if (n <= 2) return 0; // 원소 2개 이하는 이미 '직전' 상태

	// 비내림차순 LIS
	vector<int> tails;
	tails.reserve(n);
	for (int x : arr) {
		auto it = upper_bound(tails.begin(), tails.end(), x);
		if (it == tails.end()) tails.push_back(x);
		else *it = x;
	}
	int L = (int)tails.size();
	int keep = min(n, L + 1);
	return n - keep;
}

int main()
{
	vector<int> arr = { 3, 4, 2, 5, 1, 1, 2, 3, 4, 9, 9, 1, 1, 1, 10, 11, 12, 23, 3, 4, 6, 7, 2, 6 };
	cout << minDeletions(arr) << endl; //


	vector<int> arr1 = { 3, 4, 2, 5, 1 };
	cout << minDeletions(arr1) << endl; // 기대: 1 (1 또는 2 삭제)

	vector<int> arr2 = { 1, 2, 3, 4, 5 };
	cout << minDeletions(arr2) << endl; // 기대: 0 (이미 정렬됨)

	vector<int> arr3 = { 10, 1, 2, 3, 4 };
	cout << minDeletions(arr3) << endl; // 기대: 0 (10 삭제)

	vector<int> arr4 = { 3, 2, 1 };
	cout << minDeletions(arr4) << endl; // 기대: 1 (원소 하나 삭제로 해결)

	return 0;

}
//////////////////////////////////////////////////////////////////////////
///5번 문제 ------------------------------------------------------------------
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// programmer 문자 요구량 초기화
unordered_map<char, int> getNeed() {
	return {
		{'p', 1},
		{'r', 3},
		{'o', 1},
		{'g', 1},
		{'a', 1},
		{'m', 2},
		{'e', 1}
	};
}

// 왼쪽에서부터 돌면서 programmer를 구성할 수 있는 마지막 인덱스 반환
int findIndexLeft(const string& s) {
	auto need = getNeed();
	int remain = 10; // 총 필요한 문자 개수
	for (int i = 0; i < (int)s.size(); i++) {
		char c = tolower(s[i]); // 대소문자 구분 안하려면 tolower
		if (need.count(c) && need[c] > 0) {
			need[c]--;
			remain--;
			if (remain == 0) return i; // 모든 문자를 다 채운 순간
		}
	}
	return -1; // 못 만든 경우
}

// 오른쪽에서부터 돌면서 programmer를 구성할 수 있는 첫 인덱스 반환
int findIndexRight(const string& s) {
	auto need = getNeed();
	int remain = 10;
	for (int i = (int)s.size() - 1; i >= 0; i--) {
		char c = tolower(s[i]);
		if (need.count(c) && need[c] > 0) {
			need[c]--;
			remain--;
			if (remain == 0) return i; // 모든 문자를 다 채운 순간
		}
	}
	return -1;
}

// 최종 함수
int programmerStrings(const string& s) {
	int leftEnd = findIndexLeft(s);
	int rightStart = findIndexRight(s);

	if (leftEnd == -1 || rightStart == -1) return 0; // 못 만든 경우
	if (rightStart <= leftEnd) return 0;             // 겹치면 0
	return rightStart - leftEnd - 1;                 // 두 문자열 사이 인덱스 차이
}

int main() {
	string s = "programmerxxasdfxprozmedsfasdfrqgram";

	cout << "Between count: " << programmerStrings(s) << endl; // 3

	return 0;
}
//////////////////////////////////////////////////////////////////////////
///6번 문제
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findMinWeight(vector<int>& weight, int d)
{
	priority_queue<int> pq;

	//모든 초콜릿 삽입
	for (auto e : weight)
	{
		pq.push(e);
	}

	//d일 동안 반복
	for (int i = 0; i < d; i++)
	{
		int top = pq.top();
		pq.pop();
		int remain = top - top / 2;	//남는 무게
		pq.push(remain);
	}

	//남은 무게 합 구하기
	int sum = 0;

	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	return sum;
}

int main()
{
	vector<int> weight = { 30, 20, 25 };
	int d = 4;
	cout << findMinWeight(weight, d);

}
//////////////////////////////////////////////////////////////////////////
///3번문제
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int sumVips(vector<int>& score, int guilder_count, int k)
{
	//점수배열 데큐에 복사.
	deque<int> dq(score.begin(), score.end());

	long long total = 0;	//길드원들의 점수 합.

	//guilder_count만큼 반복
	for (int t = 0; t < guilder_count; t++)
	{

		//왼쪽부터 k까지의 최대값, 위치 찾기
		int left_max = -1;
		int left_idx = -1;

		for (int i = 0; i < k && i < dq.size(); i++)
		{
			if (dq[i] > left_max)
			{
				left_max = dq[i];
				left_idx = i;
			}
		}

		//오른쪽부터 k까지의 최대값, 위치 찾기
		int right_max = -1;
		int right_idx = -1;

		for (int i = 0; i < k && i < dq.size(); i++)
		{
			int index = dq.size() - k + i;
			if (index >= 0 && dq[index] > right_max)
			{
				right_max = dq[index];
				right_idx = index;
			}
		}

		int TargetIndex;
		if (left_max >= right_max)
		{
			TargetIndex = left_idx;
		}
		else
		{
			TargetIndex = right_idx;
		}

		total += dq[TargetIndex];
		dq.erase(dq.begin() + TargetIndex);
	}

	return total;
}


int main() {
	vector<int> score = { 8, 21, 8, 15, 5, 30, 21 };
	int guilder_count = 2;
	int k = 3;
	cout << sumVips(score, guilder_count, k) << endl;  // 결과: 51
	return 0;
}
//////////////////////////////////////////////////////////////////////////
///2번 문제
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
int s_nodes = 노드의 수
int s_edges = 선의 수
vector<int>& s_from = 시작 노드
vector<int>& s_to = 끝 노드
*/
vector<int> nodeDistance(int s_nodes, int s_edges, vector<int>& s_from, vector<int>& s_to)
{
	vector<vector<int>> graph(s_nodes);	//노드와 인접한 전점 목록
	vector<int> degree(s_nodes, 0);		//각 정점의 현재 차수

	for (int i = 0; i < s_edges; i++)
	{
		int u = s_from[i];
		int v = s_to[i];

		graph[u].push_back(v);
		graph[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}

	queue<int> q;
	vector<bool> isCycle(s_nodes, true);

	//초기 리프넣기
	for (int i = 0; i < s_nodes; i++)
	{
		if (degree[i] == 1)
		{
			q.push(i);
			isCycle[i] = false;	//사이클에 속하지 않는다.
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		//cur과 인접한 노드들의 차수를 1 줄인다.
		for (int next : graph[cur])
		{
			if (isCycle[next])	//이미 제거된 노드는 건너뜀.
			{
				degree[next]--;

				if (degree[next] == 1)
				{
					isCycle[next] = false;
					q.push(next);
				}
			}
		}
	}
	//여기까지오면 isCycle이 true인 노드만 사이클에 남아있다.

	vector<int> dist(s_nodes, -1);
	queue<int> bfsQ;

	for (int i = 0; i < s_nodes; i++)
	{
		if (isCycle[i])
		{
			dist[i] = 0;
			bfsQ.push(i);
		}
	}

	while (!bfsQ.empty())
	{
		int cur = bfsQ.front();
		bfsQ.pop();

		for (int next : graph[cur])
		{
			if (dist[next] == -1)
			{
				dist[next] = dist[cur] + 1;
				bfsQ.push(next);
			}
		}
	}
	return dist;

}

// -----------------------------
int main() {
	//int s_nodes = 6;
	//int s_edges = 6;

	//vector<int> s_from = { 0, 1, 0, 2, 0, 1 };
	//vector<int> s_to = { 1, 2, 2, 4, 3, 5 };
	// 기대 출력: 0 0 0 1 1 1

	int s_nodes = 7;
	int s_edges = 7;
	vector<int> s_from = { 0, 1, 2, 0, 2, 3, 4 };
	vector<int> s_to = { 1, 2, 0, 3, 4, 5, 6 };
	// 기대 출력: 0 0 0 1 2 3 4



	vector<int> ans = nodeDistance(s_nodes, s_edges, s_from, s_to);

	for (int d : ans) cout << d << ' ';
	cout << '\n';
	return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

int finalStateSum(vector<pair<int, int>>& operations)
{
	if (operations.empty()) return 0;

	//일단 최댓값 먼저 찾기
	int n = 0;
	for (auto& op : operations)
	{
		n = max(n, op.second);
	}

	vector<int> temp(n + 2, 0);

	for (auto& op : operations)
	{
		int L = op.first;
		int R = op.second;

		temp[L] ^= 1;		//시작점
		temp[R + 1] ^= 1;	//끝 위치 다음
	}

	int answer = 0;
	int current = 0;

	for (int i = 1; i <= n; i++)
	{
		current ^= temp[i];
		if (current == 1)
		{
			answer += i;	//On인 스위치 인덱스 더하기
		}
	}
	return answer;
}

void main()
{
	vector<pair<int, int>> ops = { {1,4}, {2,6}, {1,6} };
	cout << finalStateSum(ops) << endl;//9

	vector<pair<int, int>> ops2 = { {2,4}, {2,4} };
	cout << finalStateSum(ops2) << endl;//0

	vector<pair<int, int>> ops3 = { {1,3}, {2,5} };
	cout << finalStateSum(ops3) << endl;//10
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

int finalStateSum(vector<pair<int, int>>& operations)
{
	if (operations.empty()) return 0;

	//일단 최댓값 먼저 찾기
	int n = 0;
	for (auto& op : operations)
	{
		n = max(n, op.second);
	}

	vector<int> temp(n + 2, 0);

	for (auto& op : operations)
	{
		int L = op.first;
		int R = op.second;

		temp[L] ^= 1;		//시작점
		temp[R + 1] ^= 1;	//끝 위치 다음
	}

	int answer = 0;
	int current = 0;

	for (int i = 1; i <= n; i++)
	{
		current ^= temp[i];
		if (current == 1)
		{
			answer += i;	//On인 스위치 인덱스 더하기
		}
	}
	return answer;
}

#include<queue>
long long teamFormation(const vector<int>& score, int teamSize, int k)
{
	int n = score.size();

	if (n == 0 || teamSize == 0) return 0;

	//(score, index)
	using Node = pair<int, int>;

	auto cmp = [](const Node& a, const Node& b)
		{
			if (a.first != b.first) return a.first < b.first;	//점수 큰게 먼저

			return a.second > b.second;							//인덱스 작인게 먼거
		};

	priority_queue<Node, vector<Node>, decltype(cmp)> L_queue(cmp);
	priority_queue<Node, vector<Node>, decltype(cmp)> R_queue(cmp);

	vector<char> used(n, 0);
	int l = 0;
	int r = n - 1;

	for (int t = 0; t < k && l <= r; t++)
	{
		L_queue.push({ score[l], l++ });
	}

	for (int t = 0; t < k && r >= l; t++)
	{
		R_queue.push({ score[r], r-- });
	}

	long long answer = 0;

	auto cleanTop = [&](auto& PQ)
		{
			while (!PQ.empty() && used[PQ.top().second])
			{
				PQ.pop();
			}
		};

	for (int pick = 0; pick < teamSize; pick++)
	{
		cleanTop(L_queue);
		cleanTop(R_queue);

		if (L_queue.empty() && R_queue.empty())
		{
			break;
		}

		bool takeLeft = false;
		if (R_queue.empty())
		{
			takeLeft = true;
		}
		else if (L_queue.empty())
		{
			takeLeft = false;
		}
		else
		{
			auto a = L_queue.top(), b = R_queue.top();
			if (a.first > b.first)
			{
				takeLeft = true;
			}
			else if (a.first < b.first)
			{
				takeLeft = false;
			}
			else
			{
				takeLeft = (a.second < b.second);
			}
		}

		if (takeLeft)
		{
			auto [tempscore, index] = L_queue.top();
			L_queue.pop();

			if (used[index])
			{
				--pick;
				continue;
			}

			used[index] = 1;
			answer += tempscore;

			if (l <= r)
			{
				L_queue.push({ score[l], l });
				++l;
			}
		}
		else
		{
			auto [tempscore, index] = R_queue.top();
			R_queue.pop();

			if (used[index])
			{
				--pick;
				continue;
			}

			used[index] = 1;
			answer += tempscore;

			if (r >= l)
			{
				R_queue.push({ score[r], r });
				--r;
			}
		}
	}
	return answer;
}


const long long INF = (long long)4e18;

// 다익스트라: start → 모든 노드까지 최단거리
vector<long long> dijkstra(int nodeCount, int startNode, const vector<vector<pair<int, int>>>& graph) {
	vector<long long> dist(nodeCount + 1, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dist[startNode] = 0;
	pq.push({ 0, startNode });

	while (!pq.empty()) {
		auto [curDist, curNode] = pq.top(); pq.pop();
		if (curDist != dist[curNode]) continue;

		for (auto [nextNode, edgeWeight] : graph[curNode]) {
			long long newDist = curDist + edgeWeight;
			if (newDist < dist[nextNode]) {
				dist[nextNode] = newDist;
				pq.push({ newDist, nextNode });
			}
		}
	}
	return dist;
}

vector<string> checkRoutes(
	int nodeCount,
	const vector<int>& edgeFrom,
	const vector<int>& edgeTo,
	const vector<int>& edgeWeight
) {
	int edgeCount = (int)edgeFrom.size();

	// 인접리스트 구성
	vector<vector<pair<int, int>>> graph(nodeCount + 1);
	for (int i = 0; i < edgeCount; ++i) {
		int u = edgeFrom[i], v = edgeTo[i], w = edgeWeight[i];
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	// 다익스트라 실행 (시작노드=1, 목표노드=nodeCount)
	vector<long long> distFromStart = dijkstra(nodeCount, 1, graph);
	vector<long long> distFromEnd = dijkstra(nodeCount, nodeCount, graph);
	long long shortestDistance = distFromStart[nodeCount];

	vector<string> result(edgeCount, "no");
	if (shortestDistance == INF) return result; // 연결 불가 → 전부 "no"

	for (int i = 0; i < edgeCount; ++i) {
		int u = edgeFrom[i], v = edgeTo[i], w = edgeWeight[i];
		bool onShortestPath = false;

		if (distFromStart[u] != INF && distFromEnd[v] != INF &&
			distFromStart[u] + w + distFromEnd[v] == shortestDistance) {
			onShortestPath = true;
		}
		if (distFromStart[v] != INF && distFromEnd[u] != INF &&
			distFromStart[v] + w + distFromEnd[u] == shortestDistance) {
			onShortestPath = true;
		}

		result[i] = onShortestPath ? "yes" : "no";
	}
	return result;
}
static void printVec(const vector<string>& v) {
	for (auto& s : v) cout << s << "\n";
}

void main()
{
	vector<pair<int, int>> ops = { {1,4}, {2,6}, {1,6} };
	cout << finalStateSum(ops) << endl;//9

	vector<pair<int, int>> ops2 = { {2,4}, {2,4} };
	cout << finalStateSum(ops2) << endl;//0

	vector<pair<int, int>> ops3 = { {1,3}, {2,5} };
	cout << finalStateSum(ops3) << endl;//10


	// 예시 1 (문제 예시)
	vector<int> s1 = { 10,20,10,15,5,30,20 };
	cout << teamFormation(s1, 2, 3) << "\n"; // 50

	// 예시 2
	vector<int> s2 = { 5,5,5 };
	cout << teamFormation(s2, 2, 2) << "\n"; // 10 (동점이면 인덱스 작은 쪽부터)

	// 예시 3 (남은 인원 < k 인 상황)
	vector<int> s3 = { 7,1,9 };
	cout << teamFormation(s3, 3, 5) << "\n"; // 17 (9+7+1)


	// 1) 직통이 최단 (기본)
	{
		int n = 5;
		vector<int> f = { 1,2,3,4,3,1 };
		vector<int> t = { 2,3,4,5,5,5 };
		vector<int> w = { 1,2,1,1,1,3 };
		// 최단거리: 1-5(3). 결과: ..... yes 만 마지막
		auto r = checkRoutes(n, f, t, w);
		printVec(r);
		// 기대:
		// no
		// no
		// no
		// no
		// no
		// yes
	}

	// 2) 1에서 N 도달 불가
	{
		int n = 4;
		vector<int> f = { 1,3 };
		vector<int> t = { 2,4 };
		vector<int> w = { 1,1 };
		auto r = checkRoutes(n, f, t, w);
		printVec(r);
		// 기대:
		// no
		// no
	}

	// 3) 최단경로 2개 (모든 간선이 어떤 최단경로에는 포함)
	{
		int n = 4;
		vector<int> f = { 1,2,1,3 };
		vector<int> t = { 2,4,3,4 };
		vector<int> w = { 1,1,1,1 };
		auto r = checkRoutes(n, f, t, w);
		printVec(r);
		// 기대:
		// yes
		// yes
		// yes
		// yes
	}


}
//////////////////////////////////////////////////////////////////////////
/*
깊이 우선탐색으로 모든 그래프의 노드를 순회하는 함수 solution을 만드시오.
시작 노드는 문자형 START로 주어진다. 그래프 배열은 [출발, 도착] 노드 쌍들이 들어있는 배열입니다.
반환값은 그래프의 시작노드부터 모든 노드를 깊이 우선탐색으로 탐색한 경로가 순서대로 저장된 배열입니다.

ex)
graph = {{A,B}, {B,C}, {C,D}, {D,E}}
start = 'A'
result = {A,B,C,D,E}
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<char, vector<char>> adjlist;
unordered_set<char> visited;
vector<char> result;

void dfs(char node)
{
	visited.insert(node);
	result.push_back(node);

	//현재 노드와 인접한 노드중, 방문하지 않은 노드에 깊이우선탐색을 계속 진행
	for (auto neighbor : adjlist[node])
	{
		if (visited.find(neighbor) == visited.end())
			dfs(neighbor);
	}
}

vector<char> solution(vector<pair<char, char>>graph, char start)
{
	//인접리스트 생성
	for (auto e : graph)
	{
		adjlist[e.first].push_back(e.second);
	}

	dfs(start);
	return result;
}

int main()
{
	vector<pair<char, char>> graph = { {'A','B'},{'B','C'},{'B','E'}, {'C','F'}, {'E','F'} };
	char start = 'A';
	vector<char> result = solution(graph, start);

	for (auto e : result)
	{
		cout << e << ' ';
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////

가로N개 세로N개의 방으로 이루어진 정사각형 미로가있고 각 방마다 상하좌우로 유도하는 화살표가 있을때 화살표의 방향대로 따라가면 미로밖으로 벗어나지 못하는 방의 개수를 구하라.입력 - 첫째줄에 미로의 크기를 의미하는 정수 N이 주어진다.둘째 줄부터 Nㅐ의 줄에 걸쳐 미로의 바닥에 적힌 화살표의 방향이 각 줄마다 N개의 문자로 공백없이 주어진다.I번째 줄에서 J번째로 주어지는 문자는 미로의 1행j열에 위치한 방에 붙어있는 화살표방향을 의미한다.화살표의 방향은 L, R, U, D 네개의 문자로 주어지고 이동한 위치가 미로의 범위를 벗어나는 경우 미로를 탈출함을 의미한다.예시1 4 DRDU DULL RRDU LUDU 일때 출력 7

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> board;
vector<vector<int>> state;
// 0 = 미방문, 1 = 방문중(스택), 2 = 탈출 가능, 3 = 사이클(탈출 불가능)

int dx[256], dy[256];

int dfs(int x, int y) {
	if (state[x][y] == 1) return state[x][y] = 3;      // 사이클
	if (state[x][y] == 2 || state[x][y] == 3) return state[x][y];

	state[x][y] = 1; // 방문중

	int nx = x + dx[board[x][y]];
	int ny = y + dy[board[x][y]];

	if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
		return state[x][y] = 2; // 탈출 가능
	}

	int result = dfs(nx, ny);
	if (result == 3) return state[x][y] = 3;
	return state[x][y] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	board.resize(N);
	for (int i = 0; i < N; i++) cin >> board[i];

	dx['L'] = 0; dy['L'] = -1;
	dx['R'] = 0; dy['R'] = 1;
	dx['U'] = -1; dy['U'] = 0;
	dx['D'] = 1; dy['D'] = 0;

	state.assign(N, vector<int>(N, 0));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (state[i][j] == 0) dfs(i, j);
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (state[i][j] == 3) cnt++;

	cout << cnt;
}

세계적인 도둑은 손만 댔다하면 그 어떤 보안 시트템도 손쉽게 무력화 시키는것으로 유명하다 어떠한 금고를 풀어야하는데 고전적인 자물쇠 하나로 잠겨있다. 1. 이 자물쇠는 N자리의 비밀번호를 가지고있고, 다이얼의 눈금을 총M칸돌려서 해제할수 있다. 2. 다이얼은 총 10개의 눈금이 원형으로 배치되어있고, 각 눈금에는 0부터 9까지의 번호가 시계방향으로 쓰여있다.특정 숫자를 입력하기 위해서는 다이얼을 돌려서 그 숫자가 써진 눈금을 금속 핀아래에 위치시켜야한다.처음에 금속핀 아래에는 0이써진 눈금이있고, 다이얼을 돌릴때는 시계반대방향으로만 돌릴수 있다.숫자를 입력하고 나면 다이얼은 더 움직이지 않고 가만히있는다.예를들어 현재 금속핀 아래에 숫자 0이 있고 다음에 9를 입력하고자 할때에는 다이얼을 시계반대방향으로 아홉칸 움직여야한다. 4. 단, 숫자를 입력하지 않고 다이얼을 한번에 열칸 이상 움직일수는 없다.이때 도둑은 조건을 만족하는 비밀번호를 모두 입력해보려고 한다 할때 몇가지의 비밀번호를 입력해야할지 구하라 경우의 수가 너무 많을수 있으니 이를 10 ^ 9 + 7로 나눈 나머지를 구하라.입력 1 <= N <= 200 1 <= M <= 1000 입력으로 주어지는 수는 모두 정수이다.이거 풀어봐 코드만 줘봐 C++17로 위에 포함시켜야하는 헤더까지 싹

#include <bits/stdc++.h> using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;
	if (!(cin >> N >> M)) return 0;
	const long long MOD = 1000000007LL;

	vector<vector<long long>> dp(10, vector<long long>(M + 1, 0));
	dp[0][0] = 1; // before entering any digit, dial at 0 with cost 0

	for (int i = 0; i < N; ++i) {
		vector<vector<long long>> ndp(10, vector<long long>(M + 1, 0));
		for (int x = 0; x < 10; ++x) {
			for (int j = 0; j <= M; ++j) {
				long long ways = dp[x][j];
				if (!ways) continue;
				for (int c = 0; c <= 9; ++c) {
					int y = (x + c) % 10;       // counter-clockwise increases digit
					int nj = j + c;
					if (nj > M) break;
					ndp[y][nj] = (ndp[y][nj] + ways) % MOD;
				}
			}
		}
		dp.swap(ndp);
	}

	long long ans = 0;
	for (int x = 0; x < 10; ++x) {
		ans = (ans + dp[x][M]) % MOD;
	}
	cout << ans << "\n";
	return 0;

}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////