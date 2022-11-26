#include "game.h"

short Curr_BoradRow = MIN_ROW;		//初始化棋盘默认行数
short Curr_BoradCol = MIN_COL;		//初始化棋盘默认列数
_Bool isPlayerFirstMove = _PLAYER_FIRST_MOVE;	//初始化游戏玩家先走
int GameRound = 0;	//初始化游戏回合
void Iniboard(char board[MAX_ROW][MAX_COL], short row, short col)	//便利每个元素 并赋值为‘ ’空格 来进行初始化
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

	
}

void DisplayBoard(char board[MAX_ROW][MAX_COL], short row, short col)	
/*

打印格子:
     ---      ---
	| x |	 | x |
	 ---	  ---		
	 一行有 设置的行数个
	 一列有 设置的列数个
	 x为 棋盘数组中的元素

	 */

{
	
	for (int ii = 0; ii < col; ii++)
	{
		printf("  %d   ", ii + 1);
	}
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		int count = 0;
		for (int j = 0; j < col; j++)
		{
			

			for (int ii = 0; ii < col; ii++)
			{
				printf(" ---  ");
			}
			
			
			printf("\n");
			for (int ii = 0; ii < col; ii++)
			{
				
				printf("| ");
				PrintItem(board[i][j]);
				j += 1;
				count++;
				
				printf(" | ");
			}
			if (count == row)
			{
				printf("%d", i + 1);
			}
			printf("\n");
			for (int ii = 0; ii < col; ii++)
				printf(" ---  ");
			

			

		}
		printf("\n");
		

		
	}
}

void SetBoardRowAndCol(short set_row, short set_col)	//允许设置棋盘行与列
{
	if (set_row >= MAX_ROW + 1 || set_row < MIN_ROW)
	{
		printf("设置的行数不能大于-> %d <-行，并且不能小于-> %d <- 行\n", MAX_ROW,MIN_ROW);
		system("pause");
		system("cls");
	}
	else if (set_col >= MAX_COL + 1 || set_col < MIN_COL)
	{
		printf("设置的列数不能大于-> %d <-行，并且不能小于-> %d <- 行\n", MAX_COL, MIN_COL);
		system("pause");
		system("cls");
	}
	else
	{
		Curr_BoradRow = set_row;
		Curr_BoradCol = set_col;
		printf("已成功设置行数为-> %hd <-\n", Curr_BoradRow);
		printf("已成功设置列数为-> %hd <-\n", Curr_BoradCol);
		system("pause");
		system("cls");

	}
}


void PrintItem(char print)
{
	printf("%c", print);
}



int PlaerMove(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol)
{
	/*
		玩家移动函数：
		具体实现->
		接收玩家输入后判断玩家输入是否合法，如果合法就将玩家输入的位置覆盖为 # 并返回 1 
		如果输入的位置超出棋盘或小于棋盘 (输入不合法) 就返回0 
		如果输入的位置已经被走过 就返回-1
	
	*/
	while (1)
	{
		short Move_Row = 0;
		short Move_Col = 0;


		printf("请输入要下棋的坐标 输入方式为 行 列\n例子 1 2 设置1行2列的数据为#\n");
		scanf("%hd %hd", &Move_Row, &Move_Col);
		if ((Move_Row >= 1 && Move_Row <= Curr_BoradRow) && (Move_Col >= 1 && Move_Col <= Curr_BoradCol))
		{
			if (board[Move_Row - 1][Move_Col - 1] == ' ')
			{
				board[Move_Row - 1][Move_Col - 1] = '#';
				return 1;
			}
			else
			{
				return -1;
			}
			
		}
		else
		{
			return 0;
		}
	}
	
}

