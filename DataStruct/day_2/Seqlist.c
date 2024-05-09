//
// Created by 20212 on 10/05/2024.
//
#include "Seqlist.h"
void SeqListInit(SL*s){
    /* s.size = 0;
    s.a = NULL;
    s.capacity = 0; */
    s -> a =(SLDataType*)malloc(sizeof(SLDataType)*4);
    if(s -> a == NULL){
        printf("false\n");
        exit(-1);
    }
    s -> size = 0;
    s -> capacity = 4;
}
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps ,SLDataType x);//尾插
void SeqListPopBack(SL* ps );//尾删

void SeqListPushFront(SL* ps ,SLDataType x);//头插
void SeqListPopFront(SL* ps );//头删

void SeqListInsert(SL* ps,int pos,SLDataType x);//任意地方插入
void SeqListErase(SL* ps,int pos);//任意位置删除