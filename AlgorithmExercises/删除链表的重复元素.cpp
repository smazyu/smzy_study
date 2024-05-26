//
// Created by 20212 on 2024/5/25.
//
#if 0
//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* cur = head,* next = head -> next;
        while(next){
            if(cur -> val == next-> val){
                ListNode* temp = next;
                next = next -> next;
                delete(temp);
            }else{
                cur -> next = next;
                cur = next;
                next = next -> next;
            }
        }
        cur -> next = nullptr;
        return head;
    }
};
#endif