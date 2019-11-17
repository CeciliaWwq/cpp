//#include<iostream>
//using namespace std;
/*
class A
{
public:
	int _a;
};
class B :virtual public A
{
public:
	int _b;
};
class C :virtual public A
{
public:
	int _c;
};
class D :public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5; 
}
*/
/*
#include<iostream>
#include<stdbool.h>
using namespace std;
bool JudgePrimeNum(int a)
{
	int i = 0;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int a = 0;
	int b = 0;
	int n = 0;
	while (cin >> n) {
		if (n < 2) { return 1; }
		else {
			for (int i = n / 2; i > 1; i--) {
				if (JudgePrimeNum(i) == true && JudgePrimeNum(n - i) == true)
				{
					a = i;
					b = n - i;
				}
			}
			cout << a << endl;
			cout << b << endl;
		}
	}
	return 0;
}
*/