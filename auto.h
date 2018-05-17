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
