//
// Created by 20212 on 2024/5/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(char value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

TreeNode* buildExpressionTree(char* expression) {
    TreeNode* numberStack[100];
    TreeNode* operatorStack[100];
    int numberTop = -1;
    int operatorTop = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char value = expression[i];
        if (isdigit(value)) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            numberStack[++numberTop] = createNode(num + '0');
        } else if (value != ' ') {
            while (operatorTop != -1 && precedence(value) <= precedence(operatorStack[operatorTop]->data)) {
                TreeNode* right = numberStack[numberTop--];
                TreeNode* left = numberStack[numberTop--];
                TreeNode* op = operatorStack[operatorTop--];
                op->left = left;
                op->right = right;
                numberStack[++numberTop] = op;
            }
            operatorStack[++operatorTop] = createNode(value);
        }
    }

    while (operatorTop != -1) {
        TreeNode* right = numberStack[numberTop--];
        TreeNode* left = numberStack[numberTop--];
        TreeNode* op = operatorStack[operatorTop--];
        op->left = left;
        op->right = right;
        numberStack[++numberTop] = op;
    }

    return numberStack[numberTop];
}

int evaluateExpressionTree(TreeNode* root) {
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';
    } else {
        int left_val = evaluateExpressionTree(root->left);
        int right_val = evaluateExpressionTree(root->right);
        switch (root->data) {
            case '+':
                return left_val + right_val;
            case '-':
                return left_val - right_val;
            case '*':
                return left_val * right_val;
            case '/':
                return left_val / right_val;
        }
    }
    return 0;
}

int main() {
    char expression[] = "3+5*2";
    TreeNode* root = buildExpressionTree(expression);
    int result = evaluateExpressionTree(root);
    printf("表达式的值为：%d\n", result);
    freeTree(root);
    return 0;
}
