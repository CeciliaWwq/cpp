#if 0
#include<iostream>
#include<string>
#include<stdbool.h>
using namespace std;

bool JudgeCircleLitter(string& s)
{
	size_t begin =0;
	size_t end = s.size() - 1;
	while (begin <= end) {
		if (s[begin] != s[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}
int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (int i = 0; i <=str1.size(); i++)
	{
		string s = str1;
		s.insert(i, str2);
		if (JudgeCircleLitter(s) ){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif