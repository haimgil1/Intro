/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/
#include <stdio.h>
#include "mission1.h"
/************************************************************************
* function name: ShiftRight
* The Input:none
* The output:none
* The Function operation: The function recives from the user array length,
* the array and number to shift right and print the new array.
* Note: In case arrayLength is 0 the function will print the shift right.
*************************************************************************/
void ShiftRight()
{
	int array[SIZE];
	int arrayLength, shiftRight;
	int i, j;
	
	// Initializing the array the length of the array.
	arrayLength = InitializingArray(array);
	printf("Please enter the number to shift right:\n");
	scanf("%d", &shiftRight);

	// This if checks weather the array length is 0 and print nothing.
	if (arrayLength == 0)
	{
		printf("Your array is: \n");
		printf("After %d shifts right is: \n\n", shiftRight);
	}
	else
	{
		printf("Your array is: ");
        // Printing the original array
		for (i = 0; i < arrayLength; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
		printf("After %d shifts right is: ", shiftRight);

		// If the shift right is bigger than the length of the arrray. 
		shiftRight %= arrayLength;
		j = arrayLength - shiftRight;

        // Printing the new array.
		for (i = 0; i < arrayLength; i++)
		{
			printf("%d ", array[(i + j) % arrayLength]);
		}
		printf("\n\n");
	} // End of else.
}
/************************************************************************
* function name: InitializingArray
* The Input: The function recives array
* The output: The function return the length of the array
* The Function operation: The function recives array Initializing it 
* and Initializing tha length of the array and return it.
*************************************************************************/
int InitializingArray(int array[])
{
	int i, arrayLength;
	printf("Please enter your array length and your array:\n");
	scanf("%d", &arrayLength);

	// Initialize the array
	for (i = 0; i < arrayLength; i++)
	{
		scanf("%d", &array[i]);
	}
	return arrayLength;
}



