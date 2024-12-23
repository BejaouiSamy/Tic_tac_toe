#include "tic_tac.h"

extern char player;
extern char opponent;

void	play_tictac(int whose_turn)
{
	int move_index;	
	char board[SIDE][SIDE];
	int move[SIDE * SIDE];
	char temp_board[SIZE][SIZE];
	int i;
	int j;
	int x;
	int y;
	int moves;


	x = 0;
	y = 0;
	move_index = 0, x, y;
	initialise(board, move);
	show_instructions();
	while(!game_over(board) && move_index != SIDE * SIDE)
	{
		if (whose_turn == COMPUTER)
		{
			i = 0;
			while(i < SIZE)
			{
				j = 0;
				while(j < SIDE)
				{
					if (board[i][j] == 'X')
						temp_board[i][j] = 'x';
					else if (board[i][j] == 'O')
						temp_board[i][j] = 'o';
					else
						temp_board[i][j] = '_';
					j++;
				}
				i++;
			}
			struct Move this_move = find_best_move(temp_board);
			x = this_move.row;
			y = this_move.col;

			board[x][y] = COMPUTERMOVE;
			printf("COMPUTER put %c in cell %d %d\n", COMPUTERMOVE, x, y);
			show_board(board);

			move_index++;
			whose_turn = HUMAN;
		}
		else if (whose_turn == HUMAN)
		{
			printf("Enter move (1-9) : ");
			scanf("%d", &moves);
			if (moves < 1 || moves > 9)
			{
				printf("Invalid unput !");
				continue;
			}

			x = (moves - 1) / SIDE;
			y = (moves - 1) % SIDE;

			if (board[x][y] == ' ')
			{
				board[x][y] = HUMANMOVE;
				show_board(board);
				move_index++;
				if (game_over(board))
				{
					declare_winner(HUMAN);
					return;
				}
				whose_turn = COMPUTER;
			}
			else
				printf("Cell %d is already occupied.\n", moves);
		}
	}
	if (!game_over(board) && move_index == SIDE * SIDE)
		printf("That's a draw man !");
	else
	{
		//Toggle the user to declare the actuel winner
		if (whose_turn == COMPUTER)
			whose_turn = HUMAN;
		else if (whose_turn == HUMAN)
			whose_turn = COMPUTER;
		//declare de winner
		declare_winner(whose_turn);
	}
}

struct Move find_best_move(char board[SIZE][SIZE])
{
	int best_val;
	int i;
	int j;
	int move_val;

	best_val = -1000;
	struct Move best_move;
	best_move.row = -1;
	best_move.col = -1;
	i = 0;
	while(i < SIZE)
	{
		j = 0;
		while(j < SIZE)
		{
			if (board[i][j] == '_')
			{
				board[i][j] = player;
				move_val = minimax(board, 0, false);
				board[i][j] = '_';
				if (move_val > best_val)
				{
					best_move.row = i;
					best_move.col = j;
					best_val = move_val;
				}
			}
			j++;
		}
		i++;
	}
	return (best_move);
}