#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#include <stdio.h>
#include <stdlib.h>

#define length 10
#define ERROR -2

struct board {
	char* board[length][length];
	char column;
	int row;
	int firstPlacing;
};
typedef struct board Board;

/**
*
*/
void printBoard(Board *p);
void printBoard2(Board *p);

/**
*
*/
Board* setBoard(Board *p);

/**
*
*/
int canplaceTile(int tile, Board *p, Tiles *t);

/**
*
*/
int checkPosition(int tile, int directiontile, int directionplaced, int row, int column, Board *p, Tiles *t);
/**
*
*/
Board* placeTile(int tile, Tiles *t, Board *p);

#endif
