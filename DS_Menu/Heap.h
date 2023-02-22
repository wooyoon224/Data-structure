#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE    1
#define FALSE   0

#define HEAP_LEN    100

int Heap[100];
int n;

void upHeap(int v);
void insertItem(int key);
void downHeap(int v);
int removeMax();
void printHeap();

#endif