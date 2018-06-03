#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "tile.h"
#include "board.h"

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
Tiles* makeMove(Board *p, Tiles *t);

#endif
