//
// Created by 20212 on 24-4-16.
//
//指针加一跟指针类型有关
#include <stdio.h>
//int main(){
//   int a[4] = {1,2,3,4};
//   int* ptr1 = (int*) (&a +1);
//   int *ptr2 = (int*)((int)a + 1);
//}
int main(){
    int a[3][2] = {(1,2),(1,2)};
    printf("%d",a[0][0]);
}
