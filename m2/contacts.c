/* -------------------------------------------
Name:Elisa Ng
Student number: 136265170
Email: eng-li@myseneca.ca
Section: SMM
Date: 03/15/2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name * name)
{
	char option1;
	
	//printf("Contact Management System\n");
	//printf("-------------------------\n");

	printf("Please enter the contact's first name: ");
	scanf("%30s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%s", &option1);

	if (option1 == 'y' || option1 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", name->lastName);

}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address * address)
{
	char option2;
	
	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%40s", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%s", &option2);

	if (option2 == 'y' || option2 == 'Y') { // evaluate what the user enter

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
	}
	while (getchar() != '\n'); // loop that read and discard characters until it has read the newline
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", address->postalCode);
	printf("Please enter the contact's city: ");
	scanf("%40s", address->city);
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers * number)
{
	char option3, option4, option5;
	
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%s", &option3);

	if (option3 == 'y' || option3 == 'Y') {// evaluate what the user enter

		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", number->cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%s", &option4);

	if (option4 == 'y' || option4 == 'Y') { // evaluate what the user enter
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", number->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%s", &option5);

	if (option5 == 'y' || option5 == 'Y') { // evaluate what the user enter 
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", number->business);
	}
}

