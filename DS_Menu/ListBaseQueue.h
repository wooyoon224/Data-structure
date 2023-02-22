#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct node
{
	Data data;
	struct node* next;
} _Node;

typedef struct _lQueue
{
	_Node* front;
	_Node* rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);
void print_Queue(Queue* pq);

#endif