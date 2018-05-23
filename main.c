#include "tile.h"
#include "board.h"
#include "interactive.h"
#include "auto.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	int counter = 0;

	Tiles program, *t;
	t = &program;
	
	/**
	// AUTO MODE.
	FILE *board_auto;
	FILE *tile_auto;
	Board gameauto, *player;
	player = &gameauto;
	board_auto = fopen("board_auto.txt", "r");
	tile_auto = fopen("tile_auto.txt", "r");

	makeMoveAUTO(player, t, board_auto, tile_auto);

	tile_auto = fopen("tile_auto.txt", "w");
	fillTileFile(tile_auto, t);
	fclose(tile_auto);
	board_auto = fopen("board_auto.txt", "w");
	fillBoardFile(board_auto, player);
	fclose(board_auto); 

	return 0;
	**/

	// INTERACTIVE MODE.
	FILE *tile = fopen("tile.txt", "r");
	initializeTileArray(tile, t);
	fclose(tile);

	FILE *board_player1;
	FILE *board_player2;

	Board gamep1, *player1;
	player1 = &gamep1;

	Board gamep2, *player2;
	player2 = &gamep2;

	setBoard(player1);
	setBoard(player2);

	// Seting information about the first move to 0.
	player1->firstPlacing = 0;
	player2->firstPlacing = 0;


	// While there is at least one tile in tiles[] array the program continues.
	while (t->no_tiles != NO_TILES) {
		if (counter % 2 == 0) {
			// PLAYER 1.
			printf("************************************* PLAYER 1 *************************************\n\n");
			board_player1 = fopen("board_player1.txt", "w");
			makeMove(player1, t, board_player1, tile);
			fclose(board_player1);
		}
		else {
			// PLAYER 2.
			printf("************************************* PLAYER 2 *************************************\n\n");
			board_player2 = fopen("board_player2.txt", "w");
			makeMove(player2, t, board_player2, tile);
			fclose(board_player2);
		}
		counter++;
	}
	
	return 0;
	
}
