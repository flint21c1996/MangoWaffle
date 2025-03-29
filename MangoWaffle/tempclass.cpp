#include "tempclass.h"


template<>
int tempclass::Add(int a, int b)
{
	return a + b + b;
}