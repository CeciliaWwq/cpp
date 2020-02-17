#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <functional>
#include<map>
#include<queue>
using namespace std;

#if 0
//方法一：利用vector中的sort排序,在用opertor[]
//因为map中的键值对的key是有序的，sort是无序的，sort可以排vector,deque(不推荐)why,数组
bool cmp(pair<string, int>a, pair<string, int>b)
{
	return a.second > b.second;
}
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	map<string, int>mp;
	for (size_t i = 0; i < fruits.size(); i++)
	{
		// 1.统计出水果出现次数
		mp[fruits[i]]++;
	}
	// 2.找出大家最喜欢吃的水果
	vector < pair<string, int> >a(mp.begin(),mp.end());
	sort(a.begin(),a.end(),cmp);
	for (size_t j = 0; j < k; j++)
	{
		cout << a[j].first <<":"<<a[j].second<< endl;
	}
}

int main()
{
	vector<string> v = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓", "西瓜", "榴莲", "榴莲", "火龙果","火龙果", "火龙果" };
	GetFavoriteFruit(v, 3);
	return 0;
}
#endif

#if 0
//方法二：利用map中find的特性，返回的是迭代器中键值对的value值+优先级队列
struct Count_compare {
	bool operator()(const pair<string, int>& l, const pair<string, int>& v) {
		return l.second < v.second;
	}
};

void GetFavoriteFruit2(const vector<string>& fruits, size_t k)
{
	map<string, int>mp;
	for (auto& e : fruits)
	{
		//map<string, int>::iterator ret = mp.find(e);
		auto ret = mp.find(e);
		if (ret != mp.end())
		{
			ret->second++;
		}
		else {
			mp.insert(pair<string, int>(e, 1));
		}
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Count_compare>pq;
	size_t i = 0;
	for (auto& e : mp) {
		if (i < k) {
			pq.push(e);
		}
		else {
			if (e.second > pq.top().second) {
				pq.pop();
				pq.push(e);
			}
		}
	}
	
}
int main()
{
	vector<string> v = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓", "西瓜", "榴莲", "榴莲", "火龙果","火龙果", "火龙果" };
	GetFavoriteFruit2(v, 3);
	return 0;
}
#endif

#if 0
//方法三：operator[]+反向迭代器
void GetFavoriteFruit3(const vector<string>& fruits, size_t k) {
	map<string, int>mp;
	for (auto& e : fruits)
	{
		mp[e]++;
	}
	multimap<int, string, greater<int>>sortmap;//这里用multimap的原因是颠倒键值对后的value值可能存在重复
	for(const auto&e:mp)
	{
		sortmap.insert(make_pair(e.second, e.first));
	}
	vector<pair<int, string>>a(sortmap.begin(), sortmap.end());
	for (auto& e : a) {
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	vector<string> v = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓", "西瓜", "榴莲", "榴莲", "火龙果","火龙果", "火龙果" };
	GetFavoriteFruit3(v, 3);
	return 0;
}
#endif
