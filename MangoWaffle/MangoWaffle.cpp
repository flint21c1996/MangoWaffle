#include <iostream>
using namespace std;;

///try-catch
class Sung
{
public:
	~Sung()
	{
		if (!IsClose())
		{
			try
			{
				IsClose();
				throw runtime_error("예외 발생");
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
				cout << "닫히지 않았습니다." << endl;
			} 
		}
	}

	//잘 닫혔는지 확인하는 함수.
	bool IsClose()
	{
		return misClose;
	}

	//멤버를 닫는 함수를 만든다.
	void close()
	{
		misClose = true;
	}
	bool misClose = false;
};

int main()
{
	Sung s;



	return 0;

}