#include <stdio.h>

void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);

int main() {
	int ar[80];
	int size, i;

	printf("Enter array size: \n");
	scanf_s("%d", &size);

	printf("Enter %d data: \n", size);
	for (i = 0; i <= size-1; i++) {
		scanf_s("%d", &ar[i]);
	}

	printReverse1(ar, size);
	printReverse2(ar, size);
	reverseAr1D(ar, size);

	printf("\nreverseAr1D(): ");
	if (size > 0) {
		for (i = 0; i < size; i++)
			printf("%d ", ar[i]);
	}
	printf("\n");
}

// Array with Index Notation
void printReverse1(int ar[], int size) {
	printf("printReverse1(): ");
	for (int i = (size - 1); i >= 0; i--) {
		printf("%d ", ar[i]);
	}
}

// Array with Pointer Notation
void printReverse2(int ar[], int size) {
	printf("\nprintReverse2(): ");
	for (int i = size - 1; i >= 0; i--) {
		printf("%d ", *(ar + i));
	}
}

// Array is reversed via call by reference
void reverseAr1D(int ar[], int size) {
	int *tempArray;

	tempArray = (int*)malloc(size);
	int j = 0;

	for (int i = (size - 1); i >= 0; i--) {
		tempArray[j] = ar[i];
		j++;
	}

	for (int i = 0; i < size; i++) {
		ar[i] = tempArray[i];
	}
}
