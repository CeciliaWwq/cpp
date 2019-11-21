/*
#include<iostream>
#include<vector>
using namespace std;
int Solution(int n, vector<int> v)
{
	int sum1 = 0;
	int sum2 = 0;
	if (v.empty()) { return 0; }
	//sum1是到v[i-1]的最大和
	//sum2是到v[i]的最大和
	int i = 0;
	int sz = v.size();
	int max = v[0];
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		sum2 = sum1 >= 0 ? sum1 + v[i] : v[i];//选当前最优解
		if (sum2 > max)
		{
			max = sum2;
		}
		if (sum2 < 0) {
			sum2 = 0;
		}
		sum1 = sum2;
	}
	return max;
}
int main()
{
	size_t num = 0;
	cin >> num;
	vector<int>_v(num);
	for (size_t i = 0; i < num; i++)
	{
		cin >> _v[i];
	}

	int b = Solution(num, _v);
	cout << b << endl;
}
*/