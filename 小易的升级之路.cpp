#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	int c = 0;
	while (cin >> n >> c)
	{
		vector<int>v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (v[i] <= c) {
				c += v[i];
			}
			else {
				//求最大公约数
				while (v[i] != 0)
				{
					int temp = c % v[i];
					c = v[i];
					v[i] = temp;
				}
				c += v[i];
			}
		}
		cout << c;
	}
	return 0;
}