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

/*****************************************************************************
* function name: ShortMenu.
* The Input: None.
* The output: None.
* The Function operation: The function print the short menu.
*****************************************************************************/
void ShortMenu()
{
	printf("Select the next operation (insert 5 for complete menu).\n");
}

/*****************************************************************************
* function name: PrintMenu.
* The Input: None.
* The output: None.
* The Function operation: The function print the main menu.
*****************************************************************************/
void PrintMenu()
{
	printf("Please select the operation:\n");
	printf("\t0. Exit.\n");
	printf("\t1. Insert or update student grades.\n");
	printf("\t2. Delete student information.\n");
	printf("\t3. Print the student with maximal computed grade.\n");
	printf("\t4. Print all the students with their computed grades.\n");
	printf("\t5. Print the menu.\n");
}

/*****************************************************************************
* function name: PrintAggregation.
* The Input: None.
* The output: None.
* The Function operation: The function print the aggregation menu.
*****************************************************************************/
void PrintAggregation()
{
	printf("Please select the aggregation method:\n");
	printf("\ta. Average grade.\n");
	printf("\tb. Maximal grade.\n");
	printf("\tc. Minimal grade. \n");
	printf("\td. Sum.\n");
	printf("\te. Count.\n");
	printf("\t0. Return the main menu.\n");
}

/*****************************************************************************
* function name: FindingStudent
* The Input: Number of student, name of the student, and the temp name.
* The output: index of where is the student with the temp name.
* The Function operation: The function recives temp name and check
* if there is a student with that name.
* Note: In case there isn't a student with that name the function
* will return -1.
*****************************************************************************/
int FindingStudent(int *pNumStudents, char *tempName, char ***pStudentsNames)
{
	int i;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{

		// Checks if there is a student that equal to temp name.
		if (strcmp((*pStudentsNames)[i], tempName) == 0)
		{
			return i;
		}
	}
	return -1;
}

/*****************************************************************************
* function name: FreeData
* The Input: Char arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FreeData(char** names, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		free(names[i]);
	}
	free(names);
}

/*****************************************************************************
* function name: FailedThreeCharArr
* The Input: Char arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FailedThreeCharArr(char*** names, int size)
{
	int i;
	if (NULL == names)
	{
		for (i = 0; i < size; i++)
		{
			FreeData(names[i], size);
		}
		free(names);
		printf("Error: there is not enough space./n");
		exit(0);
	}
}

/*****************************************************************************
* function name: FailedOneCharArr
* The Input: Char arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FailedOneCharArr(char* names)
{
	if (NULL == names)
	{
		free(names);
		printf("Error: there is not enough space./n");
		exit(0);
	}
}

/*****************************************************************************
* function name: FailedOneIntArr
* The Input: Int arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FailedOneIntArr(int* names)
{
	if (NULL == names)
	{
		free(names);
		printf("Error: there is not enough space./n");
		exit(0);
	}
}

/*****************************************************************************
* function name: FailedTwoCharArr
* The Input: Char arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FailedTwoCharArr(char** names, int size)
{
	if (NULL == names)
	{
		FreeData(names, size);
		printf("Error: there is not enough space./n");
		exit(0);
	}
}

/*****************************************************************************
* function name: FailedTwoIntArr
* The Input: int arr and his size.
* The output: None.
* The Function operation: Free the array.
*****************************************************************************/
void FailedTwoIntArr(int** names, int size)
{
	if (NULL == names)
	{
		free(names);
		printf("Error: there is not enough space./n");
		exit(0);
	}
}

/*****************************************************************************
* function name: CleanExit
* The Input: Number of students, Names of the students, names of the courses,
* grades and number of grades of each student.
* The output: None.
* The Function operation: Free all the information on every student.
*****************************************************************************/
void CleanExit(int NumStudents, char **StudentsNames, char ***CourseNames, int **Grades, int *numOfgrades)
{
	int i;
	for (i = 0; i < NumStudents; i++)
	{
		free(StudentsNames[i]);
		FreeData(CourseNames[i], numOfgrades[i]);
		free(Grades[i]);
	}
	free(StudentsNames);
	free(CourseNames);
	free(Grades);
	free(numOfgrades);
}

