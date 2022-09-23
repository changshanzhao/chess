#define _CRT_SECURE_NO_WARNINGS 1
//����vsд�ģ��ò���dev��VS2019������scanf������������������,��ı���������ɾ�˹�
/*�Զ�������Ӯ��ֻд��������ģ�������Ļ�����ֻ���뵽switch case����дһ��ı�����,
���������N�����ж�,ѧ����ʲô�Ľ�������Լ���qq2395624242*/
#define ROW 3
#define COL 3
//ROW COL���ֿ��Ը���,������ĵĻ�����IsWin����ע�͵���
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
			//��ӡһ������
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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
		printf("�����\n");
		printf("������Ҫ�µ�����\n");
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
				printf("�ô��Ѿ�����\n");
			}

		}
		else {
			printf("����Ƿ�������������!\n");
		}
			
	}
	
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("������\n");
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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ");
	else if (ret == '#')
		printf("����Ӯ");
	else
		printf("ƽ��");

}
void test() {
	int input;
	srand((unsigned int)time(NULL));//���������
	do
	{
		menu();
		printf("������0����1\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("%d������Ϸ��ʼ\n",ROW);
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�Ƿ����֣�����������\n");
			break;
		}
	} while (input);
}

int main() {
	test();

	return 0;
}