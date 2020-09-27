#include"queue.h"

void QueueInit(Queue* pq) {
	assert(pq);
	//pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
	//pq->_rear = (QueueNode*)malloc(sizeof(QueueNode));
	pq->_front = pq->_rear = NULL;
}
void QueueDestory(Queue* pq) {
	assert(pq);
	while (pq->_front != pq->_rear) {
		QueueNode* temp = pq->_front;
		pq->_front = pq->_front->_next;
		free(temp);
	}
}
QueueNode* BuyQueueNode(QUDataType x) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	return node;
}
void QueuePush(Queue* pq, QUDataType x) {
	assert(pq);
	if (pq->_front == NULL) {
		pq->_front = pq->_rear = BuyQueueNode(x);
	}
	else {
		pq->_rear->_next = BuyQueueNode(x);//对空指针解引用了!
		pq->_rear = pq->_rear->_next;
	}
	pq->_rear->_next = NULL;
}
void QueuePop(Queue* pq) {
	assert(pq);
	//pq->_front = pq->_front->_next;没有释放资源，内存泄漏
	QueueNode* tmp;
	tmp = pq->_front;
	pq->_front = tmp->_next;
	free(tmp);
}
QUDataType QueueFront(Queue* pq) {
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq) {
	assert(pq);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq) {
	assert(pq);
	return (pq->_front == pq->_rear) && (pq->_front->_data == 0) ? 1 : 0;
}
int QueueSize(Queue* pq) {
	assert(pq);
	int count = 0;
	while (pq->_front != pq->_rear) {
		pq->_front = pq->_front->_next;
		count++;
	}
	return count;
}
void QueuePrint(Queue* pq) {
	assert(pq);
	for (QueueNode* cur = pq->_front; cur; cur = cur->_next) {
		printf("%d ", cur->_data);
		if (cur == pq->_rear) {
			break;
		}
	}
	putchar('\n');
}
int main() {

	Queue test;
	QueueInit(&test);
	for (int i = 1; i <= 10; ++i) {
		QueuePush(&test, i);
	}
	QueuePrint(&test);//1--10
	QueuePop(&test);
	QueuePrint(&test);//2--10
	printf("%d\n", QueueFront(&test));//2
	printf("%d\n", QueueBack(&test));//10
	printf("%d\n", QueueSize(&test));//8
	system("pause");
	return 0;
}