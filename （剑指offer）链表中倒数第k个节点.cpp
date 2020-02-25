#if 0
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int count = 0;
		ListNode* head = pListHead;
		ListNode* cur = pListHead;
		while (cur != NULL)
		{
			cur = pListHead->next;
			pListHead = pListHead->next;
			count++;
		}
		int x = count - 1 - (k - 1);
		if (x >= 0)
		{
			for (int i = 0; i < x; i++)
			{
				head = head->next;
			}
			return head;
		}
		else { return NULL; }
	}
};
#endif