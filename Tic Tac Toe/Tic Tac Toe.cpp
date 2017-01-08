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
int checkwin(char[]);
void player(char[], char);
int checkgrid(char[]);
void displayResult(char box[]);

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
	
		while (checkgrid(box) != 1 && checkwin(box) == -1)
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
		displayResult(box);
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
again:
	printf_s("Enter the location");
	scanf_s("%d", &pos);

	if (box[pos] == ' ')
	{
		if (symbol == 'O')
		{
			box[pos] = 'O';
			filled++;
		}
		else
		{
			box[pos] = 'X';
			filled++;
		}
	}
	else
	{
		printf_s("Invalid move! Try again");
		goto again;
	}
	
	display(box);
	//printf_s("%d", filled);
	
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

int checkwin(char box[])
{
	/*checking rows*/
	if (box[1] == box[2] && box[2] == box[3] && box[2] != ' ')
		return box[2] == 'X' ? 10 : -10;

	if (box[4] == box[5] && box[5] == box[6] && box[4] != ' ')
		return box[4] == 'X' ? 10 : -10;

	if (box[7] == box[8] && box[8] == box[9] && box[8] != ' ')
		return box[8] == 'X' ? 10 : -10;

	/*checking columns*/
	if (box[1] == box[4] && box[4] == box[7] && box[1] != ' ')
		return box[1] == 'X' ? 10 : -10;

	if (box[2] == box[5] && box[5] == box[8] && box[2] != ' ')
		return box[2] == 'X' ? 10 : -10;

	if (box[3] == box[6] && box[6] == box[9] && box[3] != ' ')
		return box[3] == 'X' ? 10 : -10;

	/*checking diagonals*/
	if (box[1] == box[5] && box[5] == box[9] && box[1] != ' ')
		return box[1] == 'X' ? 10 : -10;

	if (box[3] == box[5] && box[5] == box[7] && box[3] != ' ')
		return box[3] == 'X' ? 10 : -10;

	return -1;
}

/* Game Result*/
void displayResult(char box[]) {
	int x = checkwin(box);
	if (x == 10) {
		printf("Player X won\n");
	}
	else if (x == -10) {
		printf("Player O won\n");
	}
	else {
		printf("....DRAW...\n");
	}
	display(box);
}
