#pragma once
class tempclass
{
public:
	template<typename T>
	T Add(T a, T b);

	template<>
	int Add(int a, int b);
};


template<typename T>
T tempclass::Add(T a, T b)
{
	return a + b;
}
