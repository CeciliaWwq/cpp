//1.使用bitset将数字转化为8位二进制
//2.将bitset转化为字符串，使用‘0’对字符串分割，找到
//找到最大连续子串即可
#include<iostream>
#include<string>
#include<bitset>   //bitset
#include<sstream>  //stringstream
#include<algorithm>//max
using namespace std;
int main()

{
	int n;
	while (cin >> n)
	{
		bitset<8> B(n);//转为二进制
		string s = B.to_string();//转字符串
		stringstream ss(s);
		string tmp;
		int m = 0;
		while (getline(ss, tmp, '0'))//字符串分割
			m = max(m, (int)tmp.size());//找最大字符串
		cout << m << endl;
	}
	return 0;
}