class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int a = 0;
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		for (size_t i = 1; i < rotateArray.size(); i++)
		{
			if (rotateArray[i - 1] > rotateArray[i])
			{
				a = rotateArray[i];
				break;
			}
		}
		return a;
	}
};