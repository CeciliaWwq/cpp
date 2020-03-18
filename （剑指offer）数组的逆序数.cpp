class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size();
		if (length <= 0)
			return 0;
		vector<int>copy;
		for (size_t i = 0; i < data.size(); i++)
		{
			copy.push_back(data[i]);
		}
		long long count = countInvert(data, copy, 0, data.size() - 1);
		return count % 1000000007;
	}
	long long countInvert(vector<int>& data, vector<int>& copy, int start, int end)
	{
		if (start == end)
		{
			copy[start] = data[start];
			return 0;
		}
		int mid = (end - start) / 2;
		long long leftCount = countInvert(copy, data, start, start + mid);
		long long rightCount = countInvert(copy, data, start + mid + 1, end);
		int lefEnd = start + mid;
		int rigEnd = end;
		int copyEnd = end;
		long long count = 0;
		while (lefEnd >= start && rigEnd >= start + mid + 1)
		{
			if (data[lefEnd] > data[rigEnd]) {
				copy[copyEnd--] = data[lefEnd--];
				count = count + rigEnd - start - mid;
			}
			else
			{
				copy[copyEnd--] = data[rigEnd--];
			}
		}
		for (; lefEnd >= start; lefEnd--)
		{
			copy[copyEnd--] = data[lefEnd];
		}
		for (; rigEnd >= start + mid + 1; rigEnd--)
		{
			copy[copyEnd--] = data[rigEnd];
		}
		return count + leftCount + rightCount;
	}
};