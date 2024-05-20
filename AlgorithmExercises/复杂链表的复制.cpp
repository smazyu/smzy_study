//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

// Definition for a Node.
#if 0
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* cur = head;
        while(cur){
            Node* copy = (Node *)malloc(sizeof(Node));
            copy -> next = NULL;
            copy -> random = NULL;
            copy -> val = cur -> val;
            copy -> next = cur -> next;
            cur -> next = copy;
            cur = copy -> next;
        }
        //random
        cur = head;
        while(cur){
            if(cur -> random){
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }
        cur = head;
        Node* cHead = head -> next;
        Node * copy = cHead;
        while(cur){
            cur -> next = copy -> next;
            cur = cur -> next;
            if(cur){
                copy -> next = cur -> next;
                copy = copy -> next;
            }
        }
        return cHead;
    }
};
#endif