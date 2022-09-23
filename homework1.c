#define _CRT_SECURE_NO_WARNINGS 1
//我用vs写的，用不惯dev，VS2019不让用scanf，所以有了上面那行,别的编译器可以删了哈
/*自动裁判输赢我只写了三子棋的，想扩充的话，我只能想到switch case挨个写一遍的笨方法,
对于任意的N子琪判定,学长有什么改进意见可以加我qq2395624242*/
#define ROW 3
#define COL 3
//ROW COL数字可以更改,如果更改的话，把IsWin函数注释掉。
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void menu()
{
	printf("************************\n");
	printf("***1 . play    0.exit***\n");
	printf("************************\n");
}
void InitBoard(char board[ROW][COL], int row, int col) {
	int i;
	int j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';

		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i;
	int j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
		{
			//打印一行数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	while (1) {
		printf("玩家走\n");
		printf("请输入要下的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该处已经落子\n");
			}

		}
		else {
			printf("坐标非法，请重新输入!\n");
		}
			
	}
	
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("电脑走\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		}
	}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL],int row,int col) {
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[1][j] != ' ')
			return board[1][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';

}



void game() {
	char ret = 0;
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢");
	else if (ret == '#')
		printf("电脑赢");
	else
		printf("平局");

}
void test() {
	int input;
	srand((unsigned int)time(NULL));//产生随机数
	do
	{
		menu();
		printf("请输入0或者1\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("%d子棋游戏开始\n",ROW);
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("非法数字，请重新输入\n");
			break;
		}
	} while (input);
}

int main() {
	test();

	return 0;
}