#if 0
#include<iostream>
using namespace std;
int JudgeYear(int year)
{
	if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
	{
		return 1;
	}
	else { return 0; }
}

int JudgeDay(int year, int month)
{
	if (JudgeYear(year) == 0)
	{
		int array[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return array[month];
	}
	else
	{
		int array1[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
		return array1[month];
	}

}

bool ifqualify(int year, int month, int day)
{
	if (month > 12 || month < 0) { return false; }
	if (day>JudgeDay(year, month)||day<0) { return false; }
	else return true;

}
int JudgeDAYofYear(int year, int month, int day)
{
	int ADD = 0;
	for (int i = 0; i < month; i++)
	{
		ADD += JudgeDay(year, i);
	}
	ADD += day;
	return ADD;
}

int main()
{
	int year;
	int month;
	int day;
	while (cin >> year >> month >> day)
	{
		if (!ifqualify(year, month, day))
		{
			return -1;
		}
		int count = JudgeDAYofYear(year, month, day);
		cout << count << endl;
	}
	return 0;
}
# endif
