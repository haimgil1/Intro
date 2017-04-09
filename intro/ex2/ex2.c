#define _CRT_SECURE_NO_WARNINGS
#include <math.h> 
#include <stdio.h>
/******************************************
* Haim Gil
* 203676945
* 8911003
* ex2
******************************************/
int main()
{
	int mission,i,squre,boom,exsist;
	unsigned long prime;
	do
	{
		scanf("%d", &mission);
		// this if checks weather the user enterd a number that different from 1,2,0
		if (mission != 1 && mission != 2 && mission != 0)
		{
			printf("\n");
		}
		// this if checks weather the user enterd 1
		if (mission == 1)
		{
			scanf("%lu", &prime);
			squre = sqrt(prime);
			// this if checks weather the number is 1 or 0 then print no
			if (prime == 1 || prime == 0)
			{
				printf("NO\n");
			}
			// this if checks weather 2 divide the number
			else if (prime != 2 && prime % 2 == 0)
			{
				printf("NO\n");
			}
			// this if checks weather the number is prime
			else
			{
				for (i = 2; i <= squre; i++)
				{
					if (prime%i == 0)
					{
						printf("NO\n");
						break;
					}
				}
				//this if checks weather there isn't number that divide the number that the user enterd
				if (squre == i - 1)
				{
					printf("YES\n");
				}
			} //end of else
		} //end of mission 2
		if (mission == 2)
		{
			printf("Please enter a number for 7 boom game\n");
			scanf("%d", &boom);
			printf("[");
			if (boom >= 7)
			{
				printf("7");
			}
			// this for print all the numbers that divide 7 and are less then "boom"
			for (i = 14; i <= boom; i++)
			{
				if (i % 7 == 0)
				{
					printf(",%d", i);
				}
				exsist = i;
				// this while print all the numbers that 7 is exsist and are less then "boom"
				while (exsist >= 7)
				{
					// this if checks weather 7 is exsist in the number and it hasnt print before (if the number divide 7 too) and print it
					if (exsist % 10 == 7 && i % 7 != 0)
					{
						printf(",%d", i);
					}
					exsist = exsist / 10;
				}
			} // end of for
			printf("]\n");
		} // end of mission 2
		if (mission == 0)
		{
			return 0;
		} // end of mission 0
	} while (mission != 0);
	return 0;
}