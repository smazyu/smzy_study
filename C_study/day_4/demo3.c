//
// Created by 20212 on 3/9/2024.
//
//
//~按位取反,1变成0,0变成1
//整数在内存中以补码的形式存储
//一个整数的二进制的表示形式有三种
//原码 反码 补码 反码是原码取反，补码是反码加1
//%d 取的是原码的值
//
#include "stdio.h"
//int main(){
//    int a = 1;
//    printf("%d\n",~a);
//}
//++1,前置++先加后用，后置++先用后加
//(int)强制类型转换
//逻辑操作符 && || !
//&& 逻辑与 两边都为真则为真
//|| 逻辑或 两边有一个为真则为真
//int main(){
//    int a = 3;
//    int b = 0;
//    int c = a && b;
//    printf("c = %d\n",c);
//}
//条件操作符(三目操作符)
//表达式1?表达式2:表达式3
//如果表达式1为真则执行表达式2，否则执行表达式3
//int main(){
//    int a = 3;
//    int b = 4;
//    int c = 0;
//    c = a > b ? a : b;
//    printf("c = %d\n",c);
//}
//逗号表达式 逗号隔开的表达式
//int main(){
//    int a = 0;
//    int b = 1;
//    int c = 2;
//    int d = (a++,b++,c++);//逗号表达式的值是最后一个表达式的值
//    printf("d = %d\n",d);
//}
//[]下标操作符
//int main(){
//    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//    printf("%d\n",arr[0]);//1
//    return 0;
//}
//函数调用操作符
//()函数调用操作符 可以传多个参数
//()强制类型转换操作符
//c语言提供的关键字
//1.c语言提供的，不能自己创建
//2.关键字全部小写
//3.关键字不能用作变量名
//4.关键字不能用作函数名
//5.关键字不能用作标签名
//6.关键字不能用作宏名
//7.关键字不能用作枚举名
//8.关键字不能用作结构体名
//9.关键字不能用作联合名
//10.关键字不能用作枚举成员名
//11.关键字不能用作结构体成员名
//12.关键字不能用作联合成员名
//13.关键字不能用作typedef名
//一些关键字 auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while
//int main(){
//    int a = 10;
//    //auto是隐式的，不需要加
//}
//extern声明外部变量或者函数
//register 寄存器
//static 静态
//int main(){
//    register int a = 10;//建议a存放到寄存器
//}
//计算机中的数据可以存储到 高速缓存 内存 硬盘 网盘
//int main(){
////    大量频繁被使用的数据存放到寄存器
//}
//singed 有符号的 10 -20
//unsigned 无符号的 0 10
//static 静态的！
//union 联合体 void 无-空
//define  和 include 都不是关键字 预处理指令