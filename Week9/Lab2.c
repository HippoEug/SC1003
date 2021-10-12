// SC1003 Lab 2
#include <stdio.h>

// Function Prototypes
int numDigits1(int num);
int digitPos1(int num, int digit);
int square1(int num);
void numDigits2(int num, int *result);
void digitPos2(int num, int digit, int *result);
void square2(int num, int *result);

int main() {
	int choice;
	int number, digit, result = 0;
	do {
		printf("\nPerform the following functions ITERATIVELY:\n");
		printf("1:  numDigits1()\n");
		printf("2:  numDigits2()\n");
		printf("3:  digitPos1()\n");
		printf("4:  digitPos2()\n");
		printf("5:  square1()\n");
		printf("6:  square2()\n");
		printf("7:  quit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				printf("numDigits1(): %d\n", numDigits1(number));
				break;
			case 2:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				numDigits2(number, &result);
				printf("numDigits2(): %d\n", result);
				break;
			case 3:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				printf("Enter the digit: \n");
				scanf_s("%d", &digit);
				printf("digitPos1(): %d\n", digitPos1(number, digit));
				break;
			case 4:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				printf("Enter the digit: \n");
				scanf_s("%d", &digit);
				digitPos2(number, digit, &result);
				printf("digitPos2(): %d\n", result);
				break;
			case 5:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				printf("square1(): %d\n", square1(number));
				break;
			case 6:
				printf("Enter the number: \n");
				scanf_s("%d", &number);
				square2(number, &result);
				printf("square2(): %d\n", result);
				break;
			default: printf("Program terminating .....\n");
				break;
		}

		// After every loop reinitialize value to 0
		number = 0;
		digit = 0;
		result = 0;
	} while (choice < 7);
}

// Q1 Part 1
int numDigits1(int num) {
	int count = 0;

	do {
		count++;
		num = num / 10; // Each division removes a digit
	} while (num > 0);

	return count;
}

// Q1 Part 2
void numDigits2(int num, int *result) {
	*result = 0;

	do {
		(*result)++;
		num = num / 10; // Each division removes a digit
	} while (num > 0);
}

// Q2 Part 1
int digitPos1(int num, int digit) {
	int pos = 0;

	do {
		pos++;
		if (num % 10 == digit) { // Checking last digit through modulus
			return pos;
		}
		num = num / 10; // Each division removes a digit
	} while (num > 0);
}

// Q2 Part 2
void digitPos2(int num, int digit, int *result) {
	int pos = 0;
	*result = 0;

	do {
		pos++;
		if (num % 10 == digit) { // Checking last digit through modulus
			*result = pos;
			break;
		}
		num = num / 10; // Each division removes a digit
	} while (num > 0);
}

// Q3 Part 1
int square1(int num) {
	int square = 0;

	for (int i = 1; i <= num; i++) {
		if (i % 2 != 0) { // Checking if i is an odd number
			square += i; // Add to result if odd number
			num++; // Increases target size if odd number
		}
	}

	return square;
}

// Q3 Part 2
void square2(int num, int *result) {
	for (int i = 1; i <= num; i++) {
		if (i % 2 != 0) { // Checking if i is an odd number
			*result += i; // Add to result if odd number
			num++; // Increases target size if odd number
		}
	}
}
