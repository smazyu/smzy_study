// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
// 图示两个链表在节点 c1 开始相交
#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* NodeA = headA;
    struct ListNode* NodeB = headB;
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    int la = 0;
    int lb = 0;
    while(NodeA){
        NodeA = NodeA -> next;
        la++;
    }
    while(NodeB){
        NodeB = NodeB -> next;
        lb++;
    }
    struct ListNode * longNode = headA;
    struct ListNode * shortNode = headB;
    if(la < lb){
        longNode = headB;
        shortNode = headA;
    }
    int gap = abs(la - lb);
    while(gap --){
        longNode = longNode -> next;
    }
    while(longNode){
        if(longNode == shortNode){
            return longNode;
        }
        longNode = longNode -> next;
        shortNode = shortNode -> next;
    }
    return NULL;
}
#endif