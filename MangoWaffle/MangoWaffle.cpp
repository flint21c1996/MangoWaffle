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
				throw runtime_error("���� �߻�");
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
				cout << "������ �ʾҽ��ϴ�." << endl;
			} 
		}
	}

	//�� �������� Ȯ���ϴ� �Լ�.
	bool IsClose()
	{
		return misClose;
	}

	//����� �ݴ� �Լ��� �����.
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