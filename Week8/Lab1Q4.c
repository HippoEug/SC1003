// Program calculates exponential

#include <stdio.h>

int main() {
	float inputX;
	double numerator = 1;
	double denominator = 1;
	double result = 1;

	printf("Enter x: \n");
	scanf_s("%f", &inputX);

	for (int i = 1; i <= 10; i++) {
    		// Numerator: x^4 is x multiplied by x^3
		numerator = numerator*inputX;
    		// Denominator: Factorial 4! is 4 multiplied by factorial 3!
		denominator = denominator * i;

		result += (numerator / denominator);
		// Do not have to reinit numerator or denominator to 1 after every loop
	}

	printf("Result: %0.2f", result);
}
