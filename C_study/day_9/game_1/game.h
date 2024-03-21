//
// Created by 20212 on 2024/3/21.
//
//符号的定义
#define ROW 5
#define COL 5
#include <stdio.h>
//函数的声明
//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
//玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col);
