#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#pragma once
typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;
void ListInit(ListNode ** pphead);
void ListPushBack(ListNode* phead,LTDataType x);
ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead,LTDataType x);
void ListPopFront(ListNode* phead);
