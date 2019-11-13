//11.6

//输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)

//第二行包括3* n个整数a_i(1 ≤ a_i ≤ 10 ^ 9), 表示每个参赛选手的水平值
//题目描述输出已排序数列组（3位一组）的中间值之和，并使其最大
//难点：搞清楚数组元素的下标和找规律后的数的个数的关系，找到规律比光想解决问题的方法好的多
//误区：光想着如何分组了，太过于步骤化太死板，没有找规律
#include<iostream>
#include<vector>
#include<algorithm> 
#include<string>

using namespace std;
#if 0
int main()
{
	long long sum = 0;
	vector<int>a;
	int n;
	while (cin >> n) {
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
#endif



#if 0
class FindSecondMax {
	int Solution(int x, vector<int> v)
	{
		int temp = 0;
		int sz = v.size();
		for (int i = 0; i < x; i++)
		{
			for (int j = 1; j < x - i - 1; j++) {
				if (v[j] < v[i])
				{
					temp = v[j];
					v[j] = v[i];
					v[i] = temp;
				}
			}
		}
		int k = 0;
		int count = 0;
		while (k < x) {
			count += v[(sz - k) / 2];
			k++;
		}
	}
};
#endif


//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
#if 0
string Solution() {
	string str1, str2;
	getline(cin, str1);
	int sz1 = str1.size();
	getline(cin, str2);
	int sz2 = str2.size();
	int hasharray[256];
	for (int i=0; i < sz2; i++) {
		hasharray[str2[i]]++;
	}
	string ret;
	for (int j = 0; j < sz1; j++) {
		if (hasharray[str1[j]] ==0) {
			ret += str1[j];
		}
	}
	return ret;
}
#endif

//11.7
//输出一串数字的最小非递增或非递减数列的最小个数
#include<iostream>
#include<vector>
using namespace std;
int main() {

	//int n = 0;
	//cin >> n;
	int array[9] = { 1,2,1,2,1,2,1,2,1 };
	int n = 9;
	int i = 0;
	int count = 0;
	vector<int>v(array, array + sizeof(array) / sizeof(int));
	v.resize(n + 1);
	int j = 0;
	/*
	for (int j = 0; j < n; j++) {
		cin >> v[j];
	}
	*/
	while (i < n) {
		//判断是非递增数列
		if (v[i] > v[i + 1]) {
			while (i < n && v[i] >= v[i + 1]) { i++; }
			count++;
			i++;
		}
		if (v[i] == v[i + 1]) {
			i++;
		}
		else {
			//判断是非递减数列
			while (i < n && v[i] <= v[i + 1]) { i++; }
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int n = 0;
	cin >> n;
	int i = 0;
	int count = 0;
	 v.resize(n+1);
  //v[n]=0;
	int j=0;
	for(int j=0;j<n;j++){
		cin>>v[j];
	}
	while (i < n) {
		//判断是非递增数列
		if (v[i] > v[i + 1]) {
			while (i < n && v[i] >= v[i + 1]) { i++; }
			count++;
			i++;
		}
		else if (v[i] == v[i + 1]) {
			i++;
		}
		else {
			//判断是非递减数列
			while (i < n && v[i] <= v[i + 1]) { i++; }
			count++;
			i++;
		}
	}
	cout<<count<<endl;
	return 0;
}
*/

//倒置字符串
//输入：I Like Beijing.
//输出：Beijing. Like I
int main() {
	string s1, s2;
	cin >> s1;
	while (cin >> s2) {
		s1 = s2 + " " + s1;
	}
	cout << s1 << endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int i = 1;
	string s1;
	cin >> s1;
	int len = s1.size();
	int count = s1[0] - 'a';
	int count2 = 0;
	int cflag = 1;
	int flag = 1;
	string s;
	while (cin >> s)
	{
		int len2 = s.size();
		if (len > len2) {
			cflag = 0;
		}
		size_t sz = s1.size() < s.size() ? s1.size() : s.size();
		for (int i = 0; i < sz; i++) {
			count2 = s[i] - 'a';
			count = s1[i] - 'a';
			if (count > count2)
			{
				flag = 0;
				break;
			}
		}
		s1 = s;
		len = s1.size();
	}
	if (flag == 0 && cflag == 0) { cout << "none" << endl; }
	if (flag == 1 && cflag == 1) { cout << "both" << endl; }
	if (flag == 1 && cflag == 0) { cout << "lexicographically" << endl; }
	if (flag == 0 && cflag == 1) { cout << "lengths" << endl; }


}