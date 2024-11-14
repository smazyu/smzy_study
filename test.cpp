#include <stdio.h>
int main() {
    float num1, num2, result;
    int choice;
    printf("请输入第一个数字：");
    scanf("%f", &num1);
    printf("请输入第二个数字：");
    scanf("%f", &num2);
    printf("\n选择运算：\n");
    printf("1. 加法\n");
    printf("2. 减法\n");
    printf("3. 乘法\n");
    printf("4. 除法\n");
    printf("请输入你的选择（1/2/3/4）：");
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        result = num1 + num2;
        printf("结果：%.2f + %.2f = %.2f\n", num1, num2, result);
        break;
    case 2:
        result = num1 - num2;
        printf("结果：%.2f - %.2f = %.2f\n", num1, num2, result);
        break;
    case 3:
        result = num1 * num2;
        printf("结果：%.2f * %.2f = %.2f\n", num1, num2, result);
        break;
    case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("结果：%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("除数不能为零！\n");
            }
        break;
    default:
        printf("无效的选择！\n");
        break;
    }

    return 0;
}
