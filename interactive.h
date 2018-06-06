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
* Function asks a user to select tile.
*/
int selectTile(Tiles *t);


/**
* Function ask user to select roatation.
*/
Tiles* selectRotation(Tiles *t);


/**
* Function ask user to select the place on a board where to put selected tile.
*/
Board* selectPlace(Board *p);


/**
* Function makes move for interactive mode.
*/
Tiles* makeMove(Board *p, Tiles *t);

#endif
