//
// Created by 20212 on 2024/3/28.
//
#include <stdio.h>
int main(){
    int a = 10;
    int const *p = &a;//const放在*两边时地址指针和指向都不能改变
    printf("a = %d\n", a);
}