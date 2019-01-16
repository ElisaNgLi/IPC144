/*
Name: Elisa Ng
Student ID: 136265170
Section: IPC144SMM
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int i, day; // day and i define as integer 
	int high[10], low[10]; // high and low define as integer and using arrays

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: "); // prompt user to enter a day
	scanf("%d",&day); // accept value from user
	
	
	if (day <= 3 || day >= 10)  // optional path if the user enter a wrong day
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: "); // prompt user to re-enter a value for day if is not between 3 and 10
		scanf("%d", &day); // accept value from user
		printf("\n"); // separate line
	}

	for (i = 0; i < day;i++) // first loop for the user to enter temperature 
	{
		printf("Day %d - High: ", i + 1); // prompt user to enter high day
		scanf("%d",&high[i]); // accept value from user 

		printf("Day %d - Low: ", i + 1); // prompt user to enter low day
		scanf("%d",&low[i]); // accept value from user
	}

	printf("\n");
	printf("Day  Hi  Low\n"); // prompt to user

	for (i = 0; i < day; i++) // second loop to do a parallel array
	{
		printf("%d    %d    %d\n",i + 1, high[i], low[i]);
	}
	return 0;
}