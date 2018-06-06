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
* Functions to print board array.
The second one prints board in a way in which it is easier to read for a user.
*/
void printBoard(Board *p);
void printBoard2(Board *p);

/**
* Function sets board array with 0's.
*/
Board* setBoard(Board *p);

/**
* Function checks whether it is possible to place the tile. 
Checks each tile around the one you want to place.
It returns OK if the tile can be placed in a seleced place.
*/
int canplaceTile(int tile, Board *p, Tiles *t);

/**
* Function checks whether the tile fits (row, column) to the tile next to it (int tile).
For example for row = 0, column = 1 function checks tile on the right.
For row = 1, column = 1 function checks tile in the row above. 
*/
int checkPosition(int tile, int directiontile, int directionplaced, int row, int column, Board *p, Tiles *t);


/**
* Function place selected tile on a selected place.
*/
Board* placeTile(int tile, Tiles *t, Board *p);


#endif
