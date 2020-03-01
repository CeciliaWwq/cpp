#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int>stack1;
		stack<int>stack2;
		vector<int>::reverse_iterator rit = popV.rbegin();
		while (rit != popV.rend()) {
			stack2.push(*rit);
			rit++;
		}
		for (auto& e : pushV) {
			if (e == stack2.top()) {
				stack2.pop();
			}
			else { stack1.push(e); }
		}
		while ((!stack1.empty()) && (!stack2.empty()))
		{
			if (stack1.top() == stack2.top())
			{
				stack1.pop();
				stack2.pop();
			}
		}
		if (stack2.empty())
		{
			return true;
		}
		return false;
	}
};
int main()
{
	vector<int>a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	vector<int>b;
	b.push_back(4);
	b.push_back(5);
	b.push_back(3);
	b.push_back(2);
	b.push_back(1);
	Solution result;
	bool ret2=result.IsPopOrder(a, b);
	cout << "答案是:" << ret2 << endl;
}

//优化
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int>s1;
		for (size_t i = 0, j = 0; i < pushV.size();) {
			s1.push(pushV[i++]);
			while (j < popV.size() && s1.top() == popV[j])
			{
				s1.pop();
				j++;
			}
		}
		return s1.empty();
	}
};