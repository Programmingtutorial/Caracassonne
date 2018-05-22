#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printBoard(Board *p) {
	int i, j;

	/* Prints columns numbers from A to J. */
	printf("    ");
	for (char c = 'A'; c <= 'J'; ++c)
		printf("%c     ", c);

	printf("\n");

	for (i = 0; i < length; i++) {
		if (i + 1 < 10) {
			printf(" %d ", i + 1);
		}
		else {
			printf("%d ", i + 1);
		}
		for (j = 0; j < length; j++) {
			// Prints string without new line.
			printf("%.*s ", tile_length - 1, p->board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printBoard2(Board *p) {
	int i, j;

	printf("\n");
	printf("   |");

	for (char c = 'A'; c <= 'J'; ++c) {
		printf("   %c   ", c);
		printf("|");
	}

	printf("\n");
	printf("------------------------------------------------------------------------------------");
	printf("\n");

	for (i = 0; i < length; i++) {

		printf("   |");

		for (j = 0; j < length; j++) {

			printf("   %c   ", p->board[i][j][0]);
			printf("|");
		}

		printf("\n");
		if (i<9)
			printf(" %d |", i + 1);
		else
			printf("%d |", i + 1);
		for (j = 0; j < length; j++) {

			printf(" %c %c %c ", p->board[i][j][3], p->board[i][j][4], p->board[i][j][1]);
			printf("|");

		}

		printf("\n");
		printf("   |");

		for (j = 0; j < length; j++) {

			printf("   %c   ", p->board[i][j][2]);
			printf("|");
		}

		printf("\n");
		printf("------------------------------------------------------------------------------------");
		printf("\n");

	}
	printf("\n");

}

Board* setBoard(Board *p) {
	int i, j;

	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			p->board[i][j] = "00000";
		}
	}

	return p;
}


int canplaceTile(int tile, Board *p, Tiles *t) {
	const char *empty = "00000";
	int right = 0, left = 0, up = 0, down = 0;

	// If there are no tiles left returns NO_TILES.
	if (t->no_tiles == NO_TILES) {
		return NO_TILES;
	}
	
	// If this is the first move you can place tile anywhere.
	if (p->firstPlacing == 0) {
		// Changing the information about the first placing since the player made the first move.
		p->firstPlacing = 1;
		return 1;
	}
	
	// Checks if there is already any tile on selected place.
	if (strcmp(p->board[p->row][p->column], empty) != 0) {
		printf("This place is already taken\n");
		return ERROR;
	}

	// Dodaj warunki na wychodzenie poza planszê. !!!!!!!

	// Checks if selected tile fits.
	//R = 1, L = 3, U = 0, D = 2;	from type of ennum (tile.h)
	if (strcmp(p->board[p->row][(p->column) + 1], empty) != 0) {
		right = checksPosition(tile, R, 0, 1, p, t);
		if (right == ERROR)
			return ERROR;
	}
	if (strcmp(p->board[p->row][(p->column) - 1], empty) != 0) {
		left = checksPosition(tile, L, 0, -1, p, t);
		if (left == ERROR)
			return ERROR;
	}
	if (strcmp(p->board[(p->row) + 1][p->column], empty) != 0) {
		up = checksPosition(tile, U, 0, 1, p, t);
		if (up == ERROR)
			return ERROR;
	}
	if (strcmp(p->board[(p->row) - 1][p->column], empty) != 0) {
		down = checksPosition(tile, D, -1, 0, p, t);
		if (down == ERROR)
			return ERROR;
	}

	if (right + left + up + down == 0) {
		printf("There is no tile around.\n");
		return ERROR;
	}

	return OK;
}

/* Funkcja sprwdza czy klocek na miejscu (row, column) patrz¹c od wybranego klocka (int tile) pasuje do niego.
Na przyk³ad dla row = 0, column = 1 funkcja sprawdza klocek w kolumnie na prawo.
Dla row = 1, column = 1 funkcja sprawdza klocek w rzêdzie powy¿ej. */
int checksPosition(int tile, int direction, int row, int column, Board *p, Tiles *t) {
	
	if (t->tiles[tile][direction] != p->board[(p->row) + row][(p->column) + column][direction]) {
		printf("Selected tile does not fit.\n");
		return ERROR;
	}
	return OK;
}


Board* placeTile(int tile, Tiles *t, Board *p) {

	p->board[p->row][p->column] = t->tiles[tile];

	return p;
}