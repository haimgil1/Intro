/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/
#include <stdio.h>
#include "mission2.h"
/************************************************************************
* function name: SubAscendingArray
* The Input:none
* The output:none
* The Function operation: The function recives from the user array length
* and the array and print the max ascending array and his length.
* Note:In case the size of the array is 0 the function will print Length 0.
* Note: In case of two or more max ascending array in the same size the
* the function will print the first one.
*************************************************************************/
void SubAscendingArray()
{
    int array[SIZE];
	int arrayLength, first, last, maxLength, length;
	int i;

	// Initializing the array the length of the array.
	arrayLength = InitializingArray(array);

	// This if checks weather the array length is 0 and print nothing.
	if (arrayLength == 0)
	{
		printf("The max ascending array is: \n");
		printf("Length 0\n\n");
	}
	else
	{
		first = 0;
		last = 0;
		maxLength = 1;
		length = 1;

		// This for finding the max ascending array.
		for (i = 1; i < arrayLength; i++)
		{
			// This if checks weather there is ascending array and count it. 
			if (array[i] > array[i - 1])
			{
				length++;
			}
			else
			{
				length = 1;
			}

			// This if find tha max ascending array.
			if (length > maxLength)
			{
				maxLength = length;
				first = i - (maxLength - 1);
				last = i;
			}

			/*
		     * This if stop the loop if the amounts of the next numbers.
			 * in the array issmaller than the currect max ascending array.
			*/
			if ((maxLength >= arrayLength - i) && (length == 1))
			{
				break;
			}
		} // End of for loop.
		printf("The max ascending array is: ");

		// This for print the max ascending array.
		for (i = first; i <=last; i++)
		{
		   printf("%d ", array[i]);
		} 
		printf("\n");
		printf("Length %d \n\n", maxLength);
	} // End of else.
}