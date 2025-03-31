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
			peopleStop[stages[i]-1]++;
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
		answer.push_back(get<0>(result[i])+1);
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