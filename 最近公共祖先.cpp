//所以如果a ！ = b，就让其中的较大数除以2， 如此循环直到a == b
//即是原来两个数的最近公共祖先
#include<iostream>
using namespace std;
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a == b) { return a; }
		else {
			while (a != b)
			{
				if (a > b) { a = a / 2; }
				else { b = b / 2; }

			}
			return b;
		}
	}

};//非递归
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a == b) { return b; }
		else {
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			return getLCA(a / 2, b);
		}
	}

};//递归