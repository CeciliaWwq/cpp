/*
//数组中有一个数字出现次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1，2，3,2,2，2，5,4,2}2在数组中出现了5次，因此输出2

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int sz = numbers.size();
		int array[9] = { 0 };
		for (int i = 0; i < sz; i++) {
			array[numbers[i]] = 1;
			for (int j = 0; j < sz; j++) {
				if (numbers[j] == numbers[i])
				{
					array[numbers[i]]++;
				}

			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (array[i] >= sz / 2) {
				return i;
			}
		}
		return 0;
	}
};

//在一行内输出str中连续最长数字串
//输入：abcd12345ed125ss123456789
//输出：123456789
#include<iostream>
using namespace std;
int continumax(char* outputstr, char* inputstr)
{
	char* in = inputstr, * out = outputstr, * temp, * final;
	int count = 0, maxlen = 0;
	while (*in != '\0')
	{
		if (*in >= '0' && *in <= '9')
		{
			for (temp = in; *in >= '0' && *in <= '9'; in++)
				count++;
		}
		else
			in++;
		//找到问题所在了，因为cout<maxlen时，count没有机会得到清零。
		if (maxlen < count)
		{
			maxlen = count;
			count = 0; //count 计数器 及时清零
			final = temp; // temp保存的是数字串的其实地址
		}
		count = 0;//增加这一句，当count>maxlen时 赋值成功，保留count无意义
		//当count比maxlen小时，更没有保存价值，直接清零
	}
	for (int i = 0; i < maxlen; i++)
	{
		*out = *final;
		out++;
		final++;
	}
	*out = '\0';
	return maxlen;
}
int main()
{
	//char* a = "abcd12345ed125ss123456789";
	char c[20];
	int n = continumax(c, a);
	cout << "c=" << c << endl;
	cout << "n=" << n;
}

int continumax(char* outputstr, char* inputstr)
{
	char* in = inputstr, * out = outputstr, * temp, * final;
	int count = 0, maxlen = 0;
	while (*in != '\0')
	{
		if (*in >= '0' && *in <= '9')
		{
			for (temp = in; *in >= '0' && *in <= '9'; in++)
				count++;
		}
		else
			in++;
		//找到问题所在了，因为cout<maxlen时，count没有机会得到清零。
		if (maxlen < count)
		{
			maxlen = count;
			count = 0; //count 计数器 及时清零
			final = temp; // temp保存的是数字串的其实地址
		}
		count = 0;//增加这一句，当count>maxlen时 赋值成功，保留count无意义
		//当count比maxlen小时，更没有保存价值，直接清零
	}
	for (int i = 0; i < maxlen; i++)
	{
		*out = *final;
		out++;
		final++;
	}
	*out = '\0';
	return maxlen;
}
int main()
{
	char* a = "abcd12345ed125ss123456789";
	char c[20];
	int n = continumax(c, a);
	cout << "c=" << c << endl;
	cout << "n=" << n;
}
*/
