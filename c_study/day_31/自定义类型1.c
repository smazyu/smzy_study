//
// Created by 20212 on 24-4-22.
//
#include <stdio.h>
struct s1{
    char c1;
    int i;
    char c2;
};
int main(){
    struct s1 s = {0};
    printf("%d\n",sizeof(s));
    return 0;
}
//对齐数 = 编译器默认的对齐数与该成员大小之间的最小值
//对齐到对齐数的整数倍处
//内存对齐 vs-默认对齐数 8
//linux 没有默认对齐数
//结构体的总大小为最大对齐数的整数倍
//如果嵌套类结构体 嵌套的结构体对齐到自己的最大对齐数的整数倍处
//结构体的整体大小就是所有最大对齐数的（含嵌套对齐数）的整数倍
//1.结构体的第一个成员
//放在结构体变量在内存中存储位置的0偏移处
//2.从第二个成员往后，都放在一个对齐数的整数的整数倍处
//3.结构体的大小总是结构体的所有成员的对齐数 中最大的那个
//总得来说，内存对齐是拿空间换时间