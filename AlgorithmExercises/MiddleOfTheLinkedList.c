// 给你单链表的头结点 head ，请你找出并返回链表的中间结点。

// 如果有两个中间结点，则返回第二个中间结点。




struct ListNode {
     int val;
      struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
{
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    return slow;
}