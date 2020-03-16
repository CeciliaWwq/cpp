#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int n;
	while (scanf("%u", &n) != EOF)
	{
		printf("%u =", n);
		for (unsigned int i = 2; i <= sqrt(n); i++)
		{
			while (n % i == 0 && n != i)
			{
				printf(" %u *", i);
				n /= i;
			}
			if (n == i)
			{
				break;
			}
		}
		printf(" %d\n", n);
	}
	return 0;
}
