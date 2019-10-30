#include <stdio.h>

int main () {
	int pos1, pos2;
	int i = 0, j = 0, sum = 0; 
	int aux;

	// read positions
	scanf("%d", &pos1);
	scanf("%d", &pos2);

	// checks the interval
	if (pos1 < 1 || pos1 > 1000 || pos2 < 1 || pos2 > 1000) {
		printf("Invalid positions.\n");
		return 0;
	}

	// position 1 comes before position 2 always
	if (pos2 < pos1) {
		aux = pos1;
		pos1 = pos2;
		pos2 = aux;
	}

	while (pos1 != pos2) {
		// walks 1 position foward
		pos1++;
		sum += ++i;

		if (pos1 == pos2) {
			printf("%d\n", sum);
			return 0;
		}

		// walks 1 position backwards
		pos2--;
		sum += ++j;
	}

	printf("%d\n", sum);
	return 0;
}