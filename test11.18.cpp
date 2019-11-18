/*
#include<iostream>
#include<string>
#include<stdbool.h>
#include<algorithm>
using namespace std;
int main()
{
	int m = 0;
	int n = 0;
	string table = "0123456789ABCDEF";
		string s = "";
	bool flag = false;
	cin >> m >> n;
	if (m < 0) {
		m = 0 - m;
		flag = true;
	}
	while (m)
	{
		s += table[m % n];
		m /= n;
	}
	if (flag) { s += "-"; }
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int x, y, z, w;
	cin >> x >> y >> z >> w;
	if (x >= -30 && x <= 30 && y >= -30 && y <= 30 && z >= -30 && z <= 30 && w >= -30 && w <= 30)
	{
		int A = (x + z) / 2;
		int C = (w - y) / 2;
		int B1 = (y + w) / 2;
		int B2 = (z - x) / 2;
		if (B1 != B2) { cout << "No" << endl; }
		else { cout << A << " " << B1 << " " << C << endl; }
	}
	else { return 0; }
}
*/