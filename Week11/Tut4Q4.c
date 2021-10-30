#include <stdio.h>
#include <string.h>

int stringCompare(char *string1, char *string2);

int main() {
	char string1[80], string2[80];
	char *p;
	int result = 69;

	printf("Enter string1: \n");
	fgets(string1, 80, stdin);
	if (p = strchr(string1, '\n')) {
		*p = '\0';
	}

	printf("Enter string2: \n");
	fgets(string2, 80, stdin);
	if (p = strchr(string2, '\n')) {
		*p = '\0';
	}

	result = stringCompare(string1, string2);

	if (result == 1) {
		printf("stringCompare(): greater than");
	}
	else if (result == 0) {
		printf("stringCompare(): equal");
	}
	else if (result == -1) {
		printf("stringCompare(): less than");
	}
	else {
		printf("stringCompare(): error");
	}
}

int stringCompare(char *string1, char *string2) {
	for (int i = 0; ; i++) {
		if (string1[i] == '\0' && string2[i] == '\0') {
			return 0;
		}
		else if (string1[i] == '\0') {
			return -1;
		}
		else if (string2[i] == '\0') {
			return 1;
		}
		else if (string1[i] < string2[i]) {
			return -1;
		}
		else if (string1[i] > string2[i]) {
			return 1;
		}
	}
}
