#if 0
#include<iostream>
#include<list>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* cur2 = pHead2;
		ListNode* cur1 = pHead1;
		ListNode* prev=pHead1;
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		while (cur1 != NULL)
		{
			prev = cur1;
			cur1 = cur1->next;
			if (cur2->val < prev->val)
			{
				ListNode* node1 = cur2;
				node1->next = prev;
				if (cur2->next != NULL)
					cur2 = cur2->next;
			}
			if (cur2->val >= prev->val && cur2->val <= cur1->val)
			{
				ListNode* node2 = cur2;
				prev->next = node2;
				node2->next = cur1;
				if (cur2->next != NULL)
					cur2 = cur2->next;
			}
			//else{//cur1.val<cur2.val}
		}
		while (cur2 != NULL)
		{
			cur1->next = cur2;
			cur2 = cur2->next;
		}
		return pHead1;
	}
};
int main()
{
	ListNode* l1;
	ListNode* l2;
	ListNode* l3;
	l1->val=1;
	l1->next->val=3;
	l1->next->next->val = 5;
	l2->val = 2;
	l2->next->val = 4;
	l2->next->next->val = 6;
	
}
#endif
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

#if 0
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{

		ListNode* node = new ListNode(0);
		ListNode* head = node;
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				head->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				head->next = pHead2;
				pHead2 = pHead2->next;
			}
			head = head->next;
		}
		if (pHead2 != NULL)
		{
			head->next = pHead2;
		}
		if (pHead1 != NULL)
		{
			head->next = pHead1;
		}
		return node->next;
	}
};
#endif