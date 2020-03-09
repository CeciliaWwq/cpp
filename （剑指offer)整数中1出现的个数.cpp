class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int ones = 0;
		for (long long m = 1; m <= n; m *= 10)
		{
			int a = n / m, b = n % m;
			if (a % 10 == 0)
				ones += a / 10 * m;
			else if (a % 10 == 1)
				ones += (a / 10 * m) + (b + 1);
			else
				ones += (a / 10 + 1) * m;
		}
		return ones;
	}
};