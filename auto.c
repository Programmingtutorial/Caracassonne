#include "auto.h"
#include "tile.h"
#include "board.h"
#include "interactive.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Zrób funkcje do stawiania klocka. Najpierw sprawdza czy jest ju¿ coœ na planszy. 
Jeœli nie to stawiam na œrodku. 
Jeœli tak to weŸ pierwszy z tablicy klocków i spróbuj ustawiæ go na znalezionym miejscu. 
Spróbuj wszystkich rotacji. 
Jeœli nie pasuje weŸ kolejny i zrób to samo.
Jak wykorzystasz wszystkie klocki to znajd¿ inne miejsce i zrób to samo.
*/

Board* initializeBoard(FILE *board_auto, Board *p) {
	int i, j, k = 0, first = 0;
	char s = '0';

	if (board_auto == NULL) {
		printf("Fail to open board file.\n");
		exit(-1);
	}


	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			char *temp = (char*)malloc(tile_length * sizeof(char));
			while (k < 5) {
				s = getc(board_auto);
				if (s == EOF) {
					if (first == 0)
						setBoard(p);
					break;
				}
				first = 1;
				if (s != '\n') {
					temp[k] = s;
					k++;
				}
			}
			if (s == EOF)
				break;
			
			temp[k] = '\0';
			if (temp[0] == ' ') {
				temp = "00000";
			}
			p->board[i][j] = temp;
			
			k = 0;
			s = getc(board_auto);
		}
		if (s == EOF)
			break;
	}

	return p;
}

void fillBoardFile(FILE *board, Board *p) {
	int i, j;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			if (p->board[i][j][0] != '0')
				fprintf(board, "%.*s ", tile_length - 1, p->board[i][j]);
			else
				fprintf(board, "      ");
		}
		fprintf(board, "\n");
	}
}

void fillTileFile(FILE *tile, Tiles *t) {
	for (int i = 0; i < t->size; i++) {
		if (t->tiles[i][0] != '0')
			fprintf(tile, "%.*s\n", tile_length - 1, t->tiles[i]);
	}
}

/* Function places selected tile in the middle of the board as a first move. */
Board* firstMove(int tile, Tiles *t, Board *p) {
	//p->board[(length / 2) - 1][length- 1] = t->tiles[tile];
	// Skoro może być >14 klocków to lepiej zacząć stawiać od samego dołu.
	p->board[length - 1][length- 1] = t->tiles[tile];

	return p;
}

int randomFirstTile(void) {
	int seed, tile, max = 13;

	time_t tt;
	seed = time(&tt);
	srand(seed);

	// Losowanie liczby z zakresu <0, 13>.
	tile = (int)(rand() % (max + 1));

	return tile;
}

/* Function checks if there is any tile on a board already.
If not, places a tile in a middle of a board as a first move- fistMove() function.
Otherwise it takes first free place from a right. 
If there is already any tile on a board function sets infromation about row and column where this tile is. */
Board* checkBoard(Board *p) {
	const char *empty = "00000";
	int breaker = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (strcmp(p->board[i][j], empty) != 0) {
				p->firstPlacing = 1;
				if (j > 0) {
					p->column = j - 1;	// O jedną kolumnę w lewo od już postawionego klocka.
					p->row = i;
				}
				else {
					p->column = length - 1;
					p->row = i - 1;
				}
				breaker = 1;
				break;
			}
		}
		if (breaker == 1)
			break;
	}

	if (breaker == 0) {
		p->firstPlacing = 0;
		p->row = (length / 2) - 1;
		p->column = length - 1;
	}

	return p;
}

/* Function takes first available tile from tile array.
It set information about taken tile number in Tiles structure (checkedTile). */
int takeTile(int number, Tiles *t) {
	int i;
	const char *empty = "00000\n";

	for (i = number; i < t->size; i++) {
		if (strcmp(t->tiles[i], empty) != 0) {
			t->checkedTile = i;
			break;
		}
	}
	return i;
}

int canPlaceTileAUTO(int number, Board *p, Tiles *t) {

	if (canplaceTile(number, p, t) == OK) {
		return OK;
	}
	else {	// Tu obracam klocek w każdą stronę i patrze czy pasuje 
		rotateRight(number, t);
		if (canplaceTile(number, p, t) == OK) {
			return OK;
		}
		else {
			rotateLeft(number, t);
			if (canplaceTile(number, p, t) == OK) {
				return OK;
			}
			else {
				rotateDown(number, t);
				if (canplaceTile(number, p, t) == OK) {
					return OK;
				}
			}
		}
	}
	return ERROR;
}

Tiles* makeMoveAUTO(Board *p, Tiles *t, FILE *board_auto, FILE *tile) {
	int stop, number, counter = 0, placed = 0;

	initializeBoard(board_auto, p);
	initializeTileArray(tile, t);

	checkNumberOfTiles(t);
	if (t->no_tiles != NO_TILES) {
		checkBoard(p);
		if (p->firstPlacing == 0) {
			number = randomFirstTile();
			firstMove(number, t, p);
			deleteUsedTile(number, t);
		}
		else {
			number = takeTile(0, t);
			//printf("TILE: %d", number);
			placed = canPlaceTileAUTO(number, p, t);
			while ((placed = canPlaceTileAUTO(number, p, t)) != OK) {
				number = takeTile(t->checkedTile + 1, t);
				//printf("TILE: %d", number);
				if (number == t->size) {
					p->column = p->column - 1;
					t->checkedTile = 0;
					number = takeTile(t->checkedTile, t);
					//return ERROR;
				}
			}
			if (placed == OK) {
				placeTile(number, t, p);
				//printf("PLACED");
				deleteUsedTile(number, t);
			}
		}
	}
	else {
		printf("There are no tiles left!\n");
	}

	return t;
}
