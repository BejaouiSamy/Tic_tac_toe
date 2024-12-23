#include "tic_tac.h"

char player = 'x';
char opponent = 'o';

bool	is_move_left(char board[SIZE][SIZE])
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if(board[i][j] == '_')
				return true;
			j++;
		}
		i++;
	}
	return false;
}

int evaluation(char b[SIZE][SIZE])
{
	int row;
	int col;

	row = 0;
	while(row < SIZE)
	{
		if ((b[row][0] == b[row][1]) && (b[row][1] == b[row][2]))
		{
			if(b[row][0] == player)
				return +10;
			else if (b[row][0] == opponent)
				return -10;
		}
		row++;
	}
	col = 0;
	while(col < SIZE)
	{
		if ((b[0][col] == b[1][col]) && (b[1][col] == b[2][col]))
		{
			if(b[0][col] == player)
				return +10;
			else if (b[0][col] == opponent)
				return -10;
		}
		col++;
	}
	if((b[0][0] == b[1][1]) && (b[1][1] == b[2][2]))
	{
		if(b[0][0] == player)
			return +10;
		else if (b[0][0] == opponent)
			return -10;
	}
	if((b[0][2] == b[1][1]) && (b[1][1] == b[2][0]))
	{
		if(b[0][2] == player)
			return +10;
		else if (b[0][2] == opponent)
			return -10;
	}
	return (0);
}

int minimax(char board[SIZE][SIZE], int depth, bool is_max)
{
	int score;
	int best;
	int i;
	int j;
	int val;

	score = evaluation(board);
	if (score == 10)
		return (score - depth);
	if (score == -10)
		return(score + depth);
	if (!is_move_left(board))
		return (0);
	if (is_max)
	{
		best = -1000;
		i = 0;
		while(i < SIZE)
		{
			j = 0;
			while(j < SIZE)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = player;
					val = minimax(board, depth + 1, !is_max);
					if (val > best)
						best = val;
					board[i][j] = '_';
				}
				j++;
			}
			i++;
		}
		return (best);
	}
	else
	{
		best = 1000;
		i = 0;
		while(i < SIZE)
		{
			j = 0;
			while (j < SIZE)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = opponent;
					val = minimax(board, depth + 1, !is_max);
					if (val < best)
						best = val;
					board[i][j] = '_';				
				}
				j++;
			}
			i++;
		}
		return (best);
	}
}

void	declare_winner(int whose_turn)
{
	if (whose_turn == COMPUTER)
		printf("COMPUTER's WON\n");
	else
		printf("HUMAN's WON\n");
}

int row_crossed(char board[][SIDE])
{
	int i;

	i = 0;
	while(i < SIDE)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])
			&& board[i][0] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int col_crossed(char board[][SIDE])
{
	int i;

	i = 0;
	while(i < SIDE)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][0])
			&& board[0][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int diagonal_crossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ' || board[0][2] == board[1][1]
		&& board [1][1] == board[2][0] && board[0][2] != ' ')
		return (1);
	return (0);
}

int game_over(char board[][SIDE])
{
	return (row_crossed(board)) || (col_crossed(board))
		|| (diagonal_crossed(board));
}

int main(void)
{
	play_tictac(COMPUTER);
}