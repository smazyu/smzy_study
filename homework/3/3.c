//
// Created by 20212 on 2024/5/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct SeqStack{
    void ** data; // 数据元素指针
    int top; // 栈顶元素编号
    int max; // 最大结点数
};

struct SeqStack* SS_Create(int maxlen)
{
    struct SeqStack* ss=(struct SeqStack*)malloc(sizeof(struct SeqStack));
    ss->data=malloc(maxlen*sizeof(void*));
    ss->top=-1;
    ss->max=maxlen;
    return ss;
}

bool SS_IsEmpty(struct SeqStack* ss)
{
    return ss->top == -1;
}

int SS_Length(struct SeqStack* ss)
{
    int a = ss-> top;
    return a + 1;
}

bool SS_Push(struct SeqStack* ss, void * x)
{
    if (ss == NULL || ss->data == NULL || ss->top >= ss->max - 1) {
        return false; // 栈为空或者已满
    }
    ss->top++;
    ss->data[ss->top] = x;
    return true;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }else if(c == '*' || c== '/'){
        return 2;
    }else{
        return 0;
    }
}

int calculate(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool SS_Pop(struct SeqStack* ss, void** item)
{
    if (SS_IsEmpty(ss)) {
        return false;
    }
    *item = ss->data[ss->top];
    ss->top--;
    return true;
}

bool SS_Top(struct SeqStack* ss, void** item)
{
    if (SS_IsEmpty(ss)) {
        return false;
    }
    *item = ss->data[ss->top];
    return true;
}

int main(){
    char str[] = "3 + 1 * 2";
    char post[100];
    int putindex = 0;
    struct SeqStack* ss = SS_Create(strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == ' ') continue;  // 忽略空格字符
        if (isdigit(c)) {
            post[putindex++] = c;
        }
        else if (c == '(') {
            char *p = malloc(sizeof(char));
            *p = c;
            SS_Push(ss, p);
        }
        else if (c == ')') {
            char *top;
            while (SS_Top(ss, (void**)&top) && *top != '(') {
                SS_Pop(ss, (void**)&top);
                post[putindex++] = *top;
            }
            SS_Pop(ss, (void**)&top);
        }
        else if (isOperator(c)) {
            char *top;
            while (!SS_IsEmpty(ss) && SS_Top(ss, (void**)&top) && precedence(*top) >= precedence(c)) {
                SS_Pop(ss, (void**)&top);
                post[putindex++] = *top;
            }
            char *p = malloc(sizeof(char));
            *p = c;
            SS_Push(ss, p);
        }
    }
    char *top;
    while (SS_Top(ss, (void**)&top)) {
        SS_Pop(ss, (void**)&top);
        post[putindex++] = *top;
    }
    post[putindex] = '\0';
    printf("%s\n", post);
}