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

Board* initializeBoard(FILE *board_player, Board *p) {
	int i, j, k = 0, stop = 0;
	char s = '0';

	if (board_player == NULL) {
		printf("Fail to open the file.\n");
		exit(-1);
	}

	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			char *temp = (char*)malloc(tile_length * sizeof(char));
			while ((s = getc(board_player)) != ' ') {
				if (s == EOF)
					break;
				if (s != '\n') {
					temp[k] = s;
					k++;
				}
			}
			if (s == EOF)
				break;
			temp[k] = '\0';
			p->board[i][j] = temp;
			k = 0;
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
			fprintf(board, "%.*s ", tile_length - 1, p->board[i][j]);
		}
		fprintf(board, "\n");
	}
}

void fillTileFile(FILE *tile, Tiles *t) {
	for (int i = 0; i < tiles_number; i++) {
		fprintf(tile, "%.*s\n", tile_length - 1, t->tiles[i]);
	}
}

/* Function places selected tile in the middle of the board as a first move. */
Board* firstMove(int tile, Tiles *t, Board *p) {
	p->board[(length / 2) - 1][(length / 2) - 1] = t->tiles[tile];

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
	}

	return p;
}

/* Function takes first available tile from tile array.
It set information about taken tile number in Tiles structure (checkedTile). */
int takeTile(int number, Tiles *t) {
	int i;
	const char *empty = "00000\n";

	for (i = number; i < tiles_number; i++) {
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
	else {	// Tu obracam klocek w ka¿d¹ stronê i patrze czy pasuje 
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

Tiles* makeMoveAUTO(Board *p, Tiles *t, FILE *board_player, FILE *tile) {
	int stop, number, counter = 0, placed = 0;

	initializeBoard(board_player, p);
	initializeTileArray(tile, t);
	printBoard2(p);
	stop = printAvailableTiles(t);
	if (stop == OK) {
		checkBoard(p);
		printf("row %d	column %d\n", p->row, p->column);
		if (p->firstPlacing == 0) {	//DZIA£A
			number = randomFirstTile();
			firstMove(number, t, p);
			deleteUsedTile(number, t);
		}
		else {
			number = takeTile(0, t);
			printf("TILE NUMBER: %d\n", number);
			placed = canPlaceTileAUTO(number, p, t);
			while ((placed = canPlaceTileAUTO(number, p, t)) != OK && number < 14) {
				number = takeTile(t->checkedTile + 1, t);
				printf("TILE NUMBER: %d\n", number);
			}
			if (placed == OK) {
				placeTile(number, t, p);
				deleteUsedTile(number, t);
			}
			else if (number == 14) {
				printf("Nie uda³o siê znaleŸæ klocka, ktory pasuje :c \n");
				//findNextTile(p);
			}
		}
		printBoard2(p);
	}

	return t;
}
