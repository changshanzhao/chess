#define _CRT_SECURE_NO_WARNINGS 1
//����vsд�ģ��ò���dev��VS2019������scanf������������������,��ı���������ɾ�˹�
#define ROW 5
#define COL 5
//ROW COL���ֿ��Ը���
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
//���������������ҵ���� N����!
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
	printf("�����\n");
	printf("������Ҫ�µ�����\n");
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
				printf("�ô��Ѿ�����\n");
				break;
			}

		}
		else {
			printf("����Ƿ�������������!\n");
			break;
		}
			
	}
	
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("������\n");
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
		//��������
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


}