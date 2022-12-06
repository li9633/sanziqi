#ifndef __GAME_H__
#define __GAME_H__	//避免重复包含头文件
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 128			//定义最大棋盘行数
#define MAX_COL 128			//定义最大棋盘列数
#define MIN_ROW 3			//定义最小棋盘行数
#define MIN_COL 3			//定义最小棋盘列数

#define _PLAYER_FIRST_MOVE 1	//定义玩家先走等于1
#define _COMPUTER_FIRST_MOVE 0	//定义电脑先走等于0


extern short Curr_BoradRow;			//声明外部全局变量 当前棋盘行数
extern short Curr_BoradCol;			//声明外部全局变量 当前棋盘列数
extern _Bool isPlayerFirstMove;		//声明外部全局变量 是玩家先走
extern int GameRound;				//声明外部全局变量 游戏回合数



void Iniboard(char board[MAX_ROW][MAX_COL], short row, short col);		//声明 初始化棋盘函数

void DisplayBoard(char board[MAX_ROW][MAX_COL], short row, short col);		//声明 显示棋盘函数

void PrintItem(char print);		//声明 打印棋盘中元素函数

void SetBoardRowAndCol(short set_row,short set_col);		//声明 设置棋盘行与列函数

int PlaerMove(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short  Curr_BoradCol);		//声明 玩家移动函数

_Bool ComputerMove(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short  Curr_BoradCol);	//声明 电脑移动函数

char WhoIsWin(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol);		//声明	输赢判断函数


void SetPlayerFirstMoveOrComputerFirstMove(_Bool IsSetValue);		//声明  设置玩家先移动或者电脑先移动函数

int BoardIsFull(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol);	//声明  设置棋盘是否已满函数






#endif // !__GAME_H__
