#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int>b(n);
	b[0] = a[0];
	int res = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = max(b[i - 1] + a[i], a[i]);
		res = max(b[i], res);
	}
	cout << res << endl;
	return 0;
}
int max(int a, int b)
{
	return a > b ? a : b;
}