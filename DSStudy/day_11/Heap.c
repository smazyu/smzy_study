//
// Created by 20212 on 2024/6/4.
//
#include "Heap.h"
void HeapInit(struct Heap* php,HPDataType* a,int n){
    php -> _a = (HPDataType*)malloc(sizeof(HPDataType)* n);
    memcpy(php -> _a,a,sizeof(HPDataType)*n);
    php -> _size = n;
    php -> _capacity = n;

    //构建堆
}
void HeapDestory(struct Heap *php);
void HeadPush(struct Heap* php,HPDataType x);
void HeadPop(struct Heap* php);
HPDataType HeapTop(struct Heap* php);