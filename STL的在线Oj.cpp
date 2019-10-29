#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
//删除排序数组中的重复项
/*
class EraseSameWord {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int i = 0;
		int j = 0;
		for (j = 1; j < nums.size(); ++j)
		{
			while (nums[i] != nums[j]) {
				nums[++i] = nums[j];
			}
		}
		return i + 1;
	}
};
*/
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int Rmax = -10000000;
		int sz = array.size();
		for (int i = 0; i < sz; ++i)
		{
			for(int j = 0; j < sz; j++)
			{
			int max = 0;
			for (int m = i; m <= j; m++) {
				max += array[m];
			}
			if (max > Rmax) {
				Rmax = max;
			}
			}

		}
		return Rmax;
		}
	};
