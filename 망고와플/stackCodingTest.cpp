//-----------------------��ȣ ȸ���ϱ�-----------------------------------
#include <string>
#include <vector>
#include <stack>

using namespace std;
//c�� ������ �ֻ���� ���ϰ� ���� true�� ��ȯ�ϰ� pop���� ���ִ� �Լ�.
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
	//i�� �ε����� �ϰ� ������ �Ѿ�� �տ�������
	for (int i = 0; i < s.size(); i++)
	{
		stack<char> _stack;
		bool val = true;
		for (int j = 0; j < s.size(); j++)
		{
			//��ⷯ ������ ���� ���� �Ѿ�� �ʵ����Ѵ�.
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
