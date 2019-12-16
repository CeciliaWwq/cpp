#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int maxnum = 0;
		int count = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				maxnum = max(maxnum, count);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxnum << endl;
	}
	return 0;
}