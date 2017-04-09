/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/
#include <stdio.h>
#include "mission5.h"
/************************************************************************
* function name: SeconedLargest
* The Input:none
* The output:none
* The Function operation: The function recives from the user array
* and print the second largest number.
* Note: In case there is two or more max the funcrion will 
* print the next max number.
*************************************************************************/
void SeconedLargest()
{
	unsigned int num;
	int max = 0, secondMax = 0;
	printf("Please enter your array: \n");

	// The array ends with 0.
	do
	{
		scanf("%u", &num);

	    /* This if checks weather num is greater than max and than 
		 * replace max in second max and replace max in num.
		 */
		if (num > max)
		{
			secondMax = max;
			max = num;
		}

		/* This if checks weather num is greater the second max and
		 * differ from max and replace secondmax in num.
		 */
		else if ((num > secondMax) && (num != max))
		{
			secondMax = num;
		}
	} while (num != 0);

	// Printing the second max value.
	printf("The second largest value is %d.\n\n", secondMax);
}