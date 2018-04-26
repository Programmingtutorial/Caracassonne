#include "tile.h"
#include "board.h"
#include "interactive.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***********************************************************************************
Function prints board on the screen. 
It takes as a parameters information about player and pointer to the Board structure.
************************************************************************************/
void printBoard(int player, Board *p) {
	int i, j;
	
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
			if (player == 1)
				printf(" %.*s ", tile_length - 1, p->board_player1[i][j]);	// Prints string without new line.
			else
				printf(" %.*s ", tile_length - 1, p->board_player2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


/* Function set boards for both players and fills them with 0'. 
It takes as a paremter poninter to the structure Board.
It returns a pointer to the structure Board. */
Board* setBoard(Board *p) {	// Fills global boards with 0's
	int i, j;

	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			char *temp = (char*)malloc(tile_length * sizeof(char));
			temp = "00000";
			p->board_player1[i][j] = temp;
			p->board_player2[i][j] = temp;
		}
	}

	return p;
}

/*******************************************************************
Function checks if the tile can be placed in selected place.
It takes as a parameter information about player and pointers to structure Board and Tile.
It returns 0 if placing the tile in a selected place is unpossible, 1 otherwise. 
********************************************************************/
int canplaceTile(int player, Board *p, Tiles *t) {
	const char *empty = "00000";

	if (t->no_tiles == NO_TILES) {
		return NO_TILES;
	}

	if (player == PLAYER1) {
		if (p->firstPlacing1 == 0) {
			p->firstPlacing1 = 1;
			return 1;
		}
		
		if (p->column1 < 0 || p->column1 >= length || p->row1 < 0 || p->row1 >= length)
			printf("This place doesn't exist\n");
		else if (strcmp(p->board_player1[p->row1][p->column1], empty) != 0)
			printf("this place is already taken\n");
	}
	else {
		if (p->firstPlacing2 == 0) {
			p->firstPlacing2 = 1;
			return 1;
		}

		if (p->column2 < 0 || p->column2 >= length || p->row2 < 0 || p->row2 >= length) {
			printf("This place doesn't exist\n");
			return 0;
		}
		else if (strcmp(p->board_player2[p->column2][p->row2], empty) != 0) {
			printf("This place is already taken\n");
			return 0;
		}
	}

	/*else if (board[row][column - 1] == "00000" || board[row][column + 1] == "00000" ||	//checks if there is at least one tile around 
		board[row - 1][column] == "00000" || board[row + 1][column] == "00000") {
		printf("there are no tiles to be connected with\n");
		return 1;
	} */

	return 1;
}

/* Function place the tile on a board. 
It takes as parameters pointers to structures Board and Tile, number of tile and 
information about player.
It returns the pointer to Board structure. */
Board* placeTile(Tiles *t, int tile, int player, Board *p) {
	// PLAYER 1.
	if (player == PLAYER1) {
		// Changing information about column from char to int.
		p->column1 = p->column1 - 'A';
		// Array (board) numerated form 0 so we need to substract 1 form information about row.
		p->row1 = p->row1 - 1;
		if (canplaceTile(player, p, t) == 1) {
			// Placing the tile.
			p->board_player1[p->row1][p->column1] = t->tiles[tile];
		}
	}
	// PLAYER 2.
	else {
		p->column2 = p->column2 - 'A';
		p->row2 = p->row2 - 1;
		if (canplaceTile(player, p, t) == 1) {
			p->board_player2[p->row2][p->column2] = t->tiles[tile];
		}
	}

	return p;
}
