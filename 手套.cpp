/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		//拿掉只有一只或者一只都没有的情况，并把这种情况加在sum上
		//取两边都有手套的最小数
		//这些最小数排序
		//去掉最小数中最小的那个
		//再把这双手套拿出来
		vector<int> s;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				sum += (left[i] + right[i]);
			}
			else {
				
				s.push_back(left[i] > right[i] ? right[i] : left[i]);
			}
		}
		sort(s.begin(), s.end());
		for (int i = s.size() - 1; i > 0; i--)
		{
			sum += s[i];
		}
		return sum + 2;
	}
};
*/