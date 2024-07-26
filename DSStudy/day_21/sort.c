//
// Created by 20212 on 25/7/2024.
//
#include "sort.h"

void InsertSort(int *a, int n) {
    assert(a);
    for (int i = 0; i < n - 1; ++i) {
        //所以 i应该 < n-1 因为，i < n - 1,它的边界即为n-2,end + 1，则为n - 1,不会产生越界
        //把end + 1往[0,end]区间插入保持它有序
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0) {
            if (a[end] > tmp) {
                a[end + 1] = a[end];
                --end;
            } else {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int *a, int n) {
    int gap = n;
    //1.gap>1相当于预排序
    //2.gap == 1相当于直接插入排序
    while (gap > 1) {
        gap = gap / 3 + 1;//+1保证最后一次gap一定是1
        //gap == 1最后一次相当于直接插入排序
        for (int i = 0; i < n - gap; ++i) {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0) {
                if (a[end] > tmp) {
                    a[end + gap] = a[end];
                    end -= gap;
                } else {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

//希尔排序是对直接插入排序的优化
//直接插入排序，时间复杂度是 O(n^2) 单趟插入是 O(n)
//空间复杂度O(1)
//什么情况下最好?什么情况下最坏?
//顺序有序最好
//逆序最坏

//希尔排序，又叫缩小量排序

//插入排序 1.预排序(让数组接近有序) 2.直接插入排序
//1.预排序 把间距为gap的值分为一组，进行插入排序
//gap越大，前面大的数可以越快到后面，后面小的数可以越快到前面，但是gap越大，越不接近有序，gap越小越接近有序，如果gap=1，其实就相当于直接插入排序，就有序了
//gap > 1预排序
//gap = 1 直接插入排序