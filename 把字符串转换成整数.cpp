#include<iostream>
#include<vector>
#include<string>
using namespace std;


	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int flag = 1;
		int count = 0;
		if (str[0] == '-') { flag = 1; str[0] = '0'; }
		if (str[0] == '+') { flag = 1; str[0] = '0'; }
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				count = count * 10 + str[i] - '0';
			}
			else {
				count = 0;
				break;
			}
		}
		if (flag == 1)
		{
			count *= flag;
		}
		cout << count << endl;
	}

int main()
{
	string s("1626276");
	StrToInt(s);
	return 0;
}