#include <stdio.h>
#define SIZE 10

void transpose2D(int array[][SIZE], int rcSize);
void display(int array[][SIZE], int rcSize);

int main() {
	int array[SIZE][SIZE];
	int rcSize;

	printf("Enter size of square 2D array: ");
	scanf("%d", &rcSize);

	printf("Enter the %d x %d matrix: \n", rcSize, rcSize);
	for (int i = 0; i < rcSize; i++) {
		for (int j = 0; j < rcSize; j++) {
			scanf("%d", &array[i][j]);
		}
	}

	printf("transpose2D(): \n");
	transpose2D(array, rcSize);
	display(array, rcSize);
}

void transpose2D(int array[][SIZE], int rcSize) {
	int temp;

	for (int i = 1; i < rcSize; i++) {
		for (int j = 0; j < i; j++) {
			temp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = temp;
		}
	}
}

void display(int array[][SIZE], int rcSize) {
	for (int i = 0; i < rcSize; i++) {
		for (int j = 0; j < rcSize; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}
