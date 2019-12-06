/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool JudgeAngle(int a,int b,int c)
{
	vector<int>v;
	v.resize(3);
	v[0]=a;
	v[1]=b;
	v[2]=c;
	sort(v.begin(),v.end());
	if(v[0]+v[1]>v[2]&&v[2]-v[0]<v[1])
	{
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	long double a,b,c;
	while(cin>>a>>b>>c)
	{
	   if(JudgeAngle(a,b,c))
	   {
		   cout<<"Yes"<<endl;
	   }
		else{cout<<"No"<<endl;}
	}
	return 0;
}
*/
#include <iostream>
using namespace std;

int main()
{
	long double a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (c + b > a))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

