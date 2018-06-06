#ifndef AUTO_H
#define AUTO_H

#include "tile.h"
#include "board.h"
#include "interactive.h"

#include <stdlib.h>
#include <stdio.h>

/**
* Function reads board form a file and set board array.
*/
Board* initializeBoard(FILE *board_auto, Board *p);


/**
* Function writes board array to the file.
*/
void fillBoardFile(FILE *board, Board *p);


/**
* Function writes tile array to the file.
*/
void fillTileFile(FILE *tile, Tiles *t);


/**
* Function makes the first move.
It places randomly selected tile on down right corner of the board.
*/
Board* firstMove(int tile, Tiles *t, Board *p);


/**
* Function randomly select tile.
*/
int randomFirstTile(void);


/**
* Function checks if there is any tile on a board already.
If not, places a tile in a middle of a board as a first move- fistMove() function.
Otherwise it takes first free place from a right. 
If there is already any tile on a board function sets infromation about row and column where this tile is.
*/
Board* checkBoard(Board *p);


/**
* Function takes the next tile in realtion to previously checked.
*/
int takeTile(int number, Tiles *t);


/**
* Function checks if the tile can be placed.
*/
int canPlaceTileAUTO(int number, Board *p, Tiles *t);


/**
* Function makes the move automatically.
*/
Tiles* makeMoveAUTO(Board *p, Tiles *t, FILE *board_auto, FILE *tile);


#endif
