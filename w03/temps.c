/*Name: Elisa Ng
Student ID: 136256170
Section: SMM
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define NUMS 4

int main(void)
{
	int high = 0, low = 0, i, j, total_high = 0, total_low = 0;
	float avarage;
	int highest = 0, lowest = 0, highday = 0,lowday = 0;

	printf("---=== IPC Temperature Analyzer ===---");
	for (i = 0; i < NUMS; i++) {

	for (j = 0; j<NUMS; j++, i++) {
			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			
			if (high>highest) {
				highest = high;
				highday = i + 1;
			}

			printf("\nEnter the low value for day %d: ", j + 1);
			scanf("%d", &low);

			if (low < lowest) {
				lowest = low;
				lowday = j + 1;
			}
			
			while (high < low || high >= 41 || low <= -41)
			{

				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

				printf("\nEnter the high value for day %d: ", i + 1);
				scanf("%d", &high);

				printf("\nEnter the low value for day %d: ", j + 1);
				scanf("%d", &low);
			}
			total_high += high;
			total_low += low;
		}
		avarage = (float)(total_high + total_low) / (NUMS * 2);
		printf("\nThe average (mean) temperature was: %.2f\n", avarage);

		
		

		printf("The highest temperature was %d, ", highest);
		printf("on day %d\n", highday);

		printf("The lowest temperature was %d, ", lowest);
		printf("on day %d\n", lowday);

	}

	

	return 0;

}
