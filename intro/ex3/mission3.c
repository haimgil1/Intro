/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/
#include <stdio.h>
#include "mission3.h"

/************************************************************************
* function name: Palindrome
* The Input:none
* The output:none
* The Function operation: The function recives from the user array length
* and the array and print if the array is palindrom.
* Note: 0 is palindrome.
*************************************************************************/
void Palindrome()
{
	int array[SIZE];
	int arrayLength;
	int palindrom,i;

	// Initializing the array the length of the array.
	arrayLength = InitializingArray(array);
	// Checks if the array is palindrom.
	palindrom = IsPalindrome(array, arrayLength);

	// 1 is palindrome and 0 is not.
	if (palindrom == 1)
	{
		printf("Your array is palindrome.\n\n");
	}
	else
	{
		printf("Your array is not palindrome.\n\n");
	}
}

/************************************************************************
* function name: IsPalindrome
* The Input: array and array length
* The output:1 or 0
* The Function operation: The function recives array and array length
* and return 1 if the array is 1 and 0 if not.
*************************************************************************/
int IsPalindrome(int a[], int size)
{
	int i;
	// This for checking if the array is not palindrome.
	for (i = 0; i < size / 2; i++)
	{
	    if (a[i] != a[size - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}
