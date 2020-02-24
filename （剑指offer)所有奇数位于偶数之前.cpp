#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void reOrderArray(vector<int>& array) {
		vector<int>array_double;//偶数数组
		vector<int>::iterator id, ie;
		id = array.begin();
		for (; id != array.end();)
		{
			if (*id % 2 == 0)
			{
				array_double.push_back(*id);
				id = array.erase(id);
			}
			else { id++; }
		}
		vector<int>::iterator id2, ie2;
		id2 = array_double.begin();
		ie2 = array_double.end();
		for (; id2 != ie2; id2++)
		{
			array.push_back(*id2);
		}
	}
};
int main()
{
	vector<int>array= { 1,2,3,4,5,6,7 };
	Solution s;
	s.reOrderArray(array);
}


#if 0
class Solution {
public:
	void reOrderArray(vector<int>& array) {
		size_t n = array.size();
		vector<int>arraysigle(n, 0);
		vector<int>arraydouble(n, 0);
		vector<int>array2(n, 0);
		size_t s = 0;
		size_t d = 0;
		size_t j = 0;
		for (size_t i = 0; i < n; i++) {
			if (array[i] % 2 == 1)//奇数
			{
				arraysigle[s++] = array[i];
			}
			else {//
				arraydouble[d++] = array[i];
			}
		}
		for (size_t m = 0; m < n; m++)
		{
			if (arraysigle[m] != 0)
			{
				array2[j++] = arraysigle[m];
			}
			else
				break;
		}
		for (size_t v = 0; v < n; v++)
		{
			if (arraydouble[v] != 0)
			{
				array2[j++] = arraydouble[v];
			}
			else
				break;
		}
		for (size_t i = 0; i < n; i++)
		{
			array[i] = array2[i];
		}
	}
};
#endif
