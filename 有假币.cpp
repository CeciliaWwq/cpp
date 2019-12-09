// write your code here cpp
#include<iostream>
#include<stdio.h>
using namespace std;
int FindFakeMoney(int n)
{
	if (1 == n) { return 0; }
	if (n <= 3) { return 1; }
	return 1 + FindFakeMoney((n + 2) / 3);
}
int main()
{
	int n = 0;
	while (cin >> n && n)
	{
		cout << FindFakeMoney(n) << endl;
	}
	return 0;
}