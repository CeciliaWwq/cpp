
#if 0
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* Head = new ListNode(0);
		Head->next = pHead;
		ListNode* pre = Head;
		ListNode* last = pHead;
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		while (last != NULL)
		{
			if (last->next != NULL && last->val == last->next->val)
			{
				while (last->next != NULL && last->val == last->next->val)
				{
					last = last->next;
				}
				pre->next = last->next;
				last = last->next;
			}
			else {
				last = last->next;
				pre = pre->next;
			}
		}
		return Head->next;
	}
};
#endif