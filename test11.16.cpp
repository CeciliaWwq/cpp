//求最大连续bit位
#include<iostream>
using namespace std;
int main()
{
	int n;
	int flag = 0;
	int sum = 0;
	while (cin >> n)
	{
		while (n)
		{
			if (n & 1 == 1)
			{
				flag += 1;
				sum = sum > flag ? sum : flag;
			}
			else flag = 0;
			n = n >> 1;
		}
		cout << sum << endl;
	}
	return 0;
}
//最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		int c = 0;
		if (a == b || a == b / 2)return a;
		if (b == a / 2)return b;
		while (a != b)
		{
			if (a > b)
			{
				a /= 2;
			}
			else {
				b /= 2;
			}
		}
		c = a;
		return c;
	}
};
//