#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "ListBaseStack.h"
#include "ListBaseQueue.h"
#include "Heap.h"
#include "QuickSort.h"
#include "HashTable.h"



int main(void)
{
    int Input = 1, Input2 = 0;
    int i = 1, a = 0, Hroot = 0;
    
    ListStack s;
    StackInit(&s);
    Queue q;
    QueueInit(&q);
    

    while (Input == 1 || 2 || 3 || 4 || 5)
    {
        printf("Main Menu\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Heap\n");
        printf("4. Sort\n");
        printf("5. Hash Table\n");
        printf("Input : ");
        scanf("%d", &Input);
        printf("\n");

        int select = 0;
        Input2 = 0;

        switch (Input)
        {
        case 1:
            printf("1. Stack\n");
            printf("1. Pop, 2. Push, 3. Seek\n");
            scanf("%d", &select);
            printf("\n");
            if (select == 1)
            {
                printf("pop : %d\n",SPop(&s));
                break;
            }
            else if (select == 2)
            {
                printf("push 할 수 : ");
                scanf("%d", &Input2);
                printf("\n");
                SPush(&s,Input2);
                break;
            }
            else if (select == 3)
            {
                print_stack(&s);
                break;
            }
            else
                break;

        case 2:
            printf("2. Queue\n");
            printf("1. Pop, 2. Push, 3. Seek\n");
            scanf("%d", &select);
            if (select == 1)
            {
                printf("pop : %d\n", Dequeue(&q));
                break;
            }
            else if (select == 2)
            {
                printf("push 할 수 : ");
                scanf("%d", &Input2);
                printf("\n");
                Enqueue(&q, Input2);
                break;
            }
            else if (select == 3)
            {
                print_Queue(&q);
                break;
            }
            else
                break;

        case 3:
            printf("3. Heap\n");
            printf("1. Pop, 2. Push, 3. Seek\n");
            scanf("%d", &select);
            if (select == 1)
            {
                Hroot = removeMax();
                printf("%d\n", Hroot);
                break;
            }
            else if (select == 2)
            {
                printf("push 할 수 : ");
                scanf("%d", &Input2);
                printf("\n");
                insertItem(Input2);
                i++;
                break;
            }
            else if (select == 3)
            {
                printHeap();
                break;
            }
            else
                break;

        case 4:
            printf("4. Sort\n");
            printf("여러가지 자연수 입력(10개) : \n");
            int arr[10];
            int len = sizeof(arr) / sizeof(int);

            for(int j=0;j<len;j++)
                scanf("%d ", &arr[j]);
            
            quick_sort(arr, 0, len - 1);

            for (i = 0; i < len; i++)
            {
                printf("%d", arr[i]);
            }
            printf("\n");
            break;

        case 5:
            printf("5. Hash Table\n");
            printf("1. Insert, 2. Print\n");
            scanf("%d", &select);
            if (select == 1) 
            {
                printf("10 ~ 99까지의 수 입력 : \n");
                Input2 = 10;
                while (Input2 >= 10 && Input2 <= 99) {
                    scanf("%d", &Input2);
                    HT_add_data(Input2);
                }
                break;
            }
            else if (select == 2) 
            {
                print_HT();
                printf("\n");
                break;
            }
            else
                break;
        default:
            return 0;
        }
    }
}


