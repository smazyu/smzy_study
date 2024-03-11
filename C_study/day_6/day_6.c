//
// Created by 20212 on 3/11/2024.
//
//#include <stdio.h>
//int main(){
//    char password[20] = {0};
//    printf("请输入密码");
//    scanf(" %s", password);//123456 scanf遇到空格就会停止读取
////    printf("%s\n", password);
//    printf("请确认密码(Y/N):>");
////    清理缓冲区
////    这里会读取回车 输入函数从缓冲区里面拿数据，如果缓冲区没有数据，就会等待，如果缓冲区有数据，就会直接拿走
////    getchar();//拿走一个字符\n
//    int tmp = 0;
//getchar()读取的是整型，因为getchar读取的是字符，字符的本质是整型，因为有对应的ASCII码
//    while((tmp = getchar()) != EOF && tmp != '\n'){
//    ;    //清理缓冲区
//                };
//    int ch = getchar();
//    if(ch == 'Y'){
//        printf("密码确认成功");
//    }else{
//        printf("密码确认失败");
//    }
//}
//#include <stdio.h>
//int main(){
//    int ch =0;
//    while ((ch = getchar()) != EOF){
//        if(ch < '0' || ch > '9'){//如果ch不是数字就跳过，只能打印数字字符
//            continue;
//        }
//    }
//    return 0;
//}
#include <stdio.h>
//int main(){
//    int i = 1;//初始化
//    while(i < 11)//判断部分
//    {
//        printf("%d\n", i);
//        ++i;
//    }
//}
//for(初始化; 判断; 改变)
//int main(){
//    int i = 0;
//    for(i=1;i<11;i++){
//        printf("%d\n", i);
//    }
//    return 0;
//}