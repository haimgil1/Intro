/******************************************
* Haim Gil
* 203676945
* 8911003
* ex4
******************************************/
#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>
#include "mission1.h"
#include "mission2.h"
#include "mission3.h"
#include "mission4.h"
#include "helpFuncs.h"
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
main ()
{
	char ch;
	int mission;
	PrintMenu();
	int numOfStudents = 0;
	char **studentNames =NULL;
	char ***courseNames = NULL;
	int **grades = NULL;
	int *numOfgrades = NULL;
	do
	{
		scanf("%c", &ch);
		mission = ch - '0';
		switch (mission)
		{
		case 0:
		{
			CleanExit(numOfStudents, studentNames, courseNames, grades, numOfgrades);
			return 0;
		}
		case 1:
		{
			InsertStudent(&numOfStudents, &studentNames, &courseNames, &grades, &numOfgrades);
			break;
		}
		case 2:
		{
			DeleteStudent(&numOfStudents, &studentNames, &courseNames, &grades, &numOfgrades);
			break;
		}
		case 3:
		{
			studWithMaxComputedGrade(&numOfStudents, &studentNames, &courseNames, &grades, &numOfgrades);
			break;
		}
		case 4:
		{
			PrintsAllstud(&numOfStudents, &studentNames, &courseNames, &grades, &numOfgrades);
			break;
		}
		case 5:
		{
			PrintMenu();
			continue;
		}
		case -38:
		{
			continue;
		}
		default:
		{
			printf("Error: unrecognized operation.\n");
			break;
		} 
		} //end of switch
		ShortMenu();
	} while (mission != 0);
	return 0;
}

