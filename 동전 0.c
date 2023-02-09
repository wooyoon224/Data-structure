#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int N, K, i, c=0;   //N은 동전의 종류, K는 총합, c는 동전 갯수
    int arr[10];    //N은 최대 10

    scanf("%d %d",&N, &K);  //첫줄에 N과 K입력

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }   //동전 종류
    i=N-1;  //Ai는 Ai-1의 배수

    while(K>0){
        if(arr[i]>K){
            i--;
        }
        else{
            K=K-arr[i];
            c++;
        }
    }

    printf("%d", c);
}




