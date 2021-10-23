#include <stdio.h>
#define SIZE 10

void reduceMatrix2D(int array[][SIZE], int rcSize);
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

	printf("reduceMatrix2D(): \n");
	reduceMatrix2D(array, rcSize);
	display(array, rcSize);
}

void reduceMatrix2D(int array[][SIZE], int rcSize) {
	int sum = 0;

	for (int j = 0; j < rcSize; j++) { // iterate through each column
		sum = 0;
		for (int i = j + 1; i < rcSize; i++) { // ie column 0 row 1 onwards to add
			sum += array[i][j];
			array[i][j] = 0;
		}
		array[j][j] += sum;
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
