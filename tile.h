#ifndef TILE_H
#define TILE_H

#include <stdlib.h>
#include <stdio.h>

#define tiles_number 14
#define tile_length 6
#define NO_TILES -3
#define OK 1
/**
* Structure containing blocks of tiles and information about the rotation.
*/
struct Tile {
	int size;
	char* tiles[tiles_number];
	char rotate;	// Information about rotation.
	int no_tiles;	// Information amount of tiles left.
	int checkedTile;	// Only in AUTO MODE. Information about previously checked tile.
};
typedef struct Tile Tiles;


/**
* Type of ennum of tile rotation and used while checking if you can place tile.
*/
enum {
	U,	// UP
	R,	//(Rotate 90 degrees to the) RIGHT.
	D,	// (Rotate 180 degress) DOWN.
	L,	// (Rotate 90 degrees to the) LEFT.
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
int printAvailableTiles2(Tiles *t);

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

/**
*
*/
Tiles* freeMemory(Tiles *t);

/**
*
*/

#endif
