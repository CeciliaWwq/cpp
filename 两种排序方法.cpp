#if 0
//这道题是集合了vector和string于一身的通过字符串长度和ASCLL码值的大小比较的神仙题目
//不过还算简单啦
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)//范围for的引用加不加决定了值是否可以进入这个数组
	{
		cin >> str;
	}
	bool symlen = true, symlex = true;
	//比较长度
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			symlen = false;
			break;
		}
	}
	//比较ascll码值
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] >= v[i])
		{
			symlex = false;
			break;
		}
	}
	if (symlen && symlex)
	{
		cout << "both" << endl;
	}
	else if (!symlen && symlex)
	{
		cout << "lexicographically" << endl;
	}
	else if (symlen && !symlex)
	{
		cout << "lengths" << endl;
	}
	else if (!symlen && !symlex) {
		cout << "none" << endl;
	}

}
#endif