//
// Created by 20212 on 25/7/2024.
//
#include "sort.h"
void InsertSort(int* a,int n){
    assert(a);
    for (int i =0;i < n-1;++i){
        //所以 i应该 < n-1 因为，i < n - 1,它的边界即为n-2,end + 1，则为n - 1,不会产生越界
        //把end + 1往[0,end]区间插入保持它有序
        int end = i;
        int tmp = a[end +1];
        while(end >= 0){
            if(a[end] > tmp){
                a[end + 1] = a[end];
                --end;
            }else{
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

//希尔排序是对直接插入排序的优化