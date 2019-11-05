#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct stack {
    int array[100];
	int top;//栈顶
}Stack;
//支持动态增长的栈

void Stackinit(stack *s)
{
	s->top = 0;
}
void StackPush(Stack* s, int val) {
	s->array[s->top++];//压栈,尾插
}
//出栈
int StackPop(Stack* s) {
	assert(s->top > 0);
	return s->array[--s->top];
}
//查看栈顶元素
int StackTop(stack* s) {
	assert(s->top > 0);
	return s->array[s->top - 1];
}
//统计栈内元素
int StackSize(Stack* s) {
	return s->top;
}
//判断栈内是否为空
int StackIsEmpty(Stack* s) {
	return s->top == 0 ? 1 : 0;
}
//作业1）拿顺序表实现栈
//2)拿链表实现栈
//顺序表实现栈

//用顺序表实现栈
typedef struct Seqstack {
	int* array;//开辟动态指针的数组(int类型和类类型开辟的数组有什么区别？？）
	int size;
	int capacity;
}Seqstack;
//压栈
void SeqStackPush(Seqstack*s, int val) {
	//考虑扩容的问题
	if (s->size >= s->capacity) {
		int* newcapacity = (int*)malloc(sizeof(int)*s->capacity*2);
		for (int i = 0; i < s->size; i++) {
			newcapacity[i] = s->array[i];
		}
		free(s->array);
		s->array = newcapacity;
	}
	s->array[s->size] = val;
	s->size++;
}

//出栈
void SeqStackPop(Seqstack* s)//尾删
{
	assert(s->size != 0);
	s->array[s->size--];
}
//查看栈顶元素
int SeqStackTop(Seqstack* s) {
	//返回顺序表末尾
	assert(s->size != 0);
	return s->array[s->size - 1];
}
//统计栈内元素
int SeqStackSize(Seqstack* s) {
	return s->size;
}
//判断栈内是否为空
int SeqStackIsEmpty(Seqstack* s) {
	return s->size == 0 ? 1: 0;
}


//链表实现栈
//为了实现复杂度为O（1）并且方便的找到
//末尾元素所以用双向不带头不循环链表
typedef struct Stacklist {
	struct Stacklist* next;
	struct Stacklist* prev;
	int val;
}Stacklist;
//初始化
Stacklist* initial(Stacklist* s) {
	Stacklist* node = NULL;
	node->next = node;
}
//压栈
void Stacklistpush(Stacklist*s,int val){
  //尾插
	Stacklist* Node = (Stacklist*)malloc(sizeof(Stacklist));
	Node->val = val;
	if (s == NULL) {
		Node->next = s;
		s = Node;
	}
	else {
		while (s != NULL) {
			s = s->next;
		}
		Stacklist* last = s;
		last->next = Node;
	}
	Node->next = NULL;
}
//出栈
void Stacklistpush(Stacklist* s) {
	assert(s != NULL);
	while (s->next != NULL) {
		s = s->next;
	}
	free(s);
}
//查看栈顶元素
int Stacklisttop(Stacklist * s) {
	//返回顺序表末尾
	assert(s != NULL);
	while (s != NULL) {
		s = s->next;
	}
	return s->val;
}
