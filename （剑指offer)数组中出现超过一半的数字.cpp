class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		vector<int> ArrayNum;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			ArrayNum.push_back(numbers[i]);
		}
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			if (ArrayNum[i] == 0) {
				continue;
			}
			for (size_t j = i + 1; j < numbers.size(); j++)
			{
				if (ArrayNum[i] != ArrayNum[j] && ArrayNum[j] != 0)
				{
					ArrayNum[i] = 0;
					ArrayNum[j] = 0;
					break;
				}
			}
		}
		int result = 0;
		for (size_t i = 0; i < ArrayNum.size(); ++i)
		{
			if (ArrayNum[i] != 0)
			{
				result = ArrayNum[i];
			}
		}
		int count = 0;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == result)
			{
				count++;
			}
		}
		if (count * 2 <= numbers.size())
		{
			result = 0;
		}
		return result;
	}
};