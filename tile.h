#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <stdio.h>

#define tiles_number 14
#define tile_length 6
#define NO_TILES -3
/**
* Structure containing blocks of tiles and information about the rotation.
*/
struct Tile {
	char* tiles[tiles_number];
	char rotate;
	int no_tiles;
};
typedef struct Tile Tiles;


/**
* Type of ennum of tile rotation.
*/
enum {
	N,	// Do not rotate
	R,	// Rotate 90 degrees to the RIGHT.
	L,	// Rotate 90 degrees to the LEFT.
	D,	// Rotate 180 degress.
};


/**
*
*/
Tiles* initializeTileArray(FILE *tile, Tiles *t);

/**
*
*/
int printAvailableTiles(Tiles *t);

/**
*
*/
Tiles* deleteUsedTile(int number, Tiles *t);

/**
*
*/
Tiles* rotateTile(int number, Tiles *t);

/**
*
*/
Tiles* rotateRight(int number, Tiles *t);

/**
*
*/
Tiles* rotateLeft(int number, Tiles *t);

/**
*
*/
Tiles* rotateDown(int number, Tiles *t);

/**
*
*/
int canChooseTile(int number, Tiles *t);

/**
*
*/
Tiles* checkNumberOfTiles(Tiles *t);


#endif