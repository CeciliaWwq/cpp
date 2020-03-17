class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7) return index;
		int p2 = 0, p3 = 0, p5 = 0, minNum = 1;
		vector<int>arr;
		arr.push_back(minNum);
		while (arr.size() < index) {
			minNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
			if (arr[p2] * 2 == minNum)p2++;
			if (arr[p3] * 3 == minNum)p3++;
			if (arr[p5] * 5 == minNum)p5++;
			arr.push_back(minNum);
		}
		return minNum;
	}
};