#include<iostream>
#include<string>
#include<vector>
using namespace std;
void cmdExplain(const string& s)
{
	vector<string> a;
	int sz = s.size();
	int flag = 0;
	string temp = "";
	for (int i = 0; i < sz; i++)
	{
		if ('"' == s[i])
		{
			flag = ~flag;
		}
		else if (' ' == s[i] && 0 == flag)
		{
			a.push_back(temp);
			temp = "";
		}
		else temp += s[i];
	}
	a.push_back(temp);
	int count = a.size();
	cout << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << endl;
	}
}
int main()
{
	string str;
	while (getline(cin, str)) {
		cmdExplain(str);

	}
}