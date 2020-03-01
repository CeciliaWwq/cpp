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
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* next = NULL;
		ListNode* prev = NULL;
		ListNode* cur = pHead;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};
#endif