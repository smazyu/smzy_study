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
void ListPopBack(ListNode* phead){
    assert(phead);
    // ListNode* cur = phead -> next;
    // while(cur != phead){
    //     if(cur -> next == phead -> prev){
    //         break;
    //         //目前cur就是tail前一个
    //     }
    //     cur = cur -> next;
    // }
    // cur -> next = phead;
    // if(phead -> next != phead){
    //     free(phead -> prev);
    //     phead -> prev = cur;
    // }
    ListNode* tail = phead -> prev;
    ListNode* tailPrev = tail -> prev;
    tailPrev -> next = phead;
    phead -> prev = tailPrev;
    free(tail);
    tail = NULL;
}
void ListPrint(ListNode* phead){
    assert(phead);
    ListNode* cur = phead -> next;
    while(cur != phead){
        printf("%d\n",cur -> data);
        cur = cur -> next;
    }
}
void ListPopFront(ListNode* phead){
    assert(phead -> next != phead);
    ListNode* first = phead -> next;
    ListNode* second = first -> next;
    phead -> next = second;
    second -> prev = phead;
    free(first);
    first = NULL;
}
void ListPushFront(ListNode* phead,LTDataType x){
    assert(phead);
    ListNode* first = phead -> next;
    ListNode* newnode = BuyListNode(x);
    phead -> next = newnode;
    newnode -> prev = phead;
    newnode -> next = first;
    first -> prev = newnode;
}