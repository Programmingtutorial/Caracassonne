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
void printBoard(Board *p, FILE *b);

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
int checksPosition(int tile, int direction, Board *p, Tiles *t);

/**
*
*/
Board* placeTile(int tile, Tiles *t, Board *p);

#endif
