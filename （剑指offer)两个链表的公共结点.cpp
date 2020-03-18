#include<iostream>
#include<list>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		//ÆÕÍ¨½â·¨
		int lenth1 = getlenth(pHead1);
		int lenth2 = getlenth(pHead2);
		ListNode* cur2 = pHead2;
		ListNode* cur1 = pHead1;
		if (lenth1 > lenth2)
		{
			int differ = lenth1 - lenth2;
			while (differ > 0)
			{
				cur1 = cur1->next;
				differ--;
			}
		}
		else
		{
			int differ = lenth2 - lenth1;
			while (differ > 0)
			{
				cur2 = cur2->next;
				differ--;
			}
		}
		while (cur1 != NULL && cur2 != NULL)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	
};
static: int getlenth(ListNode* pHead)
{
	int count = 0;
	if (pHead == NULL)
	{
		return 0;
	}
	Listnode* cur = pHead;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}