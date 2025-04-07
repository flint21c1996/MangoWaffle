//////////////////////////////Virtual PureCall////////////////////////////////////////////
///Virtual PureCall
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



///////////////////////////virtual 소멸자.///////////////////////////////////////
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "A()\n"; }
	virtual ~A() { cout << "~A()\n"; }

	virtual void foo()
	{
		cout << "QWE" << endl;
	}
};

class B : public A
{
public:
	B() { cout << "B()\n"; }
	B(int arg) { cout << "B(int)\n"; }
	~B() { cout << "~B()\n"; }

	virtual void foo()
	{
		cout << "asd" << endl;
	}

};

int main()
{
	A* b = new B(10); //B*일 경우 virtual이 없어도 정상출력이 된다.
	b->foo();

	A* b1 = new A(); //B*일 경우 virtual이 없어도 정상출력이 된다.
	B* b2 = new B(); //B*일 경우 virtual이 없어도 정상출력이 된다.

	delete b1;
	delete b2;
	//delete static_cast<B*>(b);
	delete b;

	///출력값의 예상
	//A()
	//B(int)
	//~B()
	//~A()
	///어떤식으로 동작하는지.?
	//어찌되었건 virtual(가상함수)이 선언되었다면 vfTable이 생긴다.
	//이때 A의 virtual function에 대한 VT가 생기고 B의 virtual Function에 따라 VT이 갱신이 된다.
	// B의 소멸자는 A에 대한 소멸도 처리하도록 컴파일러가 관리를 한다. 
	// 이때 만약 A의 소멸자에 virtual처리를 하지않으면 A* b = new B의 경우,
	// A의 소멸자가 호출이 되기에 메모리 누수가 난다.
	//
}
////////////////////////////Try-Catch 이펙티브 C++ - part. 소멸자 ////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

