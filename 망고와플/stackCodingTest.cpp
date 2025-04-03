//-----------------------괄호 회전하기-----------------------------------
#include <string>
#include <vector>
#include <stack>

using namespace std;
//c와 스택의 최상단을 비교하고 잠기면 true를 반환하고 pop까지 해주는 함수.
bool checkStack(stack<char>& _stack, char c)
{
	if (c == ')')
	{
		if (_stack.top() == '(')
		{
			_stack.pop();
			return true;
		}
		else
			return false;
	}
	if (c == '}')
	{
		if (_stack.top() == '{')
		{
			_stack.pop();
			return true;
		}
		else
			return false;
	}
	if (c == ']')
	{
		if (_stack.top() == '[')
		{
			_stack.pop();
			return true;
		}
		else
			return false;
	}
	return false;
}
int solution(string s) {
	int answer = 0;
	//i를 인덱스로 하고 범위를 넘어갈시 앞에서부터
	for (int i = 0; i < s.size(); i++)
	{
		stack<char> _stack;
		bool val = true;
		for (int j = 0; j < s.size(); j++)
		{
			//모듈러 연산을 통해 끝을 넘어가지 않도록한다.
			int index = (i + j) % s.size();
			if (s[index] == '(' || s[index] == '{' || s[index] == '[')
			{
				_stack.push(s[index]);
			}
			else
			{
				if (_stack.empty())
				{
					val = false;
					break;
				}
				else
				{
					if (!checkStack(_stack, s[index]))
					{
						val = false;
						break;
					}
				}
			}
		}
		if (val && _stack.empty())
		{
			answer++;
		}
	}
	return answer;
}
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
