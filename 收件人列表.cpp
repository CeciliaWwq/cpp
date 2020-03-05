#if 0
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string sum;
	string str;
	while (cin >> n)
	{
		getline(cin, str);
		while (n--)
		{
			getline(cin, str);
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i] == ' ' || str[i] == ',')
				{
					str.insert(0, 1, '"');
					str.push_back('"');
					break;
				}
			}
			if (n >= 1) {
				str.push_back(',');
				str.push_back(' ');
			}
			sum += str;
		}
		cout << sum << endl;
		sum.clear();
	}
}
#endif