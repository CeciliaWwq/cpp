#include<iostream>
#include<map>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s)) {
		map<string, int>mp;
		string temp;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
			{
				if (temp != "")
				{
					mp[temp]++;
				}
				temp = "";
			}
			else {
				temp += tolower(s[i]);
			}
		}
		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			cout << it->first << ":" << it->second << endl;
		}
	}
}
