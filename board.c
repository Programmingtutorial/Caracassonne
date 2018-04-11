#include <stdio.h>
#include <stdlib.h>

#define length 100

char tab1[length][length];	// One board just for a try, should be 2 of them
int firstPlacing = 0;

	

void printBoard(char board[length][length]) {	// Prints board on the screen

	int i, j;

	printf("   ABCDEFGHIJ\n\n");

	for (i = 0; i < length; i++) {
		if (i + 1 < 10) {
			printf(" %d ", i + 1);
		}
		else {
			printf("%d ", i + 1);

		}
		for (j = 0; j < length; j++) {

			printf("%c", board[i][j]);

		}
		printf("\n");
	}

}

void setBoard(char board[length][length]) {	// Fills global boards with 0's

	int i, j;

	for (i = 0; i < length; i++) {

		for (j = 0; j < length; j++) {

			board[i][j] = '0';

		}
	}

}
/*
int countPoints(char board[]) {

}
*/
int canplaceTile(char board[length][length], char column, int row) {

	if (firstPlacing == 0) {
		firstPlacing = 1;
		return 0;
	}
	if (column < 0 || column >= length || row < 0 || row >= length) { //checks if its not out of board
		printf("this place doesn't exist\n");
		return 1;
	}
	else if (board[row][column] != '0') {		//checks if its empty;
		printf("this place is already taken\n");
		return 1;
	}
	else if (board[row][column - 1] == '0' || board[row][column + 1] == '0' ||	//checks if there is at least one tile around 
		board[row - 1][column] == '0' || board[row + 1][column] == '0') {
		printf("there are no tiles to be connected with\n");
		return 1;
	}
	else {
		return 0;
	}
}

	void placeTile(char tile, int player, char column, int row) {

		if (player == 1) {

			if (canplaceTile(tab1, column, row-1) == 1) {
			}
			else {
				tab1[row-1][(int)column - 65] = tile;
			}
		}
	}

/*
	if (player == 2) {

	if (canplaceTile(tab2, column, row) == 1) {

	}
	else {
	tab2[column][row] = tile;
	}
	}
}
	
/*
	else if (road connected with non-road) {

	}else if(castle conected with non-castle){
	
	}else(everything fine){
		
		board[column][row] = tile;

		return 0;
		}
	
	}

	checkIfConnects(tile, position, board){
			
			// checks for any tile if it connects fine 

	}
*/

int main() {
	setBoard(tab1);

	printf("%d\n\n", sizeof(tab1) / sizeof(tab1[0]));

	printBoard(tab1);

	printf("\n");

	placeTile('D', 1, 'B', 3);

	printBoard(tab1);

	printf("\n");

	return 0;
}