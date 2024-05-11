//
// Created by 20212 on 11/05/2024.
//
#include "Slist.h"
void SListPrint(SListNode* phead){
    SListNode* cur = phead;
    while(cur != NULL){
        printf("%d",cur -> data);
        cur = cur -> next;
    }
}