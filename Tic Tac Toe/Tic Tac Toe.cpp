// Tic Tac Toe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h" 
#include "time.h"

int filled = 0;
//Functions
void display(char[]);
int whogoesfirst();
void gameover();
void checkwin();
void player(char[], char);
int checkgrid(char[]);

int main()
{
	
	char box[10];
	char Player = 'O';
	int turn, flag = 0;
	for (int i = 0; i < 10; i++) {
		box[i] = ' ';
	}

	display(box);


	turn = whogoesfirst();
	if (turn == 0) {
		printf_s("Player 1 goes first\n");
		player(box, 'O');
	}
	else
	{
		printf_s("Player 2 goes first\n");
		player(box, 'X');
	}
	printf_s("\n");

	flag = turn + 1;

	while (checkgrid(box) != 1)
	{
		flag = (flag % 2) ? 0 : 1;
		if (flag == 1) {
			printf_s("Player 1 turn\n");
			player(box, 'O');
		}
		else
		{
			printf_s("Player 2 turn\n");
			player(box, 'X');
		}
		
		printf_s("\n");
	}

}

void display(char box[])
{
	printf_s("| %c | %c | %c |\n", box[1], box[2], box[3]);
	printf_s("| %c | %c | %c |\n", box[4], box[5], box[6]);
	printf_s("| %c | %c | %c |\n", box[7], box[8], box[9]);
}

int whogoesfirst()
{
	int x;
	srand((unsigned)time(NULL));
	x = rand() % 2;
	return x;
}

void player(char box[], char symbol)
{
	int pos;
	//system("cls");
	printf_s("Enter the location");
	scanf_s("%d", &pos);
	if (box[pos] == ' ')
	{
		if (symbol == 'O')
		{
			box[pos] = 'O';
		}
		else
		{
			box[pos] = 'X';
		}
	}
	else
	{
		printf_s("Invalid move\n");
	}
	filled++;
	display(box);
	printf_s("%d", filled);
	
}

int checkgrid(char box[])
{
	if (filled == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}