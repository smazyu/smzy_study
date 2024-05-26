// #include <stdio.h>
// #define M 1
// int main(){
//     int a = M;
//     // int b = a + 1;
//     printf("%d\n",a);
// #undef M
//     // int b = ++a;//这里就叫做有副作用
//     //宏是直接替换
//     // int b = M 这里报错 因为我取消了宏定义
// }

//宏比函数的效率更高
//宏可能不太严谨 宏运算优先级问题 

//运算逻辑足够简单 用宏
//不然就用函数

//命令行参数 命令行定义 gcc test.c -D M = 100 
//条件编译
#if 0//预处理关键字 对下列代码不编译
#include <stdio.h>
#define PRINT 1
int main(){
    #ifdef PRINT
        printf("1111");
    #endif
        return 0;
    #if 1
        printf('1');
    #endif
        return 0;
}
// #elif 2
// #endif //预处理关键字
// #endif
// #ifdef TEST 如果TEST定义了，下面参与编译
// #ifndef TEST 如果TEST未定义 
#endif
#if !defined(hehe)
#endif
//#if -> #endif
//#elif



