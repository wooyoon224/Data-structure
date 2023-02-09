#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j=0, k=0, sum=0, result=0, temp =0;
    char math[51];
    int arr[25];

    scanf("%s",math);
    int len=strlen(math);

    for(i=0;i<=len;i++) //길이 만큼 반복
    {
        if(math[i]=='-'||i==len)    //-기호가 나왔거나 끝까지 갔을때
        {
            sum+=temp;   //temp를 sum에 추가
            arr[j]=sum; //sum을 arr에 저장
            j++;
            temp=0; //temp 초기화
            sum=0;  //sum 초기화
        }
        else if (math[i]=='+')  //+기호가 나온 경우
        {
            sum+=temp;  //sum에 temp추가
            temp=0;     //temp 초기화, sum저장 안함
        }
        else
        {
            temp=temp*10;
            temp=temp+math[i]-'0';
        }
        
    }

    //결과 합산
    result=arr[0];
    for(i=1;i<j;i++)
        result=result-arr[i];
    
    printf("%d",result);
}