//
// Created by 20212 on 11/05/2024.
//
//相较于顺序表，无增容的概念，用一个申请一个，不会浪费空间
#include <stdio.h>
typedef int SlistDataType;
typedef struct SlistNode{
    SlistDataType data;
    struct SlistNode* next;
}SLTNode;