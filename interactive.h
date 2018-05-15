#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1\tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board\board.h"

#include <stdio.h>
#include <stdlib.h>


/**
*
*/
int selectMode();

/**
*
*/
int selectTile(Tiles *t);

/**
*
*/
Tiles* selectRotation(Tiles *t);

/**
*
*/
Board* selectPlace(Board *p);

/**
*
*/
Tiles* makeMove(Board *player, Tiles *t, FILE *board_player, FILE *tile);

#endif
