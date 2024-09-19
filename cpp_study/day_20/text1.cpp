//
// Created by 20212 on 19/9/2024.
//
#include <iostream>

using namespace std;
struct ListNode_C {
    int _val;
    struct ListNode_C *_next;
    struct ListNode_C *_prev;
};
typedef struct ListNode_C ListNode_C;

ListNode_C *BuyNode(int val) {
    struct ListNode_C *node_c = (struct ListNode_C *) malloc(sizeof(struct ListNode_C));
    node_c->_val = 1;
    node_c->_next = NULL;
    node_c->_prev = NULL;
    return node_c;
}

int main() {
    int *p1 = (int *) malloc(sizeof(int));
    int *p2 = new int;
    //内置类型 new和malloc一样
    //自定义类型 new和malloc不同
    //new 会调用自定义类型的构造函数和析构函数

    return 0;
}