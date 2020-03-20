
#if 0
class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			str[0] = '0';
		}
		int sum = 0;
		int result = 0;
		for (auto& e : str)
		{
			if (e > '9' || e < '0')
			{
				sum = 0;
				break;
			}
			sum = result * 10 + flag * (e - '0');
			if ((sum > 0 && result < 0) || (sum < 0 && result>0))
				return 0;
			result = sum;
		}
		return sum;
	}
};
#endif
//这道题最大的一个坑就是溢出问题：
//首先明确在整形下（十进制）表示范围：-2147483648~2147483647
//思路1：:设置成long long并增加判断条件
/*
作者：量子猫～

   int StrToInt(string str) {
		int length=str.size();
		int symbol=1,i=0;
		if(str[0]=='-'||str[0]=='+')
		{
			if(str[0]=='-')
				symbol=-1;
			i++;
		}
		long long retData=0;
		while(str[i]!='\0')
		{
			if(str[i]>='0'&&str[i]<='9'&&i<=length-1)
				retData=(retData<<3)+(retData<<1)+str[i++]-'0';
			else return 0;
			if(symbol==1&&retData>0x7FFFFFFF||symbol==-1&&retData>(int)0x80000000)
				return 0;
		}
		return retData*symbol;
	}
*/
//在这里借用某大佬的方法说明一下问题
//为什么这里还是编不过？？
//因为在循环的过程中程序是走不到‘symbol==-1&&retData<(int)0x80000000’这句的
//判断前是正数的判断过程因此最大为2147483647，即使输入了2147483648（越界）程序会自己优化在int范围内2147483647
//执行后输出：2147483647，相当于没判断！


/*
sum = result * 10 + flag * (e - '0');
if ((sum > 0 && result < 0) || (sum < 0 && result>0))
	return 0;
result = sum;
*/
// 这里让e乘以flag，可以在不用if的情况下分正数和负数情况进行，而且必须分正负
// 如果不分正负，则在str = "-2147483648"时，负数不会溢出，然而如果不带上负号，正数2147483640+8就溢出了