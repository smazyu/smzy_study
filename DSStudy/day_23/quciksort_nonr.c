//
// Created by 20212 on 5/8/2024.
//
#include "stack.h"

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

void PartSort3(int *a, int begin, int end) {
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
}

void QuickSortNonR(int *a, int left, int right) {
    //栈模拟实现
    //递归存在栈溢出风险
    //采用非递归

    //非递归 :1.提高效率(递归建立栈帧还是有消耗的，但是对于现代的计算机，这个优化微乎其微)
    //      2.递归的最大缺陷是，如果栈帧的深度太深，可能会导致栈溢出。因为系统的栈，一般空间不大，在M级别
    //    栈模拟非递归，数据是存储在堆上的，堆是G级别的空间
    Stack st;
    StackInit(&st);

    StackPush(&st, right);
    StackPush(&st, left);
    while (!StackEmpty(&st)) {
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);

        //[begin,end]
        int div = PartSort3(a, begin, right);
        //[begin,div-1] div [div + 1,end]
        if (div + 1 < end) {
            StackPush(&st, end);
            StackPush(&st, div + 1);
        }
        if (begin < div - 1) {
            StackPush(&st, div - 1);
            StackPush(&st, begin);
        }
        //只是将递归操作换成栈模拟
        //递归改非递归 --1.改循环(斐波那契额数列求解) 一些简单的处理递归才能改循环 2.栈模拟存储数据非递归
    }
    StackDestory(&st);
};