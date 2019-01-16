/*
Name: Elisa Ng
Student number: 135265170
Email: eng-li@myseneca.ca
Workshop: 5
Section: SMM
Date: 02-22-18
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2// Define Number of Employees "SIZE" to be 2

// Declare Struct Employee 
struct employees
{
	int id; // id as integer
	int age; // age as integer
	double salary; // salary as a double
};

/* main program */
int main(void) {
	int i = 0; // i as integer
	int option = 0; // option as integer
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct employees emp[SIZE];
	

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");


			for (i = 0; i < SIZE; i++) { // loop to check the data
				if (emp[i].id > 0)
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);// Use "%6d%9d%11.2lf" formatting in a  printf statement to display
				
             
			}
			printf("\n");


			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");
			if (SIZE >i) { //Check for limits on the array and add employee 
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].salary);
				i++;
				printf("\n");
			}else{
           printf("ERROR!!! Maximum Number of Employees Reached\n"); //display error if the user enter more data 
		   printf("\n");
			}


			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}