#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
	char name[20];
	int telno;
} PhoneBk;

void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);

int main() {
	PhoneBk s[MAX];
	char t[20], *p;
	int size = 0, choice;
	char dummychar;

	printf("Select one of the following options: \n");
	printf("1: readin()\n");
	printf("2: search()\n");
	printf("3: printPB()\n");
	printf("4: exit()\n");

	do {
		printf("Enter your choice: \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			scanf("%c", &dummychar);
			size = readin(s);
			break;
		case 2:
			scanf("%c", &dummychar);
			printf("Enter search name: \n");
			fgets(t, 20, stdin);
			if (p = strchr(t, '\n')) *p = '\0';
			search(s, size, t);
			break;
		case 3:
			printPB(s, size);
			break;
		}
	} while (choice < 4);
}

void printPB(PhoneBk *pb, int size) {
	printf("The phonebook list:\n");
	if (size == 0) {
		printf("Empty phonebook\n");
	}
	else {
		for (int i = 0; i < size; i++) {
			printf("Name: %s\n", pb->name);
			printf("Telno: %d\n", pb->telno);
			pb++;
		}
	}
}

int readin(PhoneBk *pb) {
	int size = 0;

	while (1) {
		printf("Enter name:\n");
		fgets(pb->name, 20, stdin);
		pb->name[strcspn(pb->name, "\n")] = 0;

		if (strcmp(pb->name, "#") == 0) {
			break;
		}
		else {
			printf("Enter tel:\n");
			scanf("%d", &(pb->telno));
			getchar();

			size++;
			pb++;
		}
	}
	return size;
}

void search(PhoneBk *pb, int size, char *target) {
	int nameFoundFlag = 0;

	for (int i = 0; i < size; i++) {
		if (strcmp(pb->name, target) == 0) {
			printf("Name = %s, Tel = %d\n", pb->name, pb->telno);
			nameFoundFlag = 1;
			break;
		}
		pb++;
	}
	if (nameFoundFlag == 0) {
		printf("Name not found!\n");
	}
}
