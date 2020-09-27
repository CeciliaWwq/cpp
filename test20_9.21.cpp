#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
#if 0
// 1����ͷ�����ѭ��������ɾ���ʵ��
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plist) {
	assert(plist);
	plist->_head = nullptr;
}
void SListDestory(SList* plist) {
	assert(plist);
	SListNode* temp = nullptr;
	for (SListNode* cur = plist->_head;cur != nullptr;temp=cur)
	{
		temp = cur->_next;
		free(cur);
	}
}
SListNode* BuySListNode(SLTDataType x)//��ͷ�ڵ㸳һ��ֵ��������Ϊ�յ������
{
	SListNode* head = (SListNode*)malloc(sizeof(SListNode));
	head->_data = x;
	head->_next = nullptr;
	return head;
}
void SListPushFront(SList* plist, SLTDataType x) {
	/*
	assert(plist);
	SListNode* node=(SListNode*)malloc(sizeof(SListNode));
	node->_data = x;//plist->_head=BuySListNode��x��
	node->_next = plist->_head;
	plist->_head = node;
	*/
	   // assert(plist);
		if (plist->_head == nullptr) {
			plist->_head = BuySListNode(x);
		}
		else {
			SListNode* temp = plist->_head;
			plist->_head = BuySListNode(x);
			plist->_head->_next = temp;
		}

}
void SListPopFront(SList* plist) {
	assert(plist);
	assert(plist->_head != nullptr);
	SListNode *cur=plist->_head;
	plist->_head = cur->_next;
	free(cur);
	cur = nullptr;
}
SListNode* SListFind(SList* plist, SLTDataType x)
// ��pos�ĺ�����в���
{
	assert(plist);
	SListNode* cur = plist->_head;
	for(;cur!=nullptr;cur=cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
}
void SListInsertAfter(SListNode* pos, SLTDataType x)
// ��pos��ǰ����в���
{
	/*
	SList* plist;
	SListNode* cur = plist->_head;
	SListNode* pre = plist->_head;
	for (pre=cur;cur != nullptr;cur = cur->_next)
	{
		if (cur== pos)
		{
			SListNode* node = (SListNode*)malloc(sizeof(SListNode));
			node->_data = x;
			node->_next = cur;
			pre->_next = node;
			break;
		}
	}*/
	SListNode* temp = pos->_next;
	pos->_next = BuySListNode(x);
	pos->_next->_next = temp;
}
void SListEraseAfter(SListNode* pos) {
	SListNode* temp;
	temp = pos->_next;
	pos->_next = pos->_next->_next;
}
void SListRemove(SList* plist, SLTDataType x) {//ɾ���ڵ�ֵΪx�Ľڵ�
	assert(plist);
	SListNode* prev = plist->_head;
	for (SListNode* cur = plist->_head;cur->_next != nullptr;cur = cur->_next) {
		if (cur->_data == x) {
			//���ͷ�ڵ����x
			if (prev->_data == x) {
				prev = plist->_head->_next;
				cur= plist->_head->_next;
			}
			else {
				prev->_next = cur->_next;
				cur = prev->_next;
			}
		}
		else { prev = cur; }
	}

}
void SListPrint(SList* plist) {
	assert(plist);
	for (SListNode* cur = plist->_head;cur != nullptr;cur = cur->_next)
	{
		cout << cur->_data;
	}
}
void SListPushBack(SList* list, SLTDataType x) {//β��
	assert(list);
	SListNode* cur = list->_head;
	while(cur->_next != nullptr)
	{
		cur = cur->_next;
	}
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->_data = x;
	cur->_next = node;
	node->_next = nullptr;
}
void SListPopBack(SList*list)
{
	assert(list);
	SListNode* cur = list->_head;
	while (cur->_next->_next!= nullptr)
	{
		cur = cur->_next;
	}
	free(cur->_next);
	cur->_next = nullptr;
}
void TestSList(SList*list) {
	SListPushFront(list, 5);
	SListPushFront(list, 4);
	SListPushFront(list, 3);
	SListPushFront(list, 2);
	SListPushFront(list, 1);

	SListPrint(list);//12345

	SListPushBack(list, 6);
	SListPushBack(list, 7);
	SListPushBack(list, 8);
	SListPushBack(list, 9);
	SListPushBack(list, 10);

	SListPrint(list);//12345678910

	SListPopBack(list);
	SListPopBack(list);
	SListPopBack(list);

	SListPrint(list);//1234567

	SListPopFront(list);
	SListPopFront(list);
	SListPopFront(list);

	SListPrint(list);//4567

	printf("%p\n", list->_head->_next);
	SListNode* cur = SListFind(list, 5);
	printf("%p\n", cur);


	SListInsertAfter(cur, 0);
	SListPrint(list);
	SListEraseAfter(cur);
	SListPrint(list);//3567

	SListPushFront(list, 3);
	SListPushFront(list, 2);
	SListPushFront(list, 3);
	SListPrint(list); //3234567

	SListRemove(list, 3);
	SListPrint(list);//24567


}
int main()
{
	SList list;
	//SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	//cur->_data = 1;

	SListInit(&list);
	TestSList(&list);
	system("pause");
	return 0;
}
#endif

// 2����ͷ˫��ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
void ListInit(List* plist) {
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist) {
	if (plist->_head->_next = plist->_head) {
		return;
	}
	else {
		ListNode* cur;
		cur = plist->_head->_next;
		while (cur!= plist->_head) {
			ListNode* temp = cur->_next;
			free(cur);
			cur = temp;
		}
	}
	free(plist->_head);
	plist->_head = nullptr;
}
ListNode* CreateNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = nullptr;
	node->_prev = nullptr;
	return node;
}
void ListPushBack(List* plist, LTDataType x){//β��
	ListNode* node = CreateNode(x);
	plist->_head->_prev->_next = node;
	node->_prev = plist->_head->_prev;
	plist->_head->_prev = node;
	node->_next = plist->_head;

}
void ListPopBack(List* plist) {//βɾ
	if (plist->_head->_next == plist->_head) {
		return;
	}
	else {
		ListNode* cur = plist->_head->_prev;//Ϊ8
		ListNode* temp = cur->_prev;
		temp->_next = plist->_head;
		plist->_head->_prev = temp;
		free(cur);
		cur = nullptr;//��һ��plist=198->��ȷ
	}
}
void ListPushFront(List* plist, LTDataType x) {//ͷ��
	ListNode* node = CreateNode(x);
	node->_next=plist->_head->_next;
	plist->_head->_next->_prev = node;
	node->_prev = plist->_head;
	plist->_head->_next = node;
}
void ListPopFront(List* plist){//ͷɾ
	if (plist->_head->_next == plist->_head)
	{
		return;
	}
	else {
		ListNode* cur = plist->_head->_next;
		ListNode* temp = cur->_next;
		plist->_head->_next = temp;
		temp->_prev = plist->_head;
	}
}
ListNode* ListFind(List* plist, LTDataType x) {
	if (plist->_head->_next ==plist->_head) {
		return nullptr;
	}
	else {
		ListNode* cur = plist->_head->_next;
		while (cur != plist->_head) {
			if (cur->_data == x) {
				return cur;
				break;
			}
			cur = cur->_next;
		}
	}
	return nullptr;
}
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* cur = CreateNode(x);
	cur->_prev = pos->_prev;
	pos->_prev->_next = cur;
	cur->_next =pos;
	pos->_prev = cur;
}
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {//ɾ��
	if (pos->_next == pos)
	{
		return;
	}
	ListNode* cur = pos->_prev;
	pos->_next->_prev = cur;
	cur->_next = pos->_next;
	free(pos);

}
void ListRemove(List* plist, LTDataType x) {//ɾ��ֵΪx�Ľڵ�
	if (plist->_head->_next == plist->_head) { return; }
	else {
		ListNode* prev = plist->_head->_next;
		ListNode* cur = plist->_head->_next;
		//ͷ�ڵ����x�����
		while (cur!=plist->_head)
		{
			if (cur->_data == x) {
				plist->_head->_next = cur->_next;
				cur->_next->_prev = plist->_head;
				cur = plist->_head->_next;
			}
			//����ͷ�ڵ����x�����
			else {
				for (;cur != plist->_head;cur = cur->_next)
				{
					if (cur->_data == x) {
						prev->_next = cur->_next;
						cur->_next->_prev = prev;
						cur = prev->_next;
					}
					prev = cur;
				}
			}
		}
	}
}
void ListPrint(List* plist) {//��ӡ
	if (plist->_head->_next == plist->_head) {
		//˵������Ϊ��
		printf("����Ϊ��, ��ӡʧ��!\n");
		return;
	}
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 9);
	ListPushBack(&list, 8);
	ListPushBack(&list, 8);
	ListPrint(&list);//β��->1 9 8 8

	ListPopBack(&list);
	ListPrint(&list);//βɾ->1 9 8

	ListPushFront(&list, 2);
	ListPrint(&list);//ͷ��->2 1 9 8

	ListPopFront(&list);
	ListPrint(&list);//ͷɾ->1 9 8

	ListNode* cur = ListFind(&list,9);
	ListInsert(cur, 7);//��cur��9��ǰ����7->1 7 9 8
	ListPrint(&list);

	ListNode* cur2 = ListFind(&list, 7);
	ListErase(cur2);
	ListPrint(&list);//ɾ���ڵ�Ϊ7�Ľڵ�->1 9 8

	ListRemove(&list, 9);
	ListPrint(&list);//ɾ����ֵΪ9�Ľڵ�->1 8
}
