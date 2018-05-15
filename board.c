#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printBoard(Board *p, FILE *board_player) {
	int i, j;

	if (board_player == NULL) {
		printf("Fail to open file.\n");
		exit(-1);
	}

	/* Prints columns numbers from A to J. */
	printf("    ");
	for (char c = 'A'; c <= 'J'; ++c)
		printf("%c      ", c);

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
			printf(" %.*s ", tile_length - 1, p->board[i][j]);
			fprintf(board_player, " %.*s ", tile_length - 1, p->board[i][j]);
		}
		printf("\n");
		fprintf(board_player, "\n");
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
	if ((right = checksPosition(tile, R, p, t)) != ERROR)
		if ((left = checksPosition(tile, L, p, t)) != ERROR)
			if ((up = checksPosition(tile, U, p, t)) != ERROR)
				down = checksPosition(tile, D, p, t);
	
	if (right + left + up + down == 0) {
		printf("There is no tile around.\n");
		return ERROR;
	}
	return 1;
}

int checksPosition(int tile, int direction, Board *p, Tiles *t) {
	const char *empty = "00000";
	if (strcmp(p->board[p->row][(p->column) + 1], empty) != 0) {
		if (t->tiles[tile][direction] != p->board[p->row][(p->column) + 1][direction]) {
			printf("Selected tile does not fit.\n");
			return ERROR;
		}
		return 1;
	}
	return 0;
}

Board* placeTile(int tile, Tiles *t, Board *p) {

	p->board[p->row][p->column] = t->tiles[tile];

	return p;
}