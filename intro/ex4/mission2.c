/******************************************
* Haim Gil
* 203676945
* 8911003
* ex4
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "helpFuncs.h"
#include "mission1.h"
#include "mission2.h"

/*****************************************************************************
* function name: DeleteStudent
* The Input: Number of student, name of the student, name of the courses,
* grades and nummber of grades.
* The output: None.
* The Function operation: The function scan a name and if the name is exsist, 
* the funtion delete the name.
* Note: In case there are no students, error massage will be printed.
* Note: In case the name is illegal, error massage will be printed.
* Note: In case there isn't a name like this, error massage will be printed.
*****************************************************************************/
void DeleteStudent(int *pNumStudents, char ***pStudentsNames, 
	              char ****pCourseNames, int ***pGrades, int **pnumOfgrades)
{
	char dummy, ch;
	char *tempString = NULL;
	char *tempName = NULL;
	int check = 0;
	int j = 0, i = 0, sizeString = 10;

	// Ignoring the '\n' that recived from tha main.
	scanf("%c", &dummy);

	// If there are no students.
	if (*pNumStudents == 0)
	{
		printf("Error: there are no students.\n");
		return;
	}
	else
	{
		// Allocating size.
		tempString = (char*)malloc(sizeString * sizeof(char*));
		FailedOneCharArr(tempString);

		// Scaning the name.
		do
		{
			scanf("%c", &ch);
			tempString[i] = ch;

			// Reallocate more size.
			if (i == sizeString)
			{
				sizeString += 10;
				tempString = (char*)realloc(tempString, sizeString * sizeof(char*));
				FailedOneCharArr(tempString);
			}
			i++;
		} while (ch != '\n');

		// Mark the last input.
		tempString[i] = '\0';

		// Checks if the name is legal.
		tempName = CheckInput('\n', tempString, &check, &j);
		
		// Free tempString.
		free(tempString);
		// Name is legal.
		if (check == 0)
		{
			// Find the student with the same name the user entered.
			i = FindingStudent(pNumStudents, tempName, pStudentsNames);
			
			// The function return -1 in case there is no such name.
			if (i != -1)
			{
				// Free the information of the student.
				free((*pStudentsNames)[i]);
				FreeData((*pCourseNames)[i], (*pnumOfgrades)[i]);
				free((*pGrades)[i]);
				(*pnumOfgrades)[i] = '\0';

				// Moving all the information of the the next students.
			   	 MoveIndex(pNumStudents, pStudentsNames, pCourseNames,
					      pGrades, pnumOfgrades, i);	
				printf("Student \"%s\" deleted.\n", tempName);
				free(tempName);
			}
			// There isn't a student like this.
			else
			{
				printf("Error: student name does not exist.\n");
				// Free the temp name.
				free(tempName);
				return;
			}
		}
		// The name is illegal.
		else
		{
			printf("Error: invalid name.\n");
			// Free the temp name.
			free(tempName);
			return;
		}
	}
}

/*****************************************************************************
* function name: MoveIndex
* The Input: Number of student, name of the student, name of the courses,
* grades, nummber of grades and index.
* The output: None
* The Function operation: The function moving all the information of
* all the students that are placed after the index.
*****************************************************************************/
void MoveIndex(int *pNumStudents,char ***pStudentsNames, char ****pCourseNames,
	          int ***pGrades, int **pnumOfgrades, int index)
{
	int j;
	// Moving index.
	for (j = index + 1; j < (*pNumStudents); j++)
	{
		(*pStudentsNames)[j - 1] = (*pStudentsNames)[j];
		(*pCourseNames)[j - 1] = (*pCourseNames)[j];
		(*pGrades)[j - 1] = (*pGrades)[j];
		(*pnumOfgrades)[j - 1] = (*pnumOfgrades)[j];
	}
	// The number of students is now less one.
	*pNumStudents -= 1;;
}
