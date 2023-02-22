#include <stdio.h>
#include "QuickSort.h"

// 배열의 두 요소를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 퀵 정렬 함수
void quick_sort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    // pivot 설정
    int pivot = arr[(left + right) / 2];

    // 왼쪽과 오른쪽을 나누기 위한 인덱스 설정
    int i = left, j = right;

    // pivot을 기준으로 왼쪽에는 pivot보다 작은 값, 오른쪽에는 pivot보다 큰 값이 오도록 정렬
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // 왼쪽과 오른쪽에서 각각 퀵 정렬 수행
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}