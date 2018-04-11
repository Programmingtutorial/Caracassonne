#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <stdio.h>

/**
* Structure containing blocks of tiles and information about the rotation.
*/
typedef struct Tile Tiles;


/**
* Type of ennum of tile rotation.
*/
enum {
	N,	// Do not rotate
	R,	// Rotate 90 degrees to the RIGHT.
	L,	// Rotate 90 degrees to the LEFT.
	D,	// Rotate 180 degress.
} rotate;


/**
* Reads tiles for a file and rewrite them to the array (in Tiles).
*/
Tiles* initializeTileArray(FILE *tile, Tiles *a);


/**
* Print tiles that still can be used.
*/
void printAvailableTiles(Tiles *a);


/**
* Delete used tile form array of tiles.
*/
Tiles* deleteUsedTile(Tiles *a, int i);


/**
* Take number of tile and direction of rotation and rotate chosen tile.
*/
Tiles* rotateTile(Tiles *a, int number, char c);

/**
* Check if it is possible to chose selected tile.
Returns 0 if chosing such tile is unpossible. Otherwise returns 0.
*/
int canChoseTile(Tiles *a, int number);

#endif