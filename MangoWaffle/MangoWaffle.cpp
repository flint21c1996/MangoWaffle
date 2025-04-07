#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A() 
	{
		Init();
	};
	void Init()
	{
		virtual_method();
	}

	virtual void virtual_method() = 0;
};

class B : public A
{
public:
	B() {};

	virtual void virtual_method()
	{
		cout << "Hello" << endl;
	}
};

int main()
{
	B b;
}