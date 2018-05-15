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
	char rotate;	// Information about rotation.
	int no_tiles;	// Information amount of tiles left.
};
typedef struct Tile Tiles;


/**
* Type of ennum of tile rotation and used while checking if you can place tile.
*/
enum {
	U,
	R,	// Rotate 90 degrees to the RIGHT.
	D,	// Rotate 180 degress.
	L,	// Rotate 90 degrees to the LEFT.
	N,	// Do not rotate
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
void deleteUsedTileAUTOMODE(int number, FILE *tile_auto);

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

/**
*
*/
Tiles* freeMemory(Tiles *t);

#endif