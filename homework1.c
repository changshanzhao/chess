#define _CRT_SECURE_NO_WARNINGS 1
//我用vs写的，用不惯dev，VS2019不让用scanf，所以有了上面那行,别的编译器可以删了哈
#define ROW 5
#define COL 5
//ROW COL数字可以更改
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/*void hello(){
	printf("hello world\n");
}
void length(){
	int a = 10;
	int a_length = sizeof a;
	printf("int_length=%d\n",a_length);
	}
int add(int x,int y){
	int z = x + y;
	return z;
}
int main(){
	hello();
	length();
	int p;
	int q;
	printf("please give me two num\n");
	scanf("%d%d",&p,&q);
	int res=add(p,q);
	printf("%d\n",res);
	return 0;
}*/
//下面才是真正的作业哈哈 N子棋!
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
	printf("玩家走\n");
	printf("请输入要下的坐标\n");
	scanf("%d%d", &x, &y);
	while (1) {
		if (x >= 1 && x <= row && y >= 1 && y < col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该处已经落子\n");
				break;
			}

		}
		else {
			printf("坐标非法，请重新输入!\n");
			break;
		}
			
	}
	
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("电脑走\n");
	x = rand() % row;
	y = rand() % col;
	while (1) {
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		
		}
	}
	



void game() {
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
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
	}
}
void test() {
	int input;
	srand((unsigned int)time(NULL));
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


}