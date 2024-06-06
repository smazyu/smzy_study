//
// Created by 20212 on 6/6/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    char *data;
    int top;
    int max;
};

struct Stack* createStack(int maxlen) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (char*)malloc(maxlen * sizeof(char));
    stack->top = -1;
    stack->max = maxlen;
    return stack;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool push(struct Stack* stack, char value) {
    if (stack->top >= stack->max - 1) {
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

bool pop(struct Stack* stack, char *value) {
    if (isEmpty(stack)) {
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

bool top(struct Stack* stack, char *value) {
    if (isEmpty(stack)) {
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

int main() {
    char str[] = "3 + 1 * 2";
    char post[100];
    int postIndex = 0;
    struct Stack* stack = createStack(strlen(str));

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            post[postIndex++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            char topValue;
            while (top(stack, &topValue) && topValue != '(') {
                pop(stack, &topValue);
                post[postIndex++] = topValue;
            }
            pop(stack, &topValue); // Remove '('
        } else if (isOperator(c)) {
            char topValue;
            while (!isEmpty(stack) && top(stack, &topValue) && precedence(topValue) >= precedence(c)) {
                pop(stack, &topValue);
                post[postIndex++] = topValue;
            }
            push(stack, c);
        }
    }

    char topValue;
    while (top(stack, &topValue)) {
        pop(stack, &topValue);
        post[postIndex++] = topValue;
    }
    post[postIndex] = '\0';
    printf("%s\n", post);

    free(stack->data);
    free(stack);

    return 0;
}
