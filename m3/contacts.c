/* -------------------------------------------
Name: Elisa Ng
Student number: 136265170
Email: eng-li@myseneca.ca
Section: SMM
Date: 03/22/2018
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name)
{
	char option1;

	printf("Please enter the contact's first name: ");
	scanf("%30s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &option1);
	yes();

	if (option1 == 'y' || option1 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", name->lastName);

}



// getAddress:
void getAddress(struct Address * address)
{
	char option2;

	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]s", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c", &option2);
	yes();

	if (option2 == 'y' || option2 == 'Y') { // evaluate what the user enter

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", address->postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", address->city);
}


// getNumbers:
void getNumbers(struct Numbers * number)
{
	char  option4, option5;

	printf("Please enter the contact's cell phone number: ");
	scanf("%10s", number->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &option4);
	
	if (option4 == 'y' || option4 == 'Y') { // evaluate what the user enter
		printf("Please enter the contact's home phone number: ");
		scanf("%10s", number->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &option5);
	
	if (option5 == 'y' || option5 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's business phone number: ");
		scanf("%10s", number->business);
	}
}


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact * contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}