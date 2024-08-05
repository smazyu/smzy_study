#include <stdio.h>
#include "stack.h"

// 已有的函数
void Swap(int *p1, int *p2);

int GetMidIndex(int a[], int begin, int end);

int PartSort3(int *a, int begin, int end);

void QuickSortNonR(int *a, int left, int right);

int main() {
    int array[] = {34, 7, 23, 32, 5, 62, 32, 2, 1, 74};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    QuickSortNonR(array, 0, size - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// 这里是已有的函数实现
void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int GetMidIndex(int a[], int begin, int end) {
    int mid = (begin + end) / 2;

    if (a[begin] < a[mid]) {
        if (a[mid] < a[end]) {
            return mid;
        } else if (a[begin] < a[end]) {
            return end;
        } else {
            return begin;
        }
    } else {
        if (a[mid] > a[end]) {
            return mid;
        } else if (a[begin] < a[end]) {
            return begin;
        } else {
            return end;
        }
    }
}

int PartSort3(int *a, int begin, int end) {
    int midIndex = GetMidIndex(a, begin, end);
    Swap(&a[midIndex], &a[end]);
    int key = a[end];
    int cur = begin;
    int prev = begin - 1;

    while (cur < end) {
        if (a[cur] < key) {
            prev++;
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[prev + 1], &a[end]);
    return prev + 1;  // Return the partition index
}

void QuickSortNonR(int *a, int left, int right) {
    Stack st;
    StackInit(&st);

    StackPush(&st, right);
    StackPush(&st, left);
    while (!StackEmpty(&st)) {
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);

        if (begin < end) {
            int div = PartSort3(a, begin, end);
            if (div + 1 < end) {
                StackPush(&st, end);
                StackPush(&st, div + 1);
            }
            if (begin < div - 1) {
                StackPush(&st, div - 1);
                StackPush(&st, begin);
            }
        }
    }
    StackDestory(&st);
}
//时间复杂度O（N*logN)
void MergeSort(int*a,int n){
    //使数组 1 3 5 6 2 5 7 8 9
    //归并排序的单趟排序
    //复杂度 O(N*logN)

}