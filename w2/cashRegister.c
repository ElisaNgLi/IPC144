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
	double amount, balance, balance2, GST, balance3; // amount, balance, balance2, GST and balance3 are double
	int Loonies, Quarters, Dimes, Nickels, balanced,balanced1; // Loonies, Quarters, Dimes, Nickels, balanced, balanced1 are integer
	double balancen; // balance of the Dime is double
	int Pennies, balancep; // Pennies and balancep are double

	printf("Please enter the amount to be paid: $"); // prompt user for amount input
	scanf("%lf", &amount); // accept amount value from user

	GST = (amount*.13) + .005; // calculate the GST
	printf("GST: %.2lf\n", GST); // prompt GST to user

	balance3 = amount + GST; // calculate the balance owing of the amount
	printf("Balance owing: $%.2lf\n", balance3); // prompt balance to user

	Loonies = balance3;
	printf("Loonies required: %d,", Loonies); // prompt Loonies to user
	balance = balance3 - Loonies; // calculate balance of Loonies
	printf(" balance owing $%.2lf\n", balance); // prompt balance of Loonies to user

	Quarters = balance / 0.25; // calculate quarters
	printf("Quarters required: %d,", Quarters); // prompt amount of quarters to user
	balance2 = balance - Quarters*0.25; // calculate balance of the quarters
	printf(" balance owing $%.2lf\n", balance2); // prompt balance of quarters to user

	Dimes = balance2 / 0.1; // calculate dimes
	printf("Dimes required: %d,", Dimes); // prompt amount of dimes to user
	balancen = balance2 - Dimes*0.1; // calculate balance of dimes
	printf(" balance owing $%.2lf\n", balancen); // prompt balance of dimes to user
	
	Nickels = balancen / 0.05; // calculate nickels
	printf("Nickels required: %d,", Nickels); // prompt amount of nickels to user
	balanced1 = balancen * 100; // calculate balance of nickels
	balanced = balanced1 % 5; // calculate balance of nickels
	printf(" balance owing $%.2lf\n", (float)balanced / 100); // prompt balance of nickels to user

	Pennies = balanced / 1; // calculate pennies
	printf("Pennies required: %d,", Pennies); // prompt amount of pennies to user
	balancep = balanced % 1; // calculate balance of pennies 
	printf(" balance owing $%.2lf\n", (float)balancep / 100); //prompt balance of pennies to user

	return 0;

}