_Bool ComputerMove(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol)
{
	/*	
	* 
	* 电脑移动函数：
	* 具体实现->：
	* 产生两个随机值分别是 行 列 但产生的行与列要大于等于0且要小于等于棋盘的 行与列
	* 如果产生的随机值 对棋盘 来说是合法的
	* 那么就判断 该位置是不是被走过的位置，如果没有走过 就下棋 并结束该函数 返回TRUE 代表已下棋
	* 如果已经是走过的位置 就重新生成两个行与列随机值
	* 
	*/
	int Computer_Step_MoveRow = 0;
	int Computer_Step_MoveCol = 0;
	while (1)
	{
		Computer_Step_MoveRow = rand() % Curr_BoradRow;
		Computer_Step_MoveCol = rand() % Curr_BoradCol;
		if ((Computer_Step_MoveRow <= Curr_BoradRow && Computer_Step_MoveRow >= 0) && (Computer_Step_MoveCol <= Curr_BoradCol && Computer_Step_MoveCol >= 0))
		{
			if (board[Computer_Step_MoveRow][Computer_Step_MoveCol] == ' ')
			{
				printf("-> 电脑输入中... <-\n     ......\n");
				Sleep(700);
				system("cls");
				board[Computer_Step_MoveRow][Computer_Step_MoveCol] = '*';
				return TRUE;
			}
			
		}

	}
	

	
}

char WhoIsWin(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol)
{
	//判断一行是否一样
	int SameRow = 0;
	for (int i = 0; i < Curr_BoradRow; i++)
	{
		
		for (int ii = 0; ii < Curr_BoradCol - 1; ii++)
		{
			if ((board[i][ii] == board[i][ii + 1]) && board[i][ii] != ' ' && board[i][ii + 1] != ' ')
			{
				SameRow++;
				if (SameRow == Curr_BoradCol - 1)
				{
					return board[i][0];
				}
			}
			else
			{
				SameRow = 0;
				break;
			}
		}

	}
	
	
	//判断一列是否一样
	int SameCol = 0;
	for (int i = 0; i < Curr_BoradCol; i++)
	{

		for (int ii = 0; ii < Curr_BoradRow - 1; ii++)
		{
			if ((board[ii][i] == board[ii+1][i]) && board[ii][i] != ' ' && board[ii+1][i] != ' ')
			{
				SameCol++;
				if (SameCol == Curr_BoradRow - 1)
				{
					return board[0][i];
				}
			}
			else
			{
				SameCol = 0;
				break;
			}
		}

	}

		//判断左斜列是否一样	//00 11 22..相等 就SameLeftOblique+1 如果SameLeftOblique=行数-1 代表有人赢了
		int SameLeftOblique = 0;
		for (int i = 0, j = 0; i < Curr_BoradRow - 1 && j < Curr_BoradCol - 1; i++, j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] != ' ')
			{
				SameLeftOblique++;
				if (SameLeftOblique == Curr_BoradRow - 1)
				{
					return board[0][0];
				}
			}
			else
			{
				SameLeftOblique = 0;
				break;
			}


		}

		//判断右斜列是否一样	//02 11 20..相等 就SameRightOblique+1 如果SameRightOblique=行数-1 代表有人赢了
		int SameRightOblique = 0;
		for (int i = 0, j = Curr_BoradCol - 1; i<=j; i++, j--)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] != ' ')
			{
				SameRightOblique++;
				if (SameRightOblique == Curr_BoradRow - 1)
				{
					return board[0][Curr_BoradCol - 1];
				}
			}
			else
			{
				SameRightOblique = 0;
				break;
			}
		}


		if (BoardIsFull(board,Curr_BoradRow,Curr_BoradCol) == 1)	//如果棋盘满了 就返回P 代表游戏平局
		{
			return 'P';
		}
	

	return 'C';			//上面的条件都不满足 代表游戏还没结束 返回 C
}

int BoardIsFull(char board[MAX_ROW][MAX_COL], short Curr_BoradRow, short Curr_BoradCol)	//棋盘是否已满 遍历整个棋盘如果有一个为空 就返回0 如果都不为空 返回1 代表棋盘满了
{
	for (int i = 0; i < Curr_BoradRow; i++)
	{
		for (int j = 0; j < Curr_BoradCol; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	
	return 1;
}



void SetPlayerFirstMoveOrComputerFirstMove(_Bool IsSetValue)	//设置玩家先走还是电脑先走
{
	if (IsSetValue == _PLAYER_FIRST_MOVE)
	{
		isPlayerFirstMove = _PLAYER_FIRST_MOVE;
	}
	else
	{
		isPlayerFirstMove = _COMPUTER_FIRST_MOVE;
	}
	
}
