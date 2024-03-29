// Created by 20212 on 2024/3/28.
//
#include <stdio.h>
#include <assert.h>
// int main(){
//     int a = 10;
//     int const *p = &a;//const放在*两边时地址指针和指向都不能改变
//     printf("a = %d\n", a);
// }
// int const * const * const p; 修饰p *p 和 **p
void my_srcpy(char*dest,char*src){
    assert(src!= NULL);//断言
    assert(dest != NULL);
    while(*dest++ = *src++){
        ;
    }
}
int main(){
    printf("hello world");
}