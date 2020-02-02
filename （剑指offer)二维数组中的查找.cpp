#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {

		int row = array.size();
		int col = array[0].size();
		int i;
		int j;
		for (j = 0, i = col - 1; j < row && i >= 0;)//i是行，j是列从左上开始
		{
			if (array[j][i] == target)
			{
				return true;
			}
			if (array[j][i] > target)
			{
				i--;
				continue;
			}
			if (array[j][i] < target)
			{
				j++;
			}
		}
		return false;
	}
};