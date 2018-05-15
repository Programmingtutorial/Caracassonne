#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Project\Project/auto.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Function reads tiles from the file and put them into array. */
Tiles* initializeTileArray(FILE *tile, Tiles *t) {
	char s = '0';
	int i = 0, k;

	if (tile == NULL) {
		printf("Fail to open tile.txt\n");
		exit(-1);
	}

	while (i < tiles_number) {
		char *temp = (char*)malloc(tile_length * sizeof(char));
		for (k = 0; k < tile_length; k++) {
			s = getc(tile);
			if (s == EOF)
				break;
			temp[k] = s;
		}
		temp[k] = '\0';
		t->tiles[i] = temp;
		if (s == EOF)
			break;
		i++;
	}

	return t;
}

/*Function prints tiles which can be used.
It takes as a parameter a pointer to the Tiles structure. 
It returns NO_TILES if there are no tiles or 1 otherwise. */
int printAvailableTiles(Tiles *t) {
	const char *empty = "00000";

	// Checking if there are any tiles (checkNumberofTiles() function).
	checkNumberOfTiles(t);
	if (t->no_tiles == NO_TILES) {
		printf("There are no tiles left.");
		return NO_TILES;
	}
	// Printing available tiles.
	printf("Available Tiles: \n");
	for (int i = 0; i < tiles_number; i++) {
		if (strcmp(t->tiles[i], empty) != 0)
			printf("%d: %s", i + 1, t->tiles[i]);
	}
	printf("\n\n");

	return 1;
}

Tiles* deleteUsedTile(int number, Tiles *t) {	
	t->tiles[number] = "00000";

	return t;
}

void deleteUsedTileAUTOMODE(int number, FILE *tile_auto) {
	// FGETS ??? 
}


Tiles* rotateTile(int number, Tiles *t) {
	
	switch (t->rotate) {
		case 'R': // Right.
			rotateRight(number, t);
			break;

		case 'L':	// Left.
			rotateLeft(number, t);
			break;

		case 'D':	// Down.
			rotateDown(number, t);
			break;

		default:
			break;
	}
	
	return t;
}

/* Function rotates the tile to the right. */
Tiles* rotateRight(int number, Tiles *t) {
	int i = 2;
	char temp;
	char rem = t->tiles[number][3];

	while (i > 0) {
		temp = t->tiles[number][i + 1];
		t->tiles[number][i + 1] = t->tiles[number][i];
		t->tiles[number][i] = temp;
		i--;
	}
	t->tiles[number][0] = rem;
	
	return t;
}

/* Function rotates the tile to the letf. */
Tiles* rotateLeft(int number, Tiles *t) {
	int i = 1;
	char temp;
	char rem = t->tiles[number][0];

	while (i < 3) {
		temp = t->tiles[number][i - 1];
		t->tiles[number][i - 1] = t->tiles[number][i];
		t->tiles[number][i] = temp;
		i++;
	}
	t->tiles[number][3] = rem;

	return t;
}

/* Function rotates the tile down. */
// Does not work well!!!
Tiles* rotateDown(int number, Tiles *t) {
	char temp;
	
	temp = t->tiles[number][0];
	t->tiles[number][1] = t->tiles[number][2];
	t->tiles[number][2] = temp;

	temp = t->tiles[number][1];
	t->tiles[number][1] = t->tiles[number][3];
	t->tiles[number][3] = temp;

	return t;
}

/*Takes number of a tile as a parameter.
Returns 0 if chosing such tile is unpossible. Otherwise returns 0.*/
int canChooseTile(int number, Tiles *t) {
	const char *empty = "00000";
	checkNumberOfTiles(t);

	if (t->no_tiles == NO_TILES)
		return NO_TILES;
	if (strcmp(t->tiles[number - 1], empty) == 0)
		return 0;
	else
		return 1;
}


Tiles* checkNumberOfTiles(Tiles *t) {
	const char *empty = "00000";
	int tile = 0;

	// Comparing each string from tiles[] array with *empty ("00000") string.
	for (int i = 0; i < tiles_number; i++) {
		/* If one of the stings form tiles[] array is different from *empty string 
		there is at least one tile. */
		if (strcmp(t->tiles[i], empty) != 0) {
			tile = 1;
			break;
		}
	}
	// If there are no tiles in tiles[] array change information about tiles to NO_TILES.
	if (tile == 0)
		t->no_tiles = NO_TILES;

	return t;
}

Tiles* freeMemory(Tiles *t) {
	for (int i = 0; i < tiles_number; i++) {
		free(t->tiles[i]);
	}

	return t;
}