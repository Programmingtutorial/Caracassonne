#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tile_length 6

void exampleTiles(FILE *tile_file, char* ex[]);
int randomTileNumber(void);
void freeArray(char **a, int m);

/*
Pierwszy comand line argument to nazwa pliku z oryginalnymi klockami (zak³adam, ¿e jest podstawowych klocków jest 14).
Drugi argument to liczba klocków do wygenerowania.
*/

int main(int argc, char *argv[]) {
	char* example[14];
	int amount, seed, random;
	char** tile;

	time_t tt;
	seed = time(&tt);
	srand(seed);

	FILE *tile_file;

	if (argc > 2) {
		amount = atoi(argv[2]);
		tile_file = fopen(argv[1], "r");
		exampleTiles(tile_file, example);

		tile_file = fopen(argv[1], "w");

		tile = (char**)malloc(amount * sizeof(char*));
		for (int i = 0; i < amount; i++) {
			tile[i] = (char*)malloc(tile_length * sizeof(char));
			random = randomTileNumber();
			tile[i] = example[random];
			fprintf(tile_file, "%s", tile[i]);
		}
		fclose(tile_file);
		
		freeArray(tile, amount);
	}

}

void exampleTiles(FILE *tile_file, char *ex[]) {
	char s = '0';
	int i = 0, k;

	if (tile_file == NULL) {
		printf("Fail to open tile file.\n");
		exit(-1);
	}
	
	while (i < 14) {
		char* temp = (char*)malloc(tile_length * sizeof(char));
		for (k = 0; k < tile_length; k++) {
			s = getc(tile_file);
			if (s == EOF)
				break;
			temp[k] = s;
		}
		temp[k] = '\0';
		ex[i] = temp;
		
		if (s == EOF)
			break;

		i++;
	}
}

void generateTiles(FILE *tile_file, int amount, char** tile, char* ex[]) {
	int random;

	tile = (char**)malloc(amount * sizeof(char*));
	for (int i = 0; i < amount; i++) {
		tile[i] = (char*)malloc(tile_length * sizeof(char));
		random = randomTileNumber();
		tile[i] = ex[random];
		fprintf(tile_file, "%s", tile[i]);
	}
}

int randomTileNumber(void) {
	int tile, max = 13;

	// Losowanie liczby z zakresu <0, 13>.
	tile = (int)(rand() % (max + 1));

	return tile;
}

void freeArray(char **a, int m) {
	int i;
	for (i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
}