#include <stdlib.h>
#include <stdio.h>

int main () {
	int game[9];
	int x_plays = 0, o_plays = 0, empty = 0, i;
	char c;

	for (i = 0; i < 9; i++) {
		scanf("%c", &c);

		// integer 1 represents a play by 'X' in the array
		if (c == 'X') {
			game[i] = 1;
			x_plays++;
		}
		// integer 0 represents a play by '0' in the array
		if (c == '0') {
			game[i] = 0;
			o_plays++;
		}
		// integer -10 represents a '.'
		if (c == '.') {
			game[i] = -10;
			empty++;
		}
		// ignore ENTER input after first and second lines
		if (i == 2 || i == 5) fgetc(stdin);
	}

	// if player 1 won, the sum of the line, column or diagonal is 3.
	// checks lines
	if (game[0] + game[1] + game[2] == 3 ||
		game[3] + game[4] + game[5] == 3 ||
		game[6] + game[7] + game[8] == 3 ||
	// columns
		game[0] + game[3] + game[6] == 3 ||
		game[1] + game[4] + game[7] == 3 ||
		game[2] + game[5] + game[8] == 3 ||
	// and diagonals
		game[0] + game[4] + game[8] == 3 ||
		game[2] + game[4] + game[6] == 3) {

		printf("primeiro_venceu\n");
		return 0;
	}

	// if player 2 won, the sum of the line, column or diagonal is 0.
	// checks lines
	if (game[0] + game[1] + game[2] == 0 ||
		game[3] + game[4] + game[5] == 0 ||
		game[6] + game[7] + game[8] == 0 ||
	// columns
		game[0] + game[3] + game[6] == 0 ||
		game[1] + game[4] + game[7] == 0 ||
		game[2] + game[5] + game[8] == 0 ||
	// and diagonals
		game[0] + game[4] + game[8] == 0 ||
		game[2] + game[4] + game[6] == 0) {

		printf("segundo_venceu\n");
		return 0;
	}

	// if no one won, then either it's a tie or someone has to play.
	// no empty spaces -> tie
	if (empty == 0) {
		printf("empate\n");
		return 0;
	}

	// same number of plays -> 'X' plays next
	if (x_plays == o_plays) {
		printf("primeiro\n");
		return 0;
	// 'X' has 1 more play -> '0' plays next
	} else
		printf("segundo\n");
		return 0;

	return 0;
}