#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

#define length 100

/**
* Array- board to place tiles in.
*/
char tab1[length][length];

int firstPlacing = 0;


/**
* Initialize board.
* Setting each cell to "0".
*/
void setBoard(char);


/**
* Print board.
*/
void printBoard(char);


/**
* Check if placing tile in selected place is possible.
*/
int canplaceTile(char);


/**
* Placinf tile on a board.
*/
void placeTile(char);



#endif