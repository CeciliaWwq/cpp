// write your code here cpp
#include<iostream>
using namespace std;
long long Daily(int day)
{
	long long D1, D2, sumD;
	if (day == 1 || day == 2)
		return 1;
	D1 = 1, D2 = 1, sumD = 0;
	for (int i = 2; i < day; ++i)
	{
		sumD = D1 + D2;
		D1 = D2;
		D2 = sumD;
	}
	return sumD;
}
int main()
{
	int dayStart = 0;
	int dayEnd = 0;
	while (cin >> dayStart)
	{
		long long sum = 0;
		cin >> dayEnd;
		for (int i = dayStart; i <= dayEnd; i++)
		{
			sum += Daily(i);
		}
		cout << sum << endl;
	}
	return 0;
}