//题目描述：F(0)=0;F(1)=1 Fibonacci:0 1 1 2 3 5 8 13 ...
//输入15
//输出最小的步数 2
/*
#include<iostream>
using namespace std;
int main()
{
	int N, l, r, f0 = 0, f1 = 1, f;
	cin >> N;
	while (1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f < N) l = N - f;
		else {
			r = f - N;
			break;
		}
	}
	cout << min(l, r) << endl;
	return 0;
}
int min(int a, int b) {
	a < b ? a : b;
}
*/

//题目描述：合法括号判断
#include<iostream>
#include<stack>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 == 1)//先排除奇数情况
			return false;
		stack<char> s1;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '(')
				s1.push(A[i]);
			else if (A[i] == ')')
			{
				if (s1.empty())
					return false;
				s1.top();
			}
			else
				return false;
		}
		if (s1.empty())
			return true;
	}
};