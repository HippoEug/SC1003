// SC1003 ASSIGNMENT
// This is a NTU Name Card Management Program, using an array of MAX structures.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

typedef struct {
	int nameCardID; // Stores name card identification number
	char personName[20]; // Stores name of person in name card
	char companyName[20]; // Stores name of person's company in name card
} NameCard;

void showChoice();
void listNameCards(NameCard nameCard[], int* numberOfNameCards);
void addNameCard(NameCard nameCard[], int* numberOfNameCards);
void removeNameCard(NameCard nameCard[], int* numberOfNameCards);
void getNameCard(NameCard nameCard[], int* numberOfNameCards);
void sortNameCards(NameCard nameCard[], int* numberOfNameCards);

int main() {
	int choice;
	int numberOfNameCards = 0;

	NameCard nameCard[MAX];

	printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
	showChoice(); // Shows user the 5 different options

	do {
		printf("Enter your choice:\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			listNameCards(nameCard, &numberOfNameCards);
			break;
		case 2:
			addNameCard(nameCard, &numberOfNameCards);
			sortNameCards(nameCard, &numberOfNameCards);
			break;
		case 3:
			removeNameCard(nameCard, &numberOfNameCards);
			break;
		case 4:
			getNameCard(nameCard, &numberOfNameCards);
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (choice != 5);
}

// Function displays available choices
void showChoice() {
	printf("1: listNameCards()\n");
	printf("2: addNameCard()\n");
	printf("3: removeNameCard()\n");
	printf("4: getNameCard()\n");
	printf("5: quit\n");
}

// Function lists all name cards stored
void listNameCards(NameCard nameCard[], int* numberOfNameCards) {
	printf("listNameCards():\n");

	if (*numberOfNameCards != 0) { // If there are name cards in holder
		for (int i = 0; i < *numberOfNameCards; i++) {
			printf("nameCardID: %d\n", nameCard[i].nameCardID);
			printf("personName: %s\n", nameCard[i].personName);
			printf("companyName: %s", nameCard[i].companyName);
		}
	}
	else {
		printf("The name card holder is empty\n");
	}
}

// Function adds new name cards into the struct array
void addNameCard(NameCard nameCard[], int* numberOfNameCards) {
	int existFlag = 0;

	int inputNameCardID;
	char inputPersonName[20];
	char inputCompanyName[20];

	printf("addNameCard():\n");

	if (*numberOfNameCards >= MAX) { // If name card holder already at MAX capacity
		// START OF USELESS CODE FOR PRODUCT SPECIFICATION
		printf("Enter nameCardID:\n");
		scanf("%d", &inputNameCardID);
		getchar(); // Clears newline in buffer for fgets
		printf("Enter personName:\n");
		fgets(inputPersonName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;
		printf("Enter companyName:\n");
		fgets(inputCompanyName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;
		// END OF USELESS CODE FOR PRODUCT SPECIFICATION

		printf("The name card holder is full\n");
	}
	else {
		printf("Enter nameCardID:\n");
		scanf("%d", &inputNameCardID);
		getchar(); // Clears newline in buffer for fgets

		printf("Enter personName:\n");
		fgets(inputPersonName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;

		printf("Enter companyName:\n");
		fgets(inputCompanyName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;

		// Iterate through name card holder to see if ID already exists
		for (int i = 0; i < *numberOfNameCards; i++) {
			if (nameCard[i].nameCardID == inputNameCardID) {
				printf("The nameCardID has already existed\n");
				existFlag = 1;
				break;
			}
		}

		// Add to name card holder if ID does not exist
		if (existFlag == 0) {
			nameCard[*numberOfNameCards].nameCardID = inputNameCardID;
			strncpy(nameCard[*numberOfNameCards].personName, inputPersonName, 20);
			nameCard[*numberOfNameCards].personName[19] = '\0'; // To null terminate strings for strncpy()
			strncpy(nameCard[*numberOfNameCards].companyName, inputCompanyName, 20);
			nameCard[*numberOfNameCards].companyName[19] = '\0'; // To null terminate strings for strncpy()

			*numberOfNameCards += 1; // Increase name card count
			printf("The name card has been added successfully\n");
		}

		existFlag = 0;
	}
}

// Function removes old name cards from the struct array
void removeNameCard(NameCard nameCard[], int* numberOfNameCards) {
	char inputPersonName[20];
	char tempStructName[20], tempInputName[20];

	int comparisonFlag = 1; // Flag to see if strings are equal
	int dataRemovedFlag = 0; // Flag to check if name card removed

	printf("removeNameCard():\n");

	if (*numberOfNameCards == 0) { // If name card holder already is empty
		// START OF USELESS CODE FOR PRODUCT SPECIFICATION
		getchar(); // Clears newline in buffer for fgets
		printf("Enter personName:\n");
		fgets(inputPersonName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;
		// END OF USELESS CODE FOR PRODUCT SPECIFICATION

		printf("The name card holder is empty\n");
	}
	else {
		getchar(); // Clears newline in buffer for fgets
		printf("Enter personName:\n");
		fgets(inputPersonName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;

		// Iterate through name card holder
		for (int i = 0; i < *numberOfNameCards; i++) {
			// Converts name in array and user input to lower case for comparison
			for (int iterChar = 0; iterChar < 20; iterChar++) {
				tempStructName[iterChar] = tolower(nameCard[i].personName[iterChar]);
				tempInputName[iterChar] = tolower(inputPersonName[iterChar]);
			}
			
			if (dataRemovedFlag == 0) { // If no name card is removed yet
				comparisonFlag = strcmp(tempStructName, tempInputName);
			}

			// If name to be removed is found and no name card is removed yet
			if (comparisonFlag == 0 && dataRemovedFlag == 0) {
				printf("The name card is removed\n");
				printf("nameCardID: %d\n", nameCard[i].nameCardID);
				printf("personName: %s\n", nameCard[i].personName);
				printf("companyName: %s", nameCard[i].companyName);
				dataRemovedFlag = 1;

				// Moving data to the left after deletion of a name card
				nameCard[i].nameCardID = nameCard[i + 1].nameCardID;
				strncpy(nameCard[i].personName, nameCard[i+1].personName, 20);
				nameCard[i].personName[19] = '\0'; // To null terminate strings for strncpy()
				strncpy(nameCard[i].companyName, nameCard[i+1].companyName, 20);
				nameCard[i].companyName[19] = '\0'; // To null terminate strings for strncpy()*/
			}
			// Else if name to be removed has already been found and a name card is removed
			// Implemented in the event of duplicate names
			else if (comparisonFlag == 0 && dataRemovedFlag == 1) {
				// Moving data to the left after removing a name card
				nameCard[i].nameCardID = nameCard[i + 1].nameCardID;
				strncpy(nameCard[i].personName, nameCard[i + 1].personName, 20);
				nameCard[i].personName[19] = '\0'; // To null terminate strings for strncpy()
				strncpy(nameCard[i].companyName, nameCard[i + 1].companyName, 20);
				nameCard[i].companyName[19] = '\0'; // To null terminate strings for strncpy()*/
			}
		}

		*numberOfNameCards -= 1; // Decrease name card count
		dataRemovedFlag = 0; // Reset flag to no name card is removed yet

		if (comparisonFlag != 0) {
			printf("The target person name is not in the name card holder\n");
		}
		comparisonFlag = 1; // Reset flag to no equal string comparison
	}
}

// Function gets a particular name card information
void getNameCard(NameCard nameCard[], int* numberOfNameCards) {
	char inputPersonName[20];
	char tempStructName[20], tempInputName[20];

	int comparisonFlag = 1;

	printf("getNameCard():\n");

	if (*numberOfNameCards != 0) { // If there are name cards in holder
		getchar(); // Clears newline in buffer for fgets
		printf("Enter personName:\n");
		fgets(inputPersonName, 20, stdin);
		inputPersonName[strcspn(inputPersonName, "\n")] = 0;

		// Iterate through name card holder
		for (int i = 0; i < *numberOfNameCards; i++) {
			// Converts name in array and user input to lower case for comparison
			for (int iterChar = 0; iterChar < 20; iterChar++) {
				tempStructName[iterChar] = tolower(nameCard[i].personName[iterChar]);
				tempInputName[iterChar] = tolower(inputPersonName[iterChar]);
			}

			comparisonFlag = strcmp(tempStructName, tempInputName);

			// If name is found
			if (comparisonFlag == 0) {
				printf("The target person name is found\n");
				printf("nameCardID: %d\n", nameCard[i].nameCardID);
				printf("personName: %s\n", nameCard[i].personName);
				printf("companyName: %s", nameCard[i].companyName);
				break;
			}
		}

		if (comparisonFlag != 0) {
			printf("The target person name is not found\n");
		}
		comparisonFlag = 1;
	}
	else {
		printf("The target person name is not found\n");
	}
}

// Function sorts name cards in ascending order of ID
void sortNameCards(NameCard nameCard[], int* numberOfNameCards) {
	int tempNameCardID;
	char tempPersonName[20], tempCompanyName[20];

	if (*numberOfNameCards != 0) { // If there are name cards in holder
		for (int i = 0; i < *numberOfNameCards; i++) { // Iterate through name card holder
			for (int j = i + 1; j < *numberOfNameCards; j++) {
				if (nameCard[i].nameCardID > nameCard[j].nameCardID) {
					tempNameCardID = nameCard[i].nameCardID;
					strncpy(tempPersonName, nameCard[i].personName, 20);
					strncpy(tempCompanyName, nameCard[i].companyName, 20);

					nameCard[i].nameCardID = nameCard[j].nameCardID;
					strncpy(nameCard[i].personName, nameCard[j].personName, 20);
					strncpy(nameCard[i].companyName, nameCard[j].companyName, 20);

					nameCard[j].nameCardID = tempNameCardID;
					strncpy(nameCard[j].personName, tempPersonName, 20);
					strncpy(nameCard[j].companyName, tempCompanyName, 20);
				}
			}
		}
	}
}
