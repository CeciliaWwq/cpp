#include"stack.h"
void StackInit(Stack* ps) {
	assert(ps);
	ps->_a = (STDataType*)calloc(N, sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = N;
}
void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->_a ) {
		ps->_top = 0;
		ps->_capacity = 0;
		free(ps->_a);
	}
}
void StackPush(Stack* ps, STDataType x) {
	assert(ps);
	if (ps->_top >= ps->_capacity) {
		ps->_capacity = ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	    ps->_a[ps->_top]=x;//ps->_top = x;
		ps->_top++;
	
}
void StackPop(Stack* ps) {
	assert(ps);
	if (ps->_top) {
		ps->_top--;
	}
}
STDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_a[ps->_top-1];
}
int StackEmpty(Stack* ps) {
	assert(ps);
	ps->_top == 0 ? 1 : 0;
}
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}
void StackPrint(Stack* ps) {
	assert(ps);
	for (int i = 0;i < ps->_top;i++) {
		printf("%d", ps->_a[i]);
	}
	putchar('\n');
}
#if 0
int main()
{
	Stack s;
	Stack* p = &s;
	StackInit(p);
	for (int i = 0; i < 20; ++i) {
		StackPush(p, i);
	}
	StackPrint(p);//´òÓ¡0¡ª¡ª19
	StackPush(p, 100);//0¡ª¡ª19£¬100
	StackPrint(p);
	StackPop(p);//0--19
	StackPrint(p);
	system("pause");
	return 0;
}

#endif
