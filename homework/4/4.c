//
// Created by 20212 on 2024/5/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义栈结构
#define MAX_SIZE 100

typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// 初始化栈
void init(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 入栈
void push(Stack *s, char c) {
    s->items[++(s->top)] = c;
}

// 出栈
char pop(Stack *s) {
    return s->items[(s->top)--];
}

// 获取栈顶元素
char peek(Stack *s) {
    return s->items[s->top];
}

// 判断运算符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 中缀表达式转换为后缀表达式
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '=') {
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // 弹出左括号
        } else {
            while (!isEmpty(&s) && precedence(ch) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// 计算后缀表达式的值
int evaluatePostfix(char *postfix) {
    Stack s;
    init(&s);
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("请输入中缀表达式（以=结束）：");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("后缀表达式为：%s\n", postfix);
    printf("计算结果为：%d\n", evaluatePostfix(postfix));
    return 0;
}
