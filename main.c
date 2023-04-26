#include "game.h"


void menu()
{
	printf("***************************************************\n");
	printf("******1.开始游戏     2.设置游戏    0.退出游戏******\n");
	printf("***************************************************\n");
}   //打印菜单

void game()		//开始游戏
{
	printf("游戏正在初始化...！\n");
	char board[MAX_ROW][MAX_COL];
	Sleep(500);
	system("cls");
	char ret = ' ';	//初始化输赢判断函数返回值
	GameRound = 0;	//初始化游戏回合

	Iniboard(board,Curr_BoradRow,Curr_BoradCol);
	DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
	while (1)
	{
		if (isPlayerFirstMove)	//玩家先走
		{
			int PlayerMove_return = PlaerMove(board, Curr_BoradRow, Curr_BoradCol);
			if (PlayerMove_return == 1)
			{
				system("cls");
				GameRound++;
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
				if (GameRound >= 2)
				{
					ret = WhoIsWin(board, Curr_BoradRow, Curr_BoradCol);
					 if (ret == '#')		//如果输赢判断函数返回了 # 代表玩家赢 输出结果 并结束这一局游戏
					 {
						 system("cls");
						 DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						 printf("玩家赢！\nPlaer Win！\n");
						 break;
					 }
					 else if (ret == '*')	//如果输赢判断函数返回了 * 代表玩家赢 输出结果 并结束这一局游戏
					 {
						 system("cls");
						 DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						 printf("电脑赢！\nComputer Win！\n");
						 break;
					 }
					 else if (ret == 'P')	//如果输赢判断函数返回了 P 代表 平局 输出结果 并结束这一局游戏
					 {
						 system("cls");
						 DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						 printf("平局！\nNoBody Win！\n");
						 break;
					 }
					 else if (ret == 'C')	//如果输赢判断函数返回了 C 代表游戏还没结束 继续下棋
					 {
						 ;
					 }
				}

				if (ComputerMove(board, Curr_BoradRow, Curr_BoradCol) == TRUE)
				{
					
					DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
					Sleep(700);
					if (GameRound >= 2)
					{
						ret = WhoIsWin(board, Curr_BoradRow, Curr_BoradCol);
						if (ret == '#')		//如果输赢判断函数返回了 # 代表玩家赢 输出结果 并结束这一局游戏
						{
							system("cls");
							DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
							printf("玩家赢！\nPlaer Win！\n");
							break;
						}
						else if (ret == '*')	//如果输赢判断函数返回了 * 代表玩家赢 输出结果 并结束这一局游戏
						{
							system("cls");
							DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
							printf("电脑赢！\nComputer Win！\n");
							break;
						}
						else if (ret == 'P')	//如果输赢判断函数返回了 P 代表 平局 输出结果 并结束这一局游戏
						{
							system("cls");
							DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
							printf("平局！\nNoBody Win！\n");
							break;
						}
						else if (ret == 'C')	//如果输赢判断函数返回了 C 代表游戏还没结束 继续下棋
						{
							;
						}
					}
					
				}
			}
			else if(PlayerMove_return== 0)
			{
				printf("输入的坐标非法！正确输入方式为 行 列\n例子 1 2 设置1行2列的数据为#\n");
				system("pause");
				system("cls");
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
			}
			else
			{
				printf("要走的位置已经被走过，请重新选择位置\n");
				system("pause");
				system("cls");
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
			}
			
		}
		else		//电脑先走
		{
			
			if (ComputerMove(board, Curr_BoradRow, Curr_BoradCol) == TRUE)
			{

				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
				Sleep(700);
				if (GameRound >= 2)
				{
					ret = WhoIsWin(board, Curr_BoradRow, Curr_BoradCol);
					if (ret == '#')		//如果输赢判断函数返回了 # 代表玩家赢 输出结果 并结束这一局游戏
					{
						system("cls");
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						printf("玩家赢！\nPlaer Win！\n");
						break;
					}
					else if (ret == '*')	//如果输赢判断函数返回了 * 代表玩家赢 输出结果 并结束这一局游戏
					{
						system("cls");
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						printf("电脑赢！\nComputer Win！\n");
						break;
					}
					else if (ret == 'P')	//如果输赢判断函数返回了 P 代表 平局 输出结果 并结束这一局游戏
					{
						system("cls");
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						printf("平局！\nNoBody Win！\n");
						break;
					}
					else if (ret == 'C')	//如果输赢判断函数返回了 C 代表游戏还没结束 继续下棋
					{
						;
					}
				}

				while (1)
				{
					int PlayerMove_return = PlaerMove(board, Curr_BoradRow, Curr_BoradCol);
					if (PlayerMove_return == 1)
					{
						system("cls");
						GameRound++;
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
						if (GameRound >= 2)
						{
							ret = WhoIsWin(board, Curr_BoradRow, Curr_BoradCol);
							
						}
						break;
					}
					else if (PlayerMove_return == 0)
					{
						printf("输入的坐标非法！正确输入方式为 行 列\n例子 1 2 设置1行2列的数据为#\n");
						system("pause");
						system("cls");
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
					}
					else
					{
						printf("要走的位置已经被走过，请重新选择位置\n");
						system("pause");
						system("cls");
						DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
					}
				}
				




			}

			if (ret == '#')		//如果输赢判断函数返回了 # 代表玩家赢 输出结果 并结束这一局游戏
			{
				system("cls");
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
				printf("玩家赢！\nPlaer Win！\n");
				break;
			}
			else if (ret == '*')	//如果输赢判断函数返回了 * 代表玩家赢 输出结果 并结束这一局游戏
			{
				system("cls");
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
				printf("电脑赢！\nComputer Win！\n");
				break;
			}
			else if (ret == 'P')	//如果输赢判断函数返回了 P 代表 平局 输出结果 并结束这一局游戏
			{
				system("cls");
				DisplayBoard(board, Curr_BoradRow, Curr_BoradCol);
				printf("平局！\nNoBody Win！\n");
				break;
			}
			else if (ret == 'C')	//如果输赢判断函数返回了 C 代表游戏还没结束 继续下棋
			{
				;
			}
			



		}
			



	}
	

	system("pause");
	system("cls");
}


