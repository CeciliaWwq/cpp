// write your code here cpp
#include<iostream>
using namespace std;
int ripeR(int n)
{
	if (n == 2)return 1;
	else {
		int temp1 = 0;
		int temp2 = 1;
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum = temp1 + temp2;
			temp1 = temp2;
			temp2 = sum;
		}
		return sum;
	}
}

int main()
{
	int n = 0;
	int sum = 0;
	while (cin >> n)
	{
		if (n == 1) { sum=1; }
		else if (n == 2) { sum=2; }
		else {
			sum = ripeR(n) + ripeR(n - 1);
		}
		cout << sum<<endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

#if 0
int main()
{
	long long n;
	long long child = 1;
	long long adult = 0;
	long long i = 0;
	long long temp;

	while (cin >> n)
	{
		i = 0;
		child = 1;
		adult = 0;
		while (++i <= n)
		{
			temp = child;
			child = adult;
			adult += temp;
		}

		cout << adult + child << endl;

	}
}
#endif