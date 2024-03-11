//
// Created by 20212 on 3/11/2024.
//
#include <stdio.h>
int main(){
    char password[20] = {0};
    printf("请输入密码");
    scanf("%s", password);//123456
    printf("请确认密码(Y/N):>");
//    这里会读取回车 输入函数从缓冲区里面拿数据，如果缓冲区没有数据，就会等待，如果缓冲区有数据，就会直接拿走
    int ch = getchar();
    if(ch == 'Y'){
        printf("密码确认成功");
    }else{
        printf("密码确认失败");
    }
}