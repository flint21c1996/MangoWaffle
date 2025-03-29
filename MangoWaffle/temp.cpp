#include <iostream>
using namespace std;

class Entity
{
public:
	void Print() const
	{
		std::cout << "Print" << std::endl;
		std::cout << this->a << std::endl;
	}
	int a = 0;
};

int main()
{
	Entity* ptr = nullptr;
	Entity& _ref = *ptr;    // No crash here - I expected a null pointer exception

	_ref.Print();
}