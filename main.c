#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Tiles\Project1/tile.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Board\Board/board.h"
#include "C:\Users\kjabl\OneDrive\Pulpit\EiTI\Carcassonne\Interactive\Interactive\interactive.h"

#include <stdio.h>
#include <stdlib.h>

/*
TO DO LIST:
1. Poprawiæ obracanie klocka do do³u.
2. Przetestowaæ obracanie klocków.
3. Zmienic warunki na stawianie klocków (aktualnie w sytuacjach krañcowych, 
takich jak pole 1A przy sprawdzaniu do góry i na lewo, warunki wychodz¹ poza planszê).
4. Dodaæ usuwanie z listy tile'ów (z pliku txt) u¿ytego tile'a (dotyczy auto mode).
5. Dopisaæ manual dla u¿ytkownika, który bêdzie móg³ w³¹czyæ przy wpisywaniu ruchu.
6. Poprawiæ drukowanie planszy na ekran.
7. ALOGRYTM WYBIERANIA POLA I KLOCKA - AUTO MODE. !!!!
8. Dodaæ komentarze.
9. Przetestowaæ dzia³anie gry.
*/

int main() {
	int counter = 0;

	Tiles program, *t;
	t = &program;

	// AUTO MODE.
	/*
	FILE *board_auto;
	FILE *tile_auto;
	Board gameauto, *player;
	player = &gameauto;

	setBoard(player);
	player->firstPlacing = 0;

	board_auto = fopen("board_auto.txt", "w");
	tile_auto = fopen("tile_auto.txt", "r+");
	initializeTileArray(tile_auto, t);

	if (t->no_tiles != NO_TILES) {
		makeMove(player, t, board_auto, tile_auto);
	}

	fclose(board_auto);
	fclose(tile_auto);
	*/

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
			printf("******************************* PLAYER 1 *******************************\n");
			board_player1 = fopen("board_player1.txt", "w");
			makeMove(player1, t, board_player1, tile);
			fclose(board_player1);
		}
		else {
			// PLAYER 2.
			printf("******************************* PLAYER 2 *******************************\n");
			board_player2 = fopen("board_player2.txt", "w");
			makeMove(player2, t, board_player2, tile);
			fclose(board_player2);
		}
		counter++;
	}

	return 0;
}