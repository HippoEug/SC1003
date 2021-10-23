#include <stdio.h>
#include <stdlib.h>

void getFrequency(int histogram[10], int userInput);
void printFrequency(int histogram[10]);

int main() {
	int histogram[10];
	int userInput;

	printf("Input number of random numbers: ");
	scanf("%d", &userInput);

	getFrequency(histogram, userInput);
	printFrequency(histogram);
}

void getFrequency(int histogram[10], int userInput) {
	for (int i = 0; i < 10; i++) {
		histogram[i] = 0;
	}

	for (int i = 0; i < userInput; i++) {
		histogram[(rand() % 100) / 10] += 1;
	}
}

void printFrequency(int histogram[10]) {
	for (int i = 0; i < 10; i++) {
		printf("%2d--%2d |", (i * 10), (i * 10 + 9));
		for (int j = 0; j < histogram[i]; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}
