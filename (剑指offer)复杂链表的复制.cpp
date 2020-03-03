/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		//复制原链表
		//复制原链表的random值
		//拆分链表
		if (pHead == NULL) return NULL;
		RandomListNode* cur = pHead;
		while (cur != NULL)
		{
			RandomListNode* node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}
		cur = pHead;
		while (cur != NULL)
		{
			if (cur->random != NULL)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		RandomListNode* head = pHead->next;
		cur = pHead;
		RandomListNode* pcur = head;
		while (pcur != NULL)
		{
			cur->next = cur->next->next;
			if (pcur->next != NULL)
				pcur->next = pcur->next->next;
			cur = cur->next;
			pcur = pcur->next;
		}
		return head;
	}
};