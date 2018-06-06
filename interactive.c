#include "interactive.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"

#include <stdio.h>
#include <stdlib.h>


int selectMode() {
	int mode;
	printf("Hello!\n");
	printf("If you want to select interactive mode press 1.\n");
	printf("If you want to select auto mode press 0.\n");
	scanf("%d", &mode);
	printf("\n");

	return mode;
}

int selectTile(Tiles *t) {
	int tile, can;

	printf("Select tile number: ");
	scanf("%d", &tile);

	// Cheks if the number of tile is correct (czy nie wychodzi poza zakres). 
	while (tile < 1 || tile > 14) {
		printf("Wrong number!\nTile number should be in the range <1, 14>. ");
		printf("Select tile number again:");
		scanf("%d", &tile);
	}
	
	// Chceck the tile can be chosen (if is available).
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

/* Function ask user to select roatation. */
Tiles* selectRotation(Tiles *t) {
	printf("Select rotation: ");
	scanf(" %c", &t->rotate);
	return t;
}

/* Function ask user to select the place on a board. */
Board* selectPlace(Board *p) {
	printf("Select row: ");
	scanf("%d", &p->row);

	printf("Select column: ");
	scanf(" %c", &p->column);

	// Changing information about column from char to int.
	p->column = p->column - 'A';
	// Array (board) numerated form 0 so we need to substract 1 form information about row.
	p->row = p->row - 1;

	//Checks if selected place exists.
	while (p->column < 0 || p->column >= length || p->row < 0 || p->row >= length) {
		printf("This place doesn't exist. Try again.\n");
		printf("Select row: ");
		scanf("%d", &p->row);

		printf("Select column: ");
		scanf(" %c", &p->column);

		p->column = p->column - 'A';
		p->row = p->row - 1;
	}

	return p;
}

Tiles* makeMove(Board *p, Tiles *t) {
	int stop, number;

	
	printBoard2(p);
	stop = printAvailableTiles2(t);
	if (stop == OK) {
		number = selectTile(t);
		selectPlace(p);
		selectRotation(t);
		rotateTile(number, t);
		while (canplaceTile(number, p, t) == ERROR) {
			number = selectTile(t);
			selectPlace(p);
			selectRotation(t);
			rotateTile(number, t);
		}
		placeTile(number, t, p);
		deleteUsedTile(number, t);
		printBoard2(p);
	}
	else if (stop == NO_TILES) {
		t->no_tiles = NO_TILES;
	}

	return t;
}