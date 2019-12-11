//井字棋
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkwin(vector<vector<int>> v, int row) {
		int sum = 0;
		//检查每行
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				sum += v[i][j];
			}
			if (sum == row) {
				return true;
			}
		}
		//检查每列
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				sum += v[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}
		//检查主对角线
		for (int i = 0; i < row; i++)
		{
			sum += v[i][i];
		}
		if (sum == row) { return true; }
		//检查副对角线
		for (int i = 0; i < row; i++)
		{
			sum += v[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		return false;
	}
};