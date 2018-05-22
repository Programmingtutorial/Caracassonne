#ifndef AUTO_H
#define AUTO_H

#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

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
