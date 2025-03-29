#include <iostream>
using namespace std;

void PrintHanoy(int* a, int* b, int* c, int anum, int bnum, int cnum)
{
	cout << endl;
}


void Hanoy(int* a, int* b, int* c, int anum, int bnum, int cnum)
{
	if (a[0] == 0)
	{

	}
	else if (b[0] == 0 && c[0] == 0)
	{
		b[0] = a[anum];
		a[anum] = 0;
		anum--;

		c[0] = a[anum];
		a[anum] = 0;
		anum--;

		Hanoy(a, b, c, anum, bnum, cnum);
	}
	else if (*(a + anum) > *(b + bnum))
	{
		*(b + bnum) = *(a + anum);
		*(a + anum) = 0;
		bnum++;
		anum--;
		if (anum < 0)
			anum = 0;
		Hanoy(a, b, c, anum, bnum, cnum);
	}

	else if (*(a + anum) > *(c + cnum))
	{
		*(c + cnum) = *(a + anum);
		*(a + anum) = 0;
		cnum++;
		anum--;
		if (anum < 0)
			anum = 0;
		Hanoy(a, b, c, anum, bnum, cnum);
	}

	else if (*(b + bnum) > *(c + cnum))
	{
		*(c + cnum) = *(b + bnum);
		*(b + bnum) = 0;
		cnum++;
		bnum--;
		if (bnum < 0)
			bnum = 0;
		Hanoy(a, b, c, anum, bnum, cnum);
	}

	else if (*(c + cnum) > *(a + anum))
	{
		*(a + anum) = *(c + cnum);
		*(c + cnum) = 0;
		anum++;
		cnum--;
		if (cnum < 0)
			cnum = 0;
		Hanoy(a, b, c, anum, bnum, cnum);
	}

	else if (*(c + cnum) > *(b + bnum))
	{
		*(b + bnum) = *(c + cnum);
		*(c + cnum) = 0;
		bnum++;
		cnum--;
		if (cnum < 0)
			cnum = 0;
		Hanoy(a, b, c, anum, bnum, cnum);
	}


}

int main()
{
	///하노이탑 드가자~

	//첫번째 탑
	int a[100] = { };
	//두번째 탑
	int b[100] = { };
	//세번째 탑
	int c[100] = { };

	int anum = 0;
	int bnum = 0;
	int cnum = 0;
	cout << "원판의 개수를 입력하세요." << endl;
	cin >> anum;

	for (int i = 0; i < anum; i++)
	{
		a[i] = i + 1;

	}

	anum--;
	Hanoy(a, b, c, anum, bnum, cnum);

	for (int i = 0; i < anum; i++)
	{
		cout << a[i] << endl;
	}

	for (int i = 0; i < bnum; i++)
	{
		cout << b[i] << endl;
	}

	for (int i = 0; i < cnum; i++)
	{
		cout << c[i] << endl;
	}
}