void start()	//进行选择
{
	int user_select = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &user_select);
		switch (user_select)
		{
		case 1:
			game();
			break;
		case 2:
			{
				int sec_user_select = -1;
				while(1)
				{
					printf("输入 1 设置 棋盘的行与列 \n输入 2 设置 玩家或电脑谁先走\n开始输入->:");
					scanf("%d", &sec_user_select);
					if (sec_user_select == 1)
					{
						short Set_BoradRow = 0;
						short Set_BoradCol = 0;
						printf("输入要设置的行数与列数\n");
						printf("输入4 4 则设置为4行4列\n");
						printf("设置的行数与列数不能超过 %d 行,不能低于 %d 行\n", (MAX_COL + MAX_ROW) / 2, (MIN_ROW + MIN_COL) / 2);
						scanf("%hd %hd", &Set_BoradRow, &Set_BoradCol);
						SetBoardRowAndCol(Set_BoradRow, Set_BoradCol);
						break;
					}
					else if (sec_user_select == 2)
					{
						int PlaerOrComputer = -1;
						printf("输入1代表玩家先走\n输入非1的数字设置为电脑先走\n开始输入->:");
						scanf("%d", &PlaerOrComputer);
						if (PlaerOrComputer != -1 && PlaerOrComputer == _PLAYER_FIRST_MOVE)
						{
							SetPlayerFirstMoveOrComputerFirstMove(_PLAYER_FIRST_MOVE);
							printf("设置为玩家先走\n");
							system("pause");
							system("cls");
							break;
						}
						else
						{
							SetPlayerFirstMoveOrComputerFirstMove(_COMPUTER_FIRST_MOVE);
							printf("设置为电脑先走\n");
							system("pause");
							system("cls");
							break;
						}
					}

				} 
				break;
				
				
			}
		case 0:
			printf("感谢游玩!\n");
			system("pause");
			break;

		default:
			printf("输入有误，请重新输入！\n");
			system("pause");
			system("cls");
			break;
		}
	} while (user_select);

	
}

int main()
{
	start();
	return 0;
}