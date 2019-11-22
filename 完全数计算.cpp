#include<iostream> 
using namespace std;
bool ispefect(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			sum += i;
	}     if (sum == n)
		return 1;
	else   return 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ispefect(i))
				count++;
		}
		cout << count << endl;
	}
}