//
// Created by 20212 on 2024/3/25.
//
//指针是编程语言的一个对象 意识是通过它可以找到对应的地址
////一个字节在内存中的编号 地址 也就是指针
//int main( ){
//
//    int a = 10;
//    &a;//拿到是a的4个字节中第一个字节的地址
//    int * pa = &a;
//    *pa = 20;
////    编号-地址-指针 存放地址的变量-指针变量 通常指的指针其实是地址 指针变量在32位平台是4个字节，在64位平台是8个字节
//    return 0;
//
//
//
//
//}
//指针类型有具体意义
//指针类型的意义
//指针类型大小都一样为什么不创造一个通用类型指针
int main(){
    int a = 0x12223344;
//    0xf1390ffc34
    char *pa = &a;
    *pa = 0;//0x000000f1390ffc40
//    0xf1390ffc34
    return 0;
//1.指针类型决定了：指针解引用的权限有多大
//2.指针类型决定了指针走一步走多远，步长
}
