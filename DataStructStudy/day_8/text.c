#include "List.h"
void TextList1(){
    ListNode* phead = NULL;
    ListInit(&phead);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,6);
    ListPopBack(phead);
    ListPopBack(phead);
    // ListPopBack(phead);
    ListPushFront(phead,5);
    // ListPopBack(phead);
    // ListPopBack(phead);
    ListPrint(phead);
}
int main(){
    TextList1();
    return 0;
}