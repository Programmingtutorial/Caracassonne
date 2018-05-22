#ifndef AUTO_H
#define AUTO_H

#include "tile.h"
#include "board.h"
#include "interactive.h"

#include <stdlib.h>
#include <stdio.h>

/**
*
*/
Board* initializeBoard(FILE *board_player, Board *p);

/**
*
*/
void fillBoardFile(FILE *board, Board *p);

/**
*
*/
void fillTileFile(FILE *tile, Tiles *t);

/**
*
*/
Board* firstMove(int tile, Tiles *t, Board *p);

/**
*
*/
int randomFirstTile(void);

/**
*
*/
Board* checkBoard(Board *p);

/**
*
*/
int takeTile(Tiles *t);

/**
*
*/
Tiles* makeMoveAUTO(Board *p, Tiles *t, FILE *board_player, FILE *tile);


#endif