//给你一个单链表的头节点 head ，请你判断该链表是否为
// 回文链表
// 。如果是，返回 true ；否则，返回 false 
#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    //首先拿到中间节点
    if(head == NULL || head -> next == NULL){
        return true;
    }
    struct ListNode* slow = head,*fast = head;
    
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast ->next -> next;
    }
    //从中间节点开始倒置
    struct ListNode *prev = NULL,*curr = slow,*next = NULL;
    while(curr){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    //中节点前后对比
    struct ListNode *OldHead = head,*NewHead = prev;
    while(NewHead != NULL){
        if(OldHead->val != NewHead ->val){
            return false;
        }
        OldHead = OldHead -> next;
        NewHead = NewHead -> next;
    }
    return true;
}
#endif