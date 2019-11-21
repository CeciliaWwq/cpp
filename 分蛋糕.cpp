//解题关键：
//((x1 - x2)* (x1 - x2) + (y1 - y2) * (y1 - y2)) == 4看起来是一个无解的表达式。
//1 + 3 = 4 3 + 1 = 4
//2 + 2 = 4 0 + 4 = 4
//4 + 0 = 4 仔细分析前三个表达式是不可能的，因为(x1 - x2) * (x1 - x2)表达式结果不能等于2或3。 
//也就是说((x1 - x2) * (x1 - x2) 和(y1 - y2) * (y1 - y2))两个表达式一个等于0，一个等于4.
//可以看出：假设放蛋糕的位置是(x1, y1)，则不能放蛋糕的位置(x2, y2)，
//满足x1 == x2, y1 - y2 == 2或者x1x2 == 2, y1 == y2.

//a[i][j]位置放蛋糕，则可以标记处a[i][j+2]和a[i+1][j]位置 不能放蛋糕，
//遍历一遍二维数组，标记处不能放蛋糕的位置，统计也就统计出了当蛋糕的位置数

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w = 0, h = 0;
	cin >> w >> h;
	vector<vector<int>>v;
	v.resize(w);
	int res = 0;
	for (auto& e : v)
	{
		e.resize(h, 1);
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (v[i][j] == 1)
			{
				res++;
				if (i + 2 < w)
				{
					v[i + 2][j] = 0;
				}
				if (j + 2 < h)
				{
					v[i][j + 2] = 0;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}