#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE    1   //참은 1로 정의
#define FALSE   0   //거짓은 0으로 정의

typedef int data;

typedef struct menu
{
    data data;
    struct menu* nextP;
}menu;

typedef struct linkedList
{
    struct menu* head;
    struct menu* cur;
    struct menu* before;
    int num;
}List;

void ListInit(List* plist)  //초기화
{
    plist->head = (menu*)malloc(sizeof(menu));
    plist->head->nextP = NULL;  //head가 가리키는 것은 NULL로 초기화
    plist->num = 0; //노드의 수는 0으로 초기화
}

void Insert(List* list, data data)  //추가
{
    menu* newL = (menu*)malloc(sizeof(menu));   //새로운 리스트를 위해 자리를 확보
    newL->data = data;  //새로운 리스트가 가리키는 데이터에 받은 데이터 입력

    newL->nextP = list->head->nextP;    //새로운 리스트의 다음 포인터는 head의 다음 포인터이다
    list->head->nextP = newL;   //리스트에서 head의 다음 포인터가 새로운 리스트이다.

    (list->num)++;  //노드의 수 하나 증가
}

data remove(List* list, data ins)     //삭제
{
    menu* rpos; //임시로 값을 저장할 변수
    menu* cur = list->head; //cur은 head에서 출발

    while (cur->nextP != NULL)  //다음 포인터가 NULL이 아니라면
    {
        if (cur->nextP->data == ins)    //입력받은 수가 data로 있다면
        {
            rpos = cur->nextP;  //cur의 다음 포인터를 rpos에 임시 저장한다
            cur->nextP = cur->nextP->nextP; //cur의 다음 포인터를 삭제할 데이터의 다음 포인터로 바꾼다
            free(rpos); //노드를 삭제한다
            (list->num)--;  //노드의 수 감소
            return;
        }
        cur = cur->nextP;   //cur을 다음 포인터로 옮겨 반복한다
        
    }
}

int count(List* list)   //노드의 수
{
    return list->num;
}

void Listprint(List* list)
{
    menu* cur;

    cur = list->head->nextP;    //head가 가리키는 다음 데이터로 이동한다
    while (cur!=NULL)   //cur이 NULL이 아니라면
    {
        printf("%d ", cur->data);   //cur이 가리키는 데이터를 출력한다
        cur = cur->nextP;   //cur은 다음 포인터로 이동한다
    }
}

int main(void)
{
    int selectM=1;
    int insert;

    List list;
    ListInit(&list);
    while (selectM == 1||2||3)  //선택한 메뉴가 1 또는 2 또는 3 일때만 반복
    {
        printf("select menu (1:추가, 2:삭제, 3:노드의 수) : ");
        scanf("%d", &selectM);

        if (selectM == 1)   //추가
        {
            printf("insert : ");
            scanf("%d", &insert);
            Insert(&list, insert);  //입력받은 데이터를 리스트에 추가
        }

        else if (selectM == 2)  //삭제
        {
            printf("delete : ");
            scanf("%d", &insert);
            remove(&list, insert);  //입력받은 데이터에 맞는 노드를 찾아 삭제
        }

        else if (selectM == 3)  //노드의 수
        {
            printf("node num : %d\n", count(&list));    //count 함수에 저장된 노드의 수 출력
        }

        else 
            break;
        Listprint(&list);   //반복 마지막마다 현재 리스트를 출력한다.
        printf("\n");
    }
    return 0;
}