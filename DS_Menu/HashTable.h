#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#define TABLE_SIZE 90 // 10의 자리수가 9개이므로 9 * 10 = 90

// 연결 리스트의 노드 구조체
typedef struct HTNode {
    int data;
    struct HTNode* next;
} htnode;

int hash_function(int data);
void HT_insert(htnode** head, int data);
void HT_add_data(int data);
void print_HT();

#endif