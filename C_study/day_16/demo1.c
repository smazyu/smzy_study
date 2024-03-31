//
// Created by 20212 on 2024/3/31.
//
//release版本会对代码进行优化
#include <stdio.h>
int main(){
    int i = 0;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%p",&i);
    printf("%p",&arr[9]);
    for(i = 0;i<=12;i++){
        arr[i] = 0;
        printf("hehe\n");
    }
    //局部变量是放在栈区上的，栈区的使用习惯是，先使用高地址再使用低地址
    return 0;
}