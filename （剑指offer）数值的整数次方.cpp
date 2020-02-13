class Solution {
public:
	double Power(double base, int exponent) {
		double res = 1;
		double curr = base;
		int n;
		if (exponent > 0)
		{
			n = exponent;
		}
		else if (exponent < 0)
		{
			if (base == 0)
			{
				return 0;
			}
			n = -exponent;
		}
		else {//exponent为0的情况
			return 1;
		}
		while (n != 0)
		{
			if ((n & 1) == 1)
				res *= curr;
			curr *= curr;
			n >>= 1;
		}
		return exponent >= 0 ? res : (1 / res);
	}
};