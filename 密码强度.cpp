#include<iostream>
#include<string>
using namespace std;
int numberchar(string str,int k)
{
	//根据ascll码判断大小写
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			big++;
		}
		if (str[i] >= 97 && str[i] <= 122)
		{
			small++;
		}
	}
	if (big == 0 && small == 0)
	{
		return 0;
	}
	if(big==k||small==k)
	{ 
		return 10;
	}
	else { return 20; }
}

int numNumber(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; ++i)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			num++;
		}
	}
	if (num == 0) { return 0; }
	if (num == 1) { return 10; }
	else { return 20; }
}

int symbal(string str, int k)
{
	int sym = 0;
	for (int i = 0; i < k; ++i)
	{
		if (!(str[i] >= 65 && str[i] <= 90 ||
			str[i] >= 97 && str[i] <= 122 ||
			str[i] - '0' >= 0 && str[i] - '0' <= 9))
		{
			sym++;
		}
	}
	if (sym == 0) { return 0; }
	if (sym == 1) { return 10; }
	else { return 25; }
}
int main()
{
	string str;
	int sum1, sum2, sum3, sum4, sum5;
	int k = str.size();
	if (k <= 4) { sum1 = 5; }
	if (k >= 5 && k <= 7) { sum1 = 10; }
	else { sum1 = 25; }
	sum2 = numberchar(str, k);
	sum3 = numNumber(str, k);
	sum4 = symbal(str, k);
	if (sum2 != 0 && sum3 != 0 && sum4 != 0)
	{
		if (sum2 = 10) { sum5 = 3; }
		else { sum5 = 5; }
	}

	else if (sum2 > 0 && sum3 > 0 && sum4 == 0) sum5 = 2; 
	if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90) cout << "VERY_SECURE" << endl;
	else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80) cout << "SECURE" << endl; 
	else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70) cout << "VERY_STRONG" << endl; 
	else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60) cout << "STRONG" << endl; 
	else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50) cout << "AVERAGE" << endl; 
	else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25) cout << "WEAK" << endl; 
	else cout << "VERY_WEAK" << endl;
return 0;
}