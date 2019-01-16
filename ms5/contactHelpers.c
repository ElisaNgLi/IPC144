/* -------------------------------------------
Name: Elisa Ng
Student number: 136265170
Email: eng-li@myseneca.ca
Section: SMM
Date: 04/03/2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");

	clearKeyboard(); // empty statement intentional
}

// getInt:
int getInt(void)
{
	int value;
	char NL;

	do {

		scanf("%d%c", &value, &NL);
		if (NL != '\n') {

			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');

	return value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int value1, keeptrying = 1;
	do {
		value1 = getInt();
		if (value1< min || value1> max) {

			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
		else {
			keeptrying = 0;
		}

	} while (keeptrying == 1);
	return value1;
}

// yes:
int yes(void)
{
	char value2 = 0;
	char newline = 0;
	do {
		scanf("%c%c", &value2, &newline);

		if (!(value2 == 'Y' || value2 == 'y' || value2 == 'N' || value2 == 'n') || (newline != '\n')) {

			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");


		}
		else if (value2 == 'y' || value2 == 'Y') {
			return 1;
		}
		else {
			return 0;
		}

		clearKeyboard();
	} while (newline != '\n');
	return newline;

}

// menu:
int menu(void)
{
	int opt = 0;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");
	opt = getIntInRange(0, 6);
	return opt;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
				{ "Sasha",{ '\0' }, "Williams" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9052223333", "9052223333", "9054445555" } },
	};
	int option;
	int done = 0;
	do {
		option = menu();
		switch (option)
		{
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			printf("<<< Feature to sort is unavailable >>>\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				done = 1;
			}
			printf("\n");
			break;

		}

	} while (done != 1);
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	
	for (i = 0; i < size; i++) {

		if (strcmp(cellNum, contacts[i].numbers.cell) == 0) {

			return i;
		}
	}

			return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int totalcontacts) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalcontacts);
}


// displayContact:
void displayContact(const struct Contact* contact) {

	if (contact->name.middleInitial[0] != '\0') {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);

}


// displayContacts:
void displayContacts(const struct Contact contact[], int size){
	
	int total = 0;
	int i;
    displayContactHeader();
	for (i = 0; i < size; i++){
		if (strlen(contact[i].numbers.cell) > 0) {
			displayContact(&contact[i]);
			total++;
		}
	}
	displayContactFooter(total);
}


// searchContacts:
void searchContacts(const struct Contact contact[], int n) {
	char cellNum[11];
	int contactIndex = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	printf("\n");
	contactIndex = findContactIndex(contact, n, cellNum);

	if (contactIndex == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		displayContact(&contact[contactIndex]);
		printf("\n");
	}

}


// addContact:
void addContact(struct Contact contact[], int  size) {
	int j;
	int i;
	int contactcount = 0;
	
	for (i = 0; i < size; i++) {
		if (strlen(contact[i].numbers.cell) != 0)
			contactcount++;
	}

		if (contactcount==size){
			printf("\n*** ERROR: The contact list is full! ***\n");
		}else{
			for (j = 0; j < size; j++) {
				if (strlen(contact[j].numbers.cell) == 0) {
					printf("\n");
					getContact(&contact[j]);
					printf("--- New contact added! ---\n");
				}
	}
	}

}


// updateContact:
void updateContact(struct Contact contact[], int i) {
	char contactInput[11] = { '\0' };
	int option = 0;
	int contactIndex;
	int contacti;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(contactInput);

	contactIndex = findContactIndex(contact, i, contactInput);
	contacti = findContactIndex(contact, i, contactInput);

	if (contacti == -1) {

		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:");
		printf("\n");
		displayContact(&contact[contactIndex]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		option = yes();

		if (option == 1) {
			getName(&contact[contactIndex].name);
		}

		printf("Do you want to update the address? (y or n): ");
		getchar();
		option = yes();

		if (option == 1) {
			getAddress(&contact[contactIndex].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		getchar();
		option = yes();

		if (option == 1) {
			contact[contactIndex].numbers.home[0] = '\0';
			contact[contactIndex].numbers.cell[0] = '\0';
			contact[contactIndex].numbers.business[0] = '\0';
			getNumbers(&contact[contactIndex].numbers);
		}

		printf("--- Contact Updated! ---\n");

	}

}
// deleteContact:
void deleteContact(struct Contact contact[], int i) {
	char contactInput[11] = { '\0' };
	int option = 0;
	int contactIndex;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(contactInput);
	contactIndex = findContactIndex(contact, i, contactInput);

	if (contactIndex < 0) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		printf("Contact found:");
		printf("\n");

		displayContact(&contact[contactIndex]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		option = yes();
		if (option == 1) {
			contact[contactIndex].address.apartmentNumber = 0;
			contact[contactIndex].numbers.home[0] = '\0';
			contact[contactIndex].numbers.cell[0] = '\0';
			contact[contactIndex].numbers.business[0] = '\0';
			printf("--- Contact deleted! ---\n");

		}


	}
}


// sortContacts:
/*void sortContacts(struct Contact contact[], int) {

}*/