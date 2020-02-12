class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		if (number == 2)
		{
			return 2;
		}
		int a = 1;
		int b = 2;
		int c;
		for (int i = 0; i < number - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};