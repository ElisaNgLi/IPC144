/* -------------------------------------------
Name: Elisa Ng
Student number: 136265170
Email: eng-li@myseneca.ca
Section: SMM
Date: 03/09/2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name n1;
	struct Address a1;
	struct Numbers n2;
	char option1, option2, option3, option4, option5;


	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");


	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", n1.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%s", &option1);

	if (option1 == 'y' || option1 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", n1.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", n1.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &a1.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%40s", a1.street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%s", &option2);

	if (option2 == 'y' || option2 == 'Y') { // evaluate what the user enter

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &a1.apartmentNumber);
	}
	while (getchar() != '\n'); // loop that read and discard characters until it has read the newline
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", a1.postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", a1.city);

	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%s", &option3);

	if (option3 == 'y' || option3 == 'Y') {// evaluate what the user enter

		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", n2.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%s", &option4);

	if (option4 == 'y' || option4 == 'Y') { // evaluate what the user enter
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", n2.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%s", &option5);

	if (option5 == 'y' || option5 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", n2.business);
	}

	// Display Contact Summary Details
	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", n1.firstName);
	printf("Middle initial(s): %s\n", n1.middleInitial);
	printf("Last name: %s\n", n1.lastName);
	printf("\n");

	printf("Address Details\n");
	printf("Street number: %d\n", a1.streetNumber);
	printf("Street name: %s\n", a1.street);
	printf("Apartment: %d\n", a1.apartmentNumber);
	printf("Postal code: %s\n", a1.postalCode);
	printf("City: %s\n", a1.city);
	printf("\n");

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", n2.cell);
	printf("Home phone number: %s\n", n2.home);
	printf("Business phone number: %s\n", n2.business);
	// Display Completion Message
	printf("\nStructure test for Name, Address, and Numbers Done!\n");


	return 0;
}
