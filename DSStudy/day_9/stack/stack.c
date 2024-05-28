//
// Created by 20212 on 2024/5/27.
//

#include "stack.h"
void StackInit(Stack *pst){
    assert(pst);
}
void StackDestory(Stack *pst);
//插入和取出
void StackPush(Stack* pst,STDataType x);
void StackPop(Stack* pst);
int StackSize(Stack *pst);
//返回1是空，返回0是非空
int StackEmpty(Stack *pst);