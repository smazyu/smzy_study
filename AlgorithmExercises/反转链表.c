//
// Created by 20212 on 14/05/2024.
//
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//1.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#if 0
#include <stdio.h>
struct ListNode {
         int val;
        struct ListNode *next;
     };
//方法一
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL|| head->next == NULL)
        return head;
    struct ListNode *n1 = NULL,*n2 = head,*n3 = head -> next;
    while(n2){
        n2 -> next = n1;
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3 -> next;
    }
    // head = n2;
    // return head;
    head = n1;
    return head;
}
//方法2
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while(cur != NULL){
        next = cur ->next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
#endif