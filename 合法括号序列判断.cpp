#if 0
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case')':
			{
				if (sc.empty()|| sc.top() != '(') return false;//注意顺序要先判断是否为空在进一步判断，有时候逻辑一点不缜密排错都需要很久
				else sc.pop();
			}
			break;
			default: return false;
			}
		}
		return true;
	}
};
#endif