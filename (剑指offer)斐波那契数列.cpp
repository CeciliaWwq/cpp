class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		int a = 1;
		int b = 1;
		int c;
		for (int i = 0; i < n - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};