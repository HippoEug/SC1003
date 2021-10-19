// SC1003 ASSIGNMENT
// This is a NTU Name Card Management Program, using an array of MAX structures.
#include <stdio.h>
#include <string.h>
#define MAX 5

void showChoice();
void listNameCards(struct Namecard namecard[], int* numberOfNameCards);
void addNameCard(struct Namecard namecard[], int* numberOfNameCards);
void removeNameCard(struct Namecard namecard[], int* numberOfNameCards);
void getNameCard(struct Namecard namecard[], int* numberOfNameCards);

typedef struct {
	int nameCardID; // Stores name card identification number
	char personName[20]; // Stores name of person in name card
	char companyName[20]; // Stores name of person's company in name card
} Namecard;

int main() {
	int choice;
	int numberOfNameCards = 0;

	Namecard namecard[MAX];

	printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
	showChoice(); // Shows user the 5 different options

	do {
		printf("Enter your choice:\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			listNameCards(namecard, &numberOfNameCards);
			break;
		case 2:
			addNameCard(namecard, &numberOfNameCards);
			break;
		case 3:
			removeNameCard(namecard, &numberOfNameCards);
			break;
		case 4:
			getNameCard(namecard, &numberOfNameCards);
			break;
		case 5:
			break;
		default:
			break;
		}

		/**
		printf("Number of name cards %d\n", numberOfNameCards); // DEBUG
		for (int i = 0; i < numberOfNameCards; i++) { // DEBUG
			printf("nameCardID: %d\n", namecard[i].nameCardID); // DEBUG
			printf("personName: %s\n", namecard[i].personName); // DEBUG
			printf("companyName: %s\n", namecard[i].companyName); // DEBUG
		}
		*/
	} while (choice != 5);
}

void showChoice() {
	printf("1: listNameCards()\n");
	printf("2: addNameCard()\n");
	printf("3: removeNameCard()\n");
	printf("4: getNameCard()\n");
	printf("5: quit\n");
}

// Function does XXX
void listNameCards(Namecard namecard[], int* numberOfNameCards) {
	printf("listNameCards():\n");

	if (*numberOfNameCards != 0) {
		for (int i = 0; i < *numberOfNameCards; i++) {
			printf("nameCardID: %d\n", namecard[i].nameCardID);
			printf("personName: %s\n", namecard[i].personName);
			printf("companyName: %s\n", namecard[i].companyName);
		}
	}
	else {
		printf("The name card holder is empty\n");
	}
}

// Function does XXX
void addNameCard(Namecard namecard[], int* numberOfNameCards) {
	// TODO: SORTING BASED ON ID IN ASCENDING ORDER
	int existFlag = 0;

	int inputNameCardID;
	char inputPersonName[20];
	char inputCompanyName[20];

	printf("addNameCard():\n");

	if (*numberOfNameCards >= 5) {
		printf("The name card folder is full\n");
	}
	else {
		printf("Enter nameCardID:\n");
		scanf("%d", &inputNameCardID);
		printf("Enter personName:\n");
		scanf("%s", inputPersonName);
		printf("Enter companyName:\n");
		scanf("%s", inputCompanyName);

		for (int i = 0; i < *numberOfNameCards; i++) {
			if (namecard[i].nameCardID == inputNameCardID) {
				printf("The nameCardID has already existed\n");
				existFlag = 1;
				break;
			}
		}

		if (existFlag == 0) {
			namecard[*numberOfNameCards].nameCardID = inputNameCardID;
			strncpy(namecard[*numberOfNameCards].personName, inputPersonName, 20);
			namecard[*numberOfNameCards].personName[19] = '\0'; // To null terminate strings for strncpy()
			strncpy(namecard[*numberOfNameCards].companyName, inputCompanyName, 20);
			namecard[*numberOfNameCards].companyName[19] = '\0'; // To null terminate strings for strncpy()

			*numberOfNameCards += 1;
			printf("The name card has been added successfully\n");
		}

		existFlag = 0;
	}
}

// Function does XXX
void removeNameCard(Namecard namecard[], int* numberOfNameCards) {
	char inputPersonName[20];
	char tempStructName[20], tempInputName[20];

	int comparisonFlag = 1;

	printf("removeNameCard():\n");

	if (*numberOfNameCards == 0) {
		printf("The name card holder is empty\n");
	}
	else {
		printf("Enter personName:\n");
		scanf("%s", inputPersonName);

		for (int i = 0; i < *numberOfNameCards; i++) {
			for (int iterChar = 0; iterChar < 20; iterChar++) {
				tempStructName[iterChar] = tolower(namecard[i].personName[iterChar]);
				tempInputName[iterChar] = tolower(inputPersonName[iterChar]);
			}

			// printf("tempStructName: %s\n", tempStructName); // debug
			// printf("tempInputtName: %s\n", tempInputName); // debug

			comparisonFlag = strcmp(tempStructName, tempInputName);
			// printf("Length of tempStructName %d\n", sizeof(tempStructName)); // debug
			// printf("Length of tempInputName %d\n", sizeof(tempInputName)); // debug
			// printf("strcmp %d\n", comparisonFlag); // debug

			if (comparisonFlag == 0) {
				printf("The name card is removed\n");
				printf("nameCardID: %d\n", namecard[i].nameCardID);
				printf("personName: %s\n", namecard[i].personName);
				printf("companyName: %s\n", namecard[i].companyName);

				namecard[i].nameCardID = namecard[i + 1].nameCardID;
				strncpy(namecard[i].personName, namecard[i+1].personName, 20);
				namecard[i].personName[19] = '\0'; // To null terminate strings for strncpy()
				strncpy(namecard[i].companyName, namecard[i+1].companyName, 20);
				namecard[i].companyName[19] = '\0'; // To null terminate strings for strncpy()

				*numberOfNameCards -= 1;
				break;
			}
			else {
				printf("The target person name is not in the name card holder\n");
			}
		}

		comparisonFlag = 1;
	}
}

// Function does XXX
void getNameCard(Namecard namecard[], int* numberOfNameCards) {
	char inputPersonName[20];
	char tempStructName[20], tempInputName[20];

	int comparisonFlag = 1;

	printf("getNameCard():\n");

	if (*numberOfNameCards != 0) {
		printf("Enter personName:\n");
		scanf("%s", inputPersonName);

		for (int i = 0; i < *numberOfNameCards; i++) {
			for (int iterChar = 0; iterChar < 20; iterChar++) {
				tempStructName[iterChar] = tolower(namecard[i].personName[iterChar]);
				tempInputName[iterChar] = tolower(inputPersonName[iterChar]);
			}

			// printf("tempStructName: %s\n", tempStructName); // debug
			// printf("tempInputtName: %s\n", tempInputName); // debug

			comparisonFlag = strcmp(tempStructName, tempInputName);
			// printf("Length of tempStructName %d\n", sizeof(tempStructName)); // debug
			// printf("Length of tempInputName %d\n", sizeof(tempInputName)); // debug
			// printf("strcmp %d\n", comparisonFlag);

			if (comparisonFlag == 0) {
				printf("The target person name is found\n");
				printf("nameCardID: %d\n", namecard[i].nameCardID);
				printf("personName: %s\n", namecard[i].personName);
				printf("companyName: %s\n", namecard[i].companyName);
				break;
			}
			else {
				printf("The target person name is not found\n");
			}
		}

		comparisonFlag = 1;
	}
	else {
		printf("The target person name is not found\n");
	}
}
