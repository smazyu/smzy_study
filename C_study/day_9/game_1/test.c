//
// Created by 20212 on 2024/3/21.
//
#include <stdio.h>
#include "game.h"
void game(){
    //存储数据 -二维数组
    char board[ROW][COL];
//   初始化棋盘 - 初始化空格
    InitBoard(board,ROW,COL);
//    打印棋盘
    DisplayBoard(board,ROW,COL);
//    填入棋子
//    与电脑判断胜负

}
void menu(){
    printf("**************************\n");
    printf("*******  1.play  *********\n");
    printf("*******  0.exit  *********\n");
    printf("**************************\n");
}
int main(){
    int input = 0;
    do{
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input){
            case 1:
                printf("三字棋游戏\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误，请重试\n");
                break;
        }
    }while(input);
}