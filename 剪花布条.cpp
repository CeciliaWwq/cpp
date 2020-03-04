#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 )
	{
		cin >> s2;
		int count = 0;
		size_t j = 0;
		for (size_t i = 0; i < s1.length();i++)
		{
			while (s1[i] == s2[j]&&j<s2.length()-1)
			{
				i++;
				j++;
				if (j == s2.length()-1)
				{
					count++;
				}
			}
			j = 0;
		}
		cout << count << endl;
	}
	return 0;
}