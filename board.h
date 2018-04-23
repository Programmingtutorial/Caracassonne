#ifndef BOARD_H
#define BOARD_H

#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1\tile.h"

#include <stdio.h>
#include <stdlib.h>


#define length 10

struct board {
	// Player 1.
	char* board_player1[length][length];
	char column1;
	int row1;
	int firstPlacing1;

	// Player 2.
	char* board_player2[length][length];
	char column2;
	int row2;
	int firstPlacing2;
};
typedef struct board Board;

/**
*
*/
void printBoard(int player, Board *p);

/**
*
*/
Board* setBoard(Board *p);

/**
*
*/
int canplaceTile(int player, Board *p, Tiles *t);

/**
*
*/
Board* placeTile(Tiles *t, int tile, int player, Board *p);


#endif
