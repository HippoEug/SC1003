// SC1003 ASSIGNMENT
// This is a NTU Name Card Management Program, using an array of MAX structures.
#include <stdio.h>
#define MAX 5

void showChoice();
void listNameCards(struct Namecard namecard[]);
void addNameCard(struct Namecard namecard[]);
void removeNameCard();
void getNameCard();

typedef struct {
	int nameCardID; // Stores name card identification number
	char personName[20]; // Stores name of person in name card
	char companyName[20]; // Stores name of person's company in name card
} Namecard;

int main() {
	int choice;

	Namecard namecard[MAX];

	printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
	showChoice(); // Shows user the 5 different options

	do {
		printf("Enter your choice:\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			listNameCards(namecard);
			break;
		case 2:
			addNameCard(namecard);
			break;
		case 3:
			removeNameCard();
			break;
		case 4:
			getNameCard();
			break;
		case 5:
			break;
		default:
			break;
		}
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
void listNameCards(Namecard namecard[]) {
	printf("listNameCards():\n");

	int numberOfNamecards = (int) sizeof(namecard);

	if (numberOfNamecards != 0) {
		for (int i = 0; i < numberOfNamecards; i++) {
			printf("nameCardID: %d", namecard[i].nameCardID);
			printf("personName: %s", namecard[i].personName);
			printf("companyName: %s", namecard[i].companyName);
		}
	}
	else {
		printf("The name card holder is empty\n");
	}
}

// Function does XXX
void addNameCard(Namecard namecard[]) {
	// TODO: SORTING BASED ON ID IN ASCENDING ORDER

	int inputNameCardID;
	char inputPersonName[20];
	char inputCompanyName[20];

	int numberOfNamecards = (int) sizeof(namecard);

	if (numberOfNamecards >= 5) {
		printf("The name card folder is full");
	}
	else {
		printf("Enter nameCardID:\n");
		scanf_s("%d", &inputNameCardID);
		printf("Enter personName:\n");
		scanf_s("%s", &inputPersonName);
		printf("Enter companyName:\n");
		scanf_s("%s", &inputCompanyName);

		for (int i = 0; i < numberOfNamecards; i++) {
			if (namecard[i].nameCardID == inputNameCardID) {
				printf("The nameCardID has already existed");
				return;
			}
		}
		namecard[numberOfNamecards + 1].nameCardID = inputNameCardID;
		namecard[numberOfNamecards + 1].personName[20] = inputPersonName;
		namecard[numberOfNamecards + 1].companyName[20] = inputCompanyName;
		printf("The name card has been added successfully");
	}
}

// Function does XXX
void removeNameCard() {
	printf("removeNameCard():\n");
}

// Function does XXX
void getNameCard() {
	printf("getNameCard():\n");
}
