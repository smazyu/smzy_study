// 现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
#if 0
class Partition {
  public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        //大体思路：创建两个链表，一个存储小于x的值，一个存储大于x的值，遍历原链表进行尾插。
        //创建哨兵卫
        struct ListNode* greatHead, *greattail, *lessHead, *lesstail, *cur;
        greatHead = greattail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lessHead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = pHead;
        //遍历原链表进行尾插
        while (cur) {
            if (cur->val < x) {
                lesstail->next = cur;  //链接原链表头节点
                lesstail = lesstail ->next;    //更新less链表尾节点;  //原链表中cur继续更新往下走
            } else {
                greattail->next = cur;
                greattail = greattail -> next;
            }
            cur = cur->next;
        }

        lesstail->next = greatHead->next;  //链接less链表和geart链表
        greattail->next = NULL;   //注意处理最后一个节点的原链接关系

        return lessHead->next;
    }
};
#endif