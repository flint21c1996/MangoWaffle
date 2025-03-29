#include <iostream>
int main() {
	int const a = 5;
	int const b = 3;

	const int* const pa = &a;
	const int* const pb = &b;
	int c = (*pb - *pa) + 2;
	
	const int d = c * 2;
	d += 3;

	std::cout << "d: " << d << std::endl;
	return 0;
}