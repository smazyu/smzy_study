#pragma once
//栈也可以写成静态的
typedef int STDataType;
typedef struct Stack{
    STDataType * _a;
    int _top;//栈顶下标
    int _capacity;
}Stack;
void StactInit();
