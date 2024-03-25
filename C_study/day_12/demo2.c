//
// Created by 20212 on 2024/3/25.
//
//整型指针加1四个字节
//字符指针加1一个字符
#include <stdio.h>
//int main(){
//    int *o;//o是一个局部的指针变量，局部变量不初始化，默认是随机值
//    *o = 20;//非法访问内存
//    return 0;
////}
//int main(){
//    int arr[10] = {0};
//    int*p = arr;
//    int i  =0;
//    for(i;i<= 10;i++){
//        *p = i;
//        p++;
//    }
//    return 0;
//}
//当指针不知道初始化为什么时，先初始化为NULL
//int main(){
//    int *p = NULL;
////    明确知道初始化化的值
//    *p = 10;
////指针使用之后置空
//}
//指针+-整数
//
int main()