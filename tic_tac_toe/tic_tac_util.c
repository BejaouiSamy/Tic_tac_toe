#include "tic_tac.h"

extern char player;
extern char opponent;

void	show_board(char board[][SIDE])
{
	printf("\n\n");
	printf("\t\t\t [%c] [%c] [%c] \n\n", board[0][0], board[0][1], board[0][2]);
	printf("\t\t\t [%c] [%c] [%c] \n\n", board[1][0], board[1][1], board[1][2]);
	printf("\t\t\t [%c] [%c] [%c] \n\n", board[2][0], board[2][1], board[2][2]);
}

void	show_instructions()
{
	printf("\t\t\t [1] [2] [3] \n\n");
	printf("\t\t\t [4] [5] [6] \n\n");
	printf("\t\t\t [7] [8] [9] \n\n");
	
	printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void	initialise(char board[][SIDE], int moves[])
{
	int i;
	int j;
	int rand_index;
	int temp;

	i = 0;
	srand(time(NULL));
	while (i < SIDE)
	{
		j = 0;
		while (j < SIDE)
		{
			board[i][j] = ' ';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < SIDE * SIDE)
	{
		moves[i] = i;
		i++;
	}
	i = SIDE * SIDE - 1;
	while (i > 0)
	{
		rand_index = rand() % (i + 1);
		temp = moves[i];
		moves[i] = moves[rand_index];
		moves[rand_index] = temp;
		i--;
	}
}