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
	int highest = 0, lowest = 0, highday, lowday; // highest, lowest, highday and lowday define as integer
	float avarage; // avarage define as float
        int num = 0, totalhigh = 0, totallow = 0; 

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: "); // prompt user to enter a day
	scanf("%d", &day); // accept value from user
	printf("\n");

	if (day <= 3 || day >= 10)  // optional path if the user enter a wrong day
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: "); // prompt user to re-enter a value for day if is not between 3 and 10
		scanf("%d", &day); // accept value from user
		printf("\n"); // separate line
	}

	for (i = 0; i < day; i++) // first loop for the user to enter temperature 
	{
		printf("Day %d - High: ", i + 1); // prompt user to enter high day
		scanf("%d", &high[i]); // accept value from user 

		printf("Day %d - Low: ", i + 1); // prompt user to enter low day
		scanf("%d", &low[i]); // accept value from user

		if (high[i] > highest) // optional path to display highest day
		{
			highest = high[i];
			highday = i + 1;
		}

		if (low[i] < lowest) // optional path to display lowest day
		{
			lowest = low[i];
			lowday = i + 1;
		}

	}

	printf("\n");
	printf("Day  Hi  Low\n"); // prompt to user

	for (i = 0; i < day; i++) // second loop to do a parallel array
	{
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);

	}

	printf("\nThe highest temperature was %d, on day %d\n", highest, highday); // prompt user the highest day 
	printf("The lowest temperature was %d, on day %d\n", lowest, lowday); // propmt user the lowest day 


	
	for (num = 0; num <= day; num++)
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
		scanf("%d", &num);

		if (num <= -1)
		{
			printf("\nGoodbye!\n");
			goto here;
		}
		
		
		
		while (num > day)
		{
                        printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", day);
			scanf("%d", &num);
		}
                for (i = 0; i < num; i++)
		{
			totalhigh = totalhigh + high[i];
			totallow = totallow + low[i];
		}


			avarage = ((float)(totalhigh + totallow)) / (num * 2); // calculate te avarage temperature
			printf("\nThe average temperature up to day %d is: %.2f\n", num, avarage); // propmpt the user the avarage temperature 
                        totalhigh = 0;
                        totallow = 0;

		}

		
	
			
	here : return 0;
}
