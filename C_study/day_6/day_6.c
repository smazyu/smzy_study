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
//int main(){
//    int i = 0;
//    for(i=1;i<11;i++){
//        printf("%d\n", i);
//    }
//}
//在 for 循环中，continue 语句执行后，会先执行循环的增量表达式（即 for 循环中的第三部分），然后再检查循环条件（即 for 循环中的第二部分）以决定是否进行下一次迭代。
//在 while 循环中，由于循环条件位于循环的顶部，continue 语句执行后会直接重新检查循环条件，以决定是否继续执行下一次迭代。
//int main(){
//    int i = 0;
//    for(i=1;i<100;i++){
//        if(i == 5){
//            break;
//        }
//        printf("%d\n",i)
//    }
//}
////不可在for循环体内修改循环变量，防止for循环失去控制
//int main() {
//    int arr[10] = {0};
//    int i = 0;
//    for(i = 0; i <= 10; i++){
//        arr[i] = i;
//        printf("%d\n",arr[i]);
//
//    }
//    return 0;
//}
//int main(){
////    判断部分省略 -判断恒为真 -死循环
////    for (;;)
//    int i = 0;
//    int j = 0;
//    for(;i<3;i++){
//        for(;j<3;j++){
//            printf("hehe\n");
//        }
//    }
//    return 0;
//}
//int main{
//        int x, y;
//        for (x=0, y=0;x<2 && y<5;++x, y++){
//            printf("hehe\n");
//        }
//};