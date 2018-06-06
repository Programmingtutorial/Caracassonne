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
* Function reads tiles from the file and put them into array.
*/
Tiles* initializeTileArray(FILE *tile, Tiles *t);


/**
* Functions printing available tiles.
The second one prints it in a way which is easier for a user to read.
*/
int printAvailableTiles(Tiles *t);
int printAvailableTiles2(Tiles *t);


/**
* Function changes used tiles to "00000" string.
It makes the tile unpossible to be used again.
*/
Tiles* deleteUsedTile(int number, Tiles *t);


/**
* Function rotates tile according to the given direction.
*/
Tiles* rotateTile(int number, Tiles *t);


/**
* Function rotates tile to the right.
*/
Tiles* rotateRight(int number, Tiles *t);


/**
* Function rotates tile to the left.
*/
Tiles* rotateLeft(int number, Tiles *t);


/**
* Function rotates tile down.
*/
Tiles* rotateDown(int number, Tiles *t);


/**
* Function rotates tile up.
*/
int canChooseTile(int number, Tiles *t);


/**
* Function checks if there is any tile left.
*/
Tiles* checkNumberOfTiles(Tiles *t);


/**
* Function free allocated memory while reading tiles form a file.
*/
Tiles* freeMemory(Tiles *t);

#endif
