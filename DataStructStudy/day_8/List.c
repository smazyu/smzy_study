
#include "List.h"
void ListInit(ListNode ** pphead){
    *pphead = BuyListNode(0);
    (*pphead) -> next = *pphead;
    (*pphead) -> prev = *pphead;
}
ListNode* BuyListNode(LTDataType x){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node -> next = NULL;
    node -> prev = NULL;
    node -> data = x;
    return node;
}
void ListPushBack(ListNode* phead,LTDataType x){
    assert(phead);
    ListNode * tail = phead -> prev;
    ListNode* newnode = BuyListNode(x);
    tail -> next = newnode;
    newnode -> prev = tail;
    newnode -> next = phead;
    phead -> prev = newnode;
}
void ListPrint(ListNode* phead){
    assert(phead);
    ListNode* cur = phead -> next;
    while(cur != phead){
        printf("%d\n",cur -> data);
        cur = cur -> next;
    }
}