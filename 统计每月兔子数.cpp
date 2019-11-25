#include<iostream>
using namespace std;
int getTotalCount(int month)
{
	int count;
	if (month < 3)
		count = 1;
	else
		count = getTotalCount(month - 1) + getTotalCount(month - 2);
	return count;
}
int main()
{
	int month;
	while (cin >> month)
	{
		cout << getTotalCount(month) << endl;
	}
	return 0;
}
