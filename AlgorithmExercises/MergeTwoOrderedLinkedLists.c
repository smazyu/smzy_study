//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// typedef struct ListNode Node;

// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//     Node * l1 = list1;
//     Node * l2 = list2;

//     // Base cases
//     if (l1 == NULL) return l2;
//     if (l2 == NULL) return l1;

//     // Initialize head and tail
//     Node *head, *tail;
//     if (l1->val <= l2->val) {
//         head = l1;
//         l1 = l1->next;
//     } else {
//         head = l2;
//         l2 = l2->next;
//     }
//     tail = head;

//     // Merge lists
//     while (l1 != NULL && l2 != NULL) {
//         if (l1->val <= l2->val) {
//             tail->next = l1;
//             l1 = l1->next;
//         } else {
//             tail->next = l2;
//             l2 = l2->next;
//         }
//         tail = tail->next;
//     }

//     // Append the remaining nodes of l1 or l2
//     if (l1 != NULL) {
//         tail->next = l1;
//     } else {
//         tail->next = l2;
//     }

//     return head;
// }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //带哨兵位的头节点
    //这里malloc重新分配一个，代表为哨兵位，不是空指针，只有当前指针不为空，才能指向下一个指针
    //带哨兵位的链表，即链表在创建之后，就默认有一个头节点，其是哨兵位，就可以往后面插元素，而不用设置头节点
    Node * l1 = list1,* l2 = list2,* head = (Node*)malloc(sizeof(Node)),*tail = head;
    tail -> next = NULL;
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL )
        return l1;
    while(l1 && l2){
        if(l1 -> val > l2 -> val){
            tail -> next = l2;
            l2 = l2 -> next;
        }else{
            tail -> next = l1;
            l1 = l1 -> next;
        }
        tail = tail -> next;
    }
    if(l1 != NULL){
        tail -> next = l1;
    }else{
        tail -> next = l2;
    }
    Node* realhead = head -> next;
    free(head);
    return realhead;
}
// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Example usage
    Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    Node* mergedList = mergeTwoLists(list1, list2);
    printList(mergedList);

    return 0;
}
