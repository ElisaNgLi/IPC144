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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+


// getName:
void getName(struct Name * name)
{
	int option1 = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	getchar();
	option1 = yes();

	if (option1 == 1) { // evaluate what the user enter 
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]s", name->lastName);

}



// getAddress:
void getAddress(struct Address * address)
{
	int option2 = 0;

	printf("Please enter the contact's street number: ");
	//scanf("%d", &address->streetNumber);
	//getchar();
	address->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]s", address->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	getchar();
	option2 = yes();


	if (option2 == 1) { // evaluate what the user enter

		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", address->postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]s", address->city);
}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers * number)
{
	int  option4 = 0, option5 = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(number->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option4 = yes();


	if (option4 == 1) { // evaluate what the user enter
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(number->home);

	}

	printf("Do you want to enter a business phone number? (y or n): ");
	//scanf(" %c", &option5);
	option5 = yes();

	if (option5 == 1) { // evaluate what the user enter 
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(number->business);

	}
}


// getContact:
void getContact(struct Contact * contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
