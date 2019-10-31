#define CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		elem.push(x);
		if (min.empty() || x <= min.top()) {
			min.push(x);
		}
	}

	void pop() {

		if (elem.top() == min.top())
		{
			min.pop();
		}
		elem.pop();
	}

	int top() {
		return elem.top();
	}

	int getMin() {
		return min.top();
	}
private:
	std::stack<int> elem;
	std::stack<int> min;
};

class Solution {
public:    
	bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
	{        //入栈和出栈的元素个数必须相同        
		if(pushV.size() != popV.size())            
			return false;                
		// 用s来模拟入栈与出栈的过程        
		int outIdx = 0;        
		int inIdx = 0;        
		std::stack<int> s;                
		while(outIdx < popV.size())
	{
			// 如果s是空，或者栈顶元素与出栈的元素不相等，就入栈            
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}
			// 栈顶元素与出栈的元素相等，出栈            
			s.pop();
			outIdx++;
		}
		return true;
	}
};
