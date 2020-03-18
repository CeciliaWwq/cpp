class Solution {
public:
	int BinarySearch(vector<int>arr, int low, int high, int k)
	{
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (arr[mid] == k)return mid;
			else if (arr[mid] > k) high = mid - 1;
			else low = mid + 1;
		}
		return -1;
	}
	int GetNumberOfK(vector<int> data, int k) {
		//思路：用二分查找找到k
		//然后对原数组中k所在的位置对数组中K个数统记
		int high = data.size() - 1;
		int keyindex = BinarySearch(data, 0, high, k);
		if (keyindex == -1)return 0;
		int lower = keyindex - 1;
		int higher = keyindex + 1;
		int sum = 1;
		while (lower >= 0 && data[lower] == k)
		{
			lower--;
			sum++;
		}
		while (higher <= high && data[higher] == k)
		{
			higher++;
			sum++;
		}
		return sum;
	}
};