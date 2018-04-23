#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1\tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board\board.h"

#include <stdio.h>
#include <stdlib.h>

#define PLAYER1 1
#define PLAYER2 2

/**
*
*/
void hello();

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
Board* selectPlace(int player, Board *p);

/**
*
*/
int player1(Board *p, Tiles *t);

/**
*
*/
int player2(Board *p, Tiles *t);


#endif
