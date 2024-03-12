//
// Created by 20212 on 3/13/2024.
//
#include <string.h>
//#include <stdio.h>
//int get_max(int x,int y){
//    int z = 0;
//    if(x>y){
//        z = x;
//    }else{
//        z = y;
//    }
//    return z;
//}
//int main(){
//    int a = 10;
//    int b = 20;
//    int max = get_max(a,b);
//    printf("max = %d\n",max);
//    return 0;
//}
//#include <stdio.h>
//void Swap(int* pa,int* pb){
//    int z = 0;
////    这里和主函数内存空间不同
//    z = *pa;
//    *pa = *pb;
//    *pb = z;
//}形参只在函数内部有效 在调用的一瞬间开辟空间
//int main(){
//    int a = 10;//4个字节的空间
//    int b = 20;
////    写一个函数，交换两个变量的值
//    printf("交换前：a=%d,b=%d",a,b);
//    Swap(&a,&b);
//    printf("交换后：a=%d,b=%d",a,b);
//    return 0;
//}
//真实传进去的参数 实参