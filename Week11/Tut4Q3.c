#include <stdio.h>
#include <string.h>

char *stringCopy(char *resultStr, char *inputStr, int inputLength);

int main() {
	char inputStr[40], resultStr[40];
	int inputLength;
	char *p, *result;

	printf("Enter the string: \n");
	fgets(inputStr, 40, stdin);
	if (p = strchr(inputStr, '\n')) {
		*p = '\0';
	}

	printf("Enter the number of characters: \n");
	scanf("%d", &inputLength);

	result = stringCopy(resultStr, inputStr, inputLength);
	printf("stringCopy(): %s\n", result);
}

char *stringCopy(char *resultStr, char *inputStr, int inputLength) {
	int i, j;

	for (i = 0; i < inputLength; i++) {
		if (inputStr[i] != '\0') {
			resultStr[i] = inputStr[i];
		}
		else {
			break;
		}
	}

	resultStr[i] = '\0';
	
	/*for (j = i; j < inputLength; j++) {
		resultStr[j] = '\0';
	}*/

	return resultStr;
}
