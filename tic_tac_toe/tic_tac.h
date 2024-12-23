#ifndef TIC_TAC_H
#define TIC_TAC_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COMPUTER 1
#define HUMAN 2
#define SIDE 3
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'
#define SIZE 3

struct Move {
    int row, col;
};

extern char player;
extern char opponent;

bool	is_move_left(char board[SIZE][SIZE]);
int evaluation(char b[SIZE][SIZE]);
int minimax(char board[SIZE][SIZE], int depth, bool is_max);
void	declare_winner(int whose_turn);
int row_crossed(char board[][SIDE]);
int col_crossed(char board[][SIDE]);
int diagonal_crossed(char board[][SIDE]);
int game_over(char board[][SIDE]);
struct Move find_best_move(char board[SIZE][SIZE]);
void	play_tictac(int whose_turn);
void	initialise(char board[][SIDE], int moves[]);
void	show_board(char board[][SIDE]);
void	show_instructions();

#endif