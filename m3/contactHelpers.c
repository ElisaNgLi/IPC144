/* -------------------------------------------
Name: Elisa Ng
Student number: 136265170
Email: eng-li@myseneca.ca
Section: SMM
Date: 03/22/2018
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");

	clearKeyboard(); // empty statement intentional
}


// getInt: Empty function definition goes here:
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


// getIntInRange: Empty function definition goes here:
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

// yes: Empty function definition goes here:
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


// menu: Empty function definition goes here:
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


// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void)
{
	int option;
	int done = 0;
	do {
		option = menu();
		switch (option)
		{
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n");
			printf("\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n");
			printf("\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n");
			printf("\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n");
			printf("\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n");
			printf("\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n");
			printf("\n");
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
