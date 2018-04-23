#include "tile.h"
#include "board.h"

#include <stdio.h>
#include <stdlib.h>


void hello() {
	printf("INTERACTIVE MODE\n");
	printf("Hello players\n");
}

int selectMode() {
	int mode;
	printf("Hello!\n");
	printf("Select mode: ");
	scanf("%d", &mode);
	printf("\n");

	return mode;
}

int selectTile(Tiles *t) {
	int tile, can;

	printf("Select tile number: ");
	scanf("%d", &tile);

	if (tile < 1 || tile > 14) {
	printf("Wrong number!\nTile number should be in the range <1, 14>. ");
		printf("Select tile number again:");
		return selectTile(t);
	}
	
	can = canChooseTile(tile, t);
	if (can == NO_TILES) {
		printf("There are no tiles left!");
		return NO_TILES;
	}
	if (can == 0) {
		printf("You can not choose that tile. Try again.\n");
		return selectTile(t);
	}
	else
		return (tile - 1);

}

Tiles* selectRotation(Tiles *t) {
	printf("Select rotation: ");
	scanf(" %c", &t->rotate);
	return t;
}

Board* selectPlace(int player, Board *p) {
	if (player == PLAYER1) {
		printf("Select row: ");
		scanf("%d", &p->row1);

		printf("Select column: ");
		scanf(" %c", &p->column1);
	}
	else {
		printf("Select row: ");
		scanf("%d", &p->row2);

		printf("Select column: ");
		scanf(" %c", &p->column2);
	}

	return p;
}

int player1(Board *p, Tiles *t) {
	int number;
	int stop = 1;

	printf("************************** PLAYER 1 **************************\n");
	printBoard(PLAYER1, p);
	stop = printAvailableTiles(t);
	if (stop == 1) {
		number = selectTile(t);
		selectPlace(PLAYER1, p);
		selectRotation(t);
		rotateTile(number, t);
		placeTile(t, number, PLAYER1, p);
		deleteUsedTile(number, t);
		printBoard(PLAYER1, p);
	}

	if (stop == NO_TILES) {
		t->no_tiles = NO_TILES;
		return NO_TILES;
	}

	return 1;
}

int player2(Board *p, Tiles *t) {
	int number;
	int stop = 1;

	printf("************************** PLAYER 2 **************************\n");
	printBoard(PLAYER2, p);
	stop = printAvailableTiles(t);
	if (stop == 1) {
		number = selectTile(t);
		selectPlace(PLAYER2, p);
		selectRotation(t);
		rotateTile(number, t);
		placeTile(t, number, PLAYER2, p);
		deleteUsedTile(number, t);
		printBoard(PLAYER2, p);
	}

	if (stop == NO_TILES) {
		t->no_tiles = NO_TILES;
		return NO_TILES;
	}
	return 1;
}