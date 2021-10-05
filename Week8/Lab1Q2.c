// Program gets average of numbers from user input

#include <stdio.h>

int main() {
	int userInputInt;
	int noOfInputs = 0, noOfLines = 0;
	double sum = 0;
	double average;

	printf("Enter number of lines: \n");
	scanf_s("%d", &noOfLines);

	for (int i = 1; i <= noOfLines; i++) {
		sum = 0, noOfInputs = 0; // Reinstate sum to be 0 

		printf("Enter line %d (ends with -1): \n", i);
		scanf_s("%d", &userInputInt);

		while (userInputInt != -1) {
			sum += userInputInt;
			noOfInputs += 1;
			scanf_s("%d", &userInputInt);
		}

		average = sum / noOfInputs;
		printf("Average = %.2f \n", average);
	}
}
