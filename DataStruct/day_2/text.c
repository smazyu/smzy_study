//
// Created by 20212 on 10/05/2024.
//
#include "Seqlist.h"
//测试头尾插入删除
void TestSeqList1(){
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
}
int main(){
    TestSeqList1();
    return 0;
}