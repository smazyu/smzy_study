//
// Created by 20212 on 2024/3/26.
//
#include <stdio.h>
//int main(){
//    int arr[10] = {0};
//    printf("%p\n",arr);
////    数组名是数组首元素的地址
//    printf("%p\n",&arr[0]);
//}
int main(){
    int arr[10] = {0};
    int*p = arr;
    int i = 0;
    for(i;i<10;i++){
        printf("%p==>%p\n",&arr[i],p+i);
        *(p+i) = i;
//        arr[2] == *(p+2)  ==  *(2+p) == *(2+arr)
    }
    for(i=0;i<10;i++){
        printf("%d\n",*(p+i));
    }
}