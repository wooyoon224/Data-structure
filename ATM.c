#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int P=0,t=0,sum=0, i, j;
    int time[1000];

    scanf("%d", &P);

    for(i=0;i<P;i++){
        scanf("%d", &time[i]);
    }

    //오름차순 정렬
    for(j=0;j<P;j++)
    {
        for(i=0;i<P-1;i++)
        {
            if(time[i]>time[i+1])   //앞에 있는 time이 뒷 time 보다 크다면
            {
                t=time[i];  //큰 앞쪽 time을 t에 임시저장
                time[i]=time[i+1];  //뒷쪽 time을 앞으로 저장
                time[i+1]=t;    //뒷쪽 time에 큰 수를 저장
            }
        }
    }

    //합산
    for(i=0;i<P;i++)
    {
        for(j=0;j<=i;j++)
        {
            sum=sum+time[j];    //time에 저장된 수를 모두 더한다.
        }
    }

    printf("%d",sum);
}