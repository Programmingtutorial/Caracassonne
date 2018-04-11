#include <stdio.h>
#include <stdlib.h>

#define tiles_number 14
#define tile_length 6

struct Tile {
	char *tiles[tiles_number];
	int rotate;
};
typedef struct Tile Tiles;

enum {
	N,	// Do not rotate
	R,	// Rotate 90 degrees to the RIGHT.
	L,	// Rotate 90 degrees to the LEFT.
	D,	// Rotate 180 degress.
} rotate;

Tiles* initializeTileArray(FILE *tile, Tiles *a);
void printAvailableTiles(Tiles *a);
Tiles* deleteUsedTile(Tiles *a, int i);
Tiles* rotateTile(Tiles *a, int number, char c);

int main() {
	Tiles program, *a;
	a = &program;

	FILE *tile = fopen("tile.txt", "r");
	initializeTileArray(tile, a);
	fclose(tile);

	printAvailableTiles(a);
	printf("\n");
	//deleteUsedTile(a, 2);
	//printAvailableTiles(a);
	rotateTile(a, 0, L);
	printf("%s", a->tiles[0]);
	
	//printAvailableTiles(a);

	return 0;
}


Tiles* initializeTileArray(FILE *tile, Tiles *a) {
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
		a->tiles[i] = temp;

		if (s == EOF)
			break;

		i++;
	}

	return a;
}

/*Function prints tiles which can be used.*/
void printAvailableTiles(Tiles *a) {
	printf("Available Tiles: \n");
	for (int i = 0; i < tiles_number; i++) {
		if(a->tiles[i] != "00000")
			printf("%d: %s", i+1, a->tiles[i]);
	}
}

/*Function takes board of tiles and number of used tile(i).*/
Tiles* deleteUsedTile(Tiles *a, int i) {
	a->tiles[i] = "00000";
	return a;
} 

/*Function takes number of tile(number) and letter (c) which means direction of rotation. */
Tiles* rotateTile(Tiles *a, int number, char c) {
	char temp, rem;
	int i = 1;

	switch (c) {
	case 1: // Right.
		i = 2;
		rem = a->tiles[number][3];
		while (i > 0) {
			temp = a->tiles[number][i+1];
			a->tiles[number][i+1] = a->tiles[number][i];
			a->tiles[number][i] = temp;
			i--;
		}
		a->tiles[number][0] = rem;
		break;
	case 2:	// Left.
		i = 1;
		rem = a->tiles[number][0];
		while (i < 3) {
			temp = a->tiles[number][i-1];
			a->tiles[number][i - 1] = a->tiles[number][i];
			a->tiles[number][i] = temp;
			i++;
		}
		a->tiles[number][3] = rem;
		break;
	case 3:	// Down.
		temp = a->tiles[number][1];
		a->tiles[number][1] = a->tiles[number][3];
		a->tiles[number][3] = temp;
		break;
	default:
		break;
	}
	return a;
}
