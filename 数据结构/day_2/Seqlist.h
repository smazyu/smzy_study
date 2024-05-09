//
// Created by 20212 on 10/05/2024.
//
#pragma once
//顺序表，有效数据在数组中必须是连续的
typedef int SLDataType;
#define N 10
struct SeqList{
    SLDataType a[N];
    int size;
};
void SeqListPushBack(struct SeqList* ps ,SLDataType x);
void SeqListPopBack(struct SeqList* ps );
void SeqListPushFront(struct SeqList* ps ,SLDataType x);
void SeqListPopFront(struct SeqList* ps );