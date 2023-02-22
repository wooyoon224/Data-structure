#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

// 해시 테이블의 배열
htnode* hash_table[TABLE_SIZE] = { NULL, };

// 해시 함수: 10의 자리수를 반환한다
int hash_function(int data) {
    return data / 10;
}

// 연결 리스트에 데이터 삽입
void HT_insert(htnode** head, int data) {
    htnode* new_node = (htnode*)malloc(sizeof(htnode));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        htnode* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

// 해시 테이블에 데이터 삽입
void HT_add_data(int data) {
    if (data < 10 || data > 99) {
        printf("Error!\n");
        return;
    }

    int index = hash_function(data);
    HT_insert(&hash_table[index], data);
}

// 해시 테이블 출력
void print_HT() {
    for (int i = 1; i < 10; i++) {
        printf("%d | ", i);
        htnode* curr = hash_table[i];
        while (curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}