#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
// 1、无头单向非循环链表增删查改实现
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
SListNode* BuySListNode(SLTDataType x)//给头节点赋一个值，在链表为空的情况下
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
	node->_data = x;//plist->_head=BuySListNode（x）
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
// 在pos的后面进行插入
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
// 在pos的前面进行插入
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
void SListRemove(SList* plist, SLTDataType x) {//删除节点值为x的节点
	assert(plist);
	SListNode* prev = plist->_head;
	for (SListNode* cur = plist->_head;cur->_next != nullptr;cur = cur->_next) {
		if (cur->_data == x) {
			//如果头节点就是x
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
void SListPushBack(SList* list, SLTDataType x) {//尾插
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

/*
// 2、带头双向循环链表增删查改实现
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
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);
*/