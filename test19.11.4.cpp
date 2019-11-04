#define CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<vector>
//输入描述：
//每组数据输入一个字符串，
//字符串最大长度为100，且只包含字母，
//不可能为空串，区分大小写。 
//输出描述： 
//每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
#include<string>
using namespace std;
/*
int main()
{
	string str;
	getline(cin,str);
	for (int i = 0; i < str.size(); ++i)
	{
		int array[256]={0};
		for (int j = i; j < str.size(); ++j)
		{
			if (str[i] == str[j])
			{
				array[str[i]]++;
			}
			else {
				array[str[i]++]++;
			}
		}
	}
	for(int i=0;i<str.size();i++)
	{
	 if(array[str[i]]!=0){
	 cout<<str[i];
	 array=0;}
	 }
	
}
*/
/*
int main()
{
	string str;
	while (cin >> str)
	{
		int hash[256] = { 0 };
		for (auto ch : str)
		{
			if (hash[ch] == 0)
			{
				cout << ch;
				hash[ch] = 1;
			}
		}
		cout << endl;
	}

	return 0;
}
*/

int main()
{
	string str;
	getline(cin, str);
	int array[256] = { 0 };
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (array[str[i]] == 0)
		{
			cout << str[i];
			array[str[i]]++;
		}
	}
	cout << endl;

}
/*
//二分查找
//用复杂度为logn 查找某个元素
class Finder {
public:
	int findElement(vector<int> a, int n, int x) {
		int left = 0, right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (a[mid] == x)
				return mid;

			// [left, mid][mid,right]
			if (a[left] < a[mid])
			{
				if (a[left] <= x && x < a[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				if (a[mid] < x && x <= a[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}

		return -1;
	}
};
*/
//寻找topk问题 寻找第5大的元素