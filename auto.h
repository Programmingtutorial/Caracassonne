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
Board* firstMove(int tile, Tiles *t, Board *p);

/**
*
*/
Board* initializeBoard(FILE *board_player, Board *p);

/**
*
*/
int checkBoard(Board *p);

/**
*
*/
void fillBoardFile(FILE *board, Board *p);

/**
*
*/
void fillTileFile(FILE *tile, Tiles *t);


#endif
