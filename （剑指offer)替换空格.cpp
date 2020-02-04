class Solution {
public:
	void replaceSpace(char* str, int length) {
		int count = 0;
		for (int i = length - 1; i >= 0; i--)//计算字符串有多少个空格
		{
			if (str[i] == ' ')
			{
				count++;
			}
		}
		for (int j = length - 1; j >= 0; j--)
		{
			if (str[j] != ' ')
			{
				str[j + count * 2] = str[j];
			}
			else {
				count--;
				str[j + count * 2] = '%';
				str[j + count * 2 + 1] = '2';
				str[j + count * 2 + 2] = '0';
			}
		}
	}
};