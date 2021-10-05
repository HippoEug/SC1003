// Program prints a triangular pattern

#include <stdio.h>

int main() {
	int height;

	printf("Enter the height: \n");
	scanf_s("%d", &height);
	printf("Pattern: \n");

	for (int i = 1; i <= height; i++) {
		for (int repeat = 1; repeat <= i; repeat++) {
			switch (i%3) {
				case 0:
					printf("3");
					break;
				case 1:
					printf("1");
					break;
				case 2:
					printf("2");
					break;
			}
		}
		printf("\n");
	}
}
