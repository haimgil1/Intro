/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/

#include <stdio.h> 
#include "mission1.h"
#include "mission2.h"
#include "mission3.h"
#include "mission4.h"
#include "mission5.h"
/************************************************************************
* function name: main
* The Input:none
* The output:none
* The Function operation: The function recives from the user number of
* mission between 1-5 and do the task.
* Note: In case the user enterd number that diffrent from 0-5 the function
* will print error message and ask him again.
* Note: In case the user entered 0, the program will end.
*************************************************************************/
int main()
{
	int mission;
	do
	{
		printf("Please select the assignment:\n");
		printf("\t0. Exit\n");
		printf("\t1. Shift right\n");
		printf("\t2. Sub ascending array\n");
		printf("\t3. Palindrome\n");
		printf("\t4. Calculator\n");
		printf("\t5. Second largest\n");
		scanf("%d", &mission);
		switch (mission)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			ShiftRight();
			break;
		}
		case 2:
		{
			SubAscendingArray();
			break;
		}
		case 3:
		{
			Palindrome();
			break;
		}
		case 4:
		{
			SimpleCalculator();
			break;
		}
		case 5:
		{
			SeconedLargest();
			break;
		}
		default:
		{
			printf("Error in assignment number, please try again.\n\n");
		}
		} //end of switch
	} while (mission != 0);
	return 0;
}