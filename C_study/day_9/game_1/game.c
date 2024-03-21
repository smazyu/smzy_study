//
// Created by 20212 on 2024/3/21.
//
#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for (i = 0;i < row;i++){
        for (j = 0;j < col;j ++){
            board[i][j] = ' ';
        }
    }
}
void DisplayBoard(char board[ROW][COL],int row,int col){
    int i = 0;
    for(i = 0;i < row;i++){
        int j = 0;
        for (j = 0;j < col;j++){
            printf(" %c ",board[i][j]);
            if(j<col - 1)
                printf("|");
        }
        printf("\n");
        if(i < row -1){
            for(int j = 0;j < col; j++){
                printf("---");
                if(j<col - 1)
                    printf("|");
            }
            printf("\n");
        }

    }
}
void PlayerMove(char board[ROW][COL],int row,int col){
    printf("玩家走>");
    printf("请输入你要走的坐标:>")









}