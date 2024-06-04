//
// Created by 20212 on 2024/6/4.
//

#pragma once
typedef int HPDataType;
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
struct Heap{
    HPDataType *_a;
    int _size;
    int _capacity;
}Heap;
void HeapInit(struct Heap* php,HPDataType* a,int n);
void HeapDestory(struct Heap *php);
void AdustDown(HPDataType *a,int n,int root);
void HeadPush(struct Heap* php,HPDataType x);
void HeadPop(struct Heap* php);
HPDataType HeapTop(struct Heap* php);
