//
// Created by 20212 on 24-4-25.
//

#include "contact.h"

void menu(){
    printf("************************************\n");
    printf("*******1.add ****** 2.del*********************\n");
    printf("*******3.search*****4.modify*******************\n");
    printf("*******5.sort ******6.print*********************\n");
    printf("*******0.exit****************************\n");
    printf("************************************\n");
}
enum Option{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT,
    PRINT
};
int main(){
    int input = 0;
    //创建通讯录
    Contact con;
    //初始化通讯录
    InitContact(&con);
    do{
        menu();
        printf("请选择 ：->");
        scanf("%d",&input);
        switch(input){
            case ADD:
                //增加人的信息
                AddContact(&con);
                break;
            case DEL:
                break;
            case SEARCH:
                break;
            case MODIFY:
                break;
            case SORT:
                break;
            case PRINT:
                PrintContact(&con);
                break;
        }
    }while(input != EXIT);
    return 0;
}