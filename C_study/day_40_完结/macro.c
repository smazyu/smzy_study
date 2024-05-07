#include <stdio.h>
#define M 1
int main(){
    int a = M;
    // int b = a + 1;
    printf("%d\n",a);
#undef M
    // int b = ++a;//这里就叫做有副作用
    //宏是直接替换
    // int b = M 这里报错 因为我取消了宏定义
}

//宏比函数的效率更高
//宏可能不太严谨 宏运算优先级问题 

//运算逻辑足够简单 用宏
//不然就用函数