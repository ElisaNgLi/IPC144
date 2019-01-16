/*
	 Name:      Elisa Ng
	 Student#:  136265170
	 Section:   SMM
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
int main(void)
{
	double amount, balance, balance2; // amount, balance, balance 2 are double
	int Loonies, Quarters; // Loonies and Quarters are integer

	printf("Please enter the amount to be paid: $"); // prompt user for amount input
	scanf("%lf", &amount); // accept amount value from user

	Loonies = amount; 
	printf("Loonies required: %d,", Loonies); // prompt Loonies to user
	balance = amount - Loonies; // calculate balance of Loonies
	printf(" balance owing $%.2lf\n", balance); // prompt balance of Loonies to user

	Quarters = balance / 0.25; // calculate quarters
	printf("Quarters required: %d,", Quarters); // prompt amount of quarters to user
	balance2 = balance - Quarters*0.25; // calculate balance of the quarters
	printf(" balance owing $%.2lf\n", balance2); // prompt balance of quarters to user

	return 0;

}
