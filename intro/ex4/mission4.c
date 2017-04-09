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
#include "mission4.h"
#include "helpFuncs.h"

/*****************************************************************************
* function name: PrintsAllstud.
* The Input: Number of student, name of the students, name of the courses,
* grades and nummber of grades.
* The output: None
* The Function operation: The function recives from the user a-e characters.
* Note: In case the input is 0, the function return to main menu.
*****************************************************************************/
void PrintsAllstud(int *pNumStudents, char ***pStudentsNames, 
	              char ****pCourseNames, int ***pGrades, int **pnumOfgrades)
{
	PrintAggregation();
	char dummy, mission;
	scanf("%c", &dummy);
	scanf("%c", &mission);
	Sorting(pStudentsNames, pNumStudents, pCourseNames, pGrades, pnumOfgrades);
	switch (mission)
	{
	case 48:
	{
		break;
	}
	case 'a':
	{
		AvgAll(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'b':
	{
		MaxAll(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'c':
	{
		MinAll(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'd':
	{
		SumAll(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'e':
	{
		NumOfCoursesAll(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	default:
	{
		break;
	}
	}
}

/*****************************************************************************
* function name: Sorting
* The Input: Number of student, name of the student, name of the courses,
* grades and nummber of grades.
* The output: None
* The Function operation: The function sorting the array.
* Note: I took this function from lesson 7.
*****************************************************************************/
void Sorting(char ***pStudentsNames, int *pNumStudents, char ****pCourseNames,
	        int ***pGrades, int **pnumOfgrades)
{
	int i, j;
	char *tempStudName, **tempCourse;
	int *tempGrades, tempNumOfGrades;
	// Go over all the students.
	for (i = 0; i < *pNumStudents - 1; i++)
	{
		for (j = 0; j < *pNumStudents - 1 - i; j++)
		{
			// Sorting the array by names.
			if (strcmp((*pStudentsNames)[j], (*pStudentsNames)[j + 1]) > 0)
			{
				//swap the elements
				tempStudName = (*pStudentsNames)[j];
				(*pStudentsNames)[j] = (*pStudentsNames)[j + 1];
				(*pStudentsNames)[j + 1] = tempStudName;

				tempCourse = (*pCourseNames)[j];
				(*pCourseNames)[j] = (*pCourseNames)[j + 1];
				(*pCourseNames)[j + 1] = tempCourse;

				tempGrades = (*pGrades)[j];
				(*pGrades)[j] = (*pGrades)[j + 1];
				(*pGrades)[j + 1] = tempGrades;

				tempNumOfGrades = (*pnumOfgrades)[j];
				(*pnumOfgrades)[j] = (*pnumOfgrades)[j + 1];
				(*pnumOfgrades)[j + 1] = tempNumOfGrades;
			}
		}
	}
}

/*****************************************************************************
* function name: AvgAll.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function prints all the avg grades of each
* student.
*****************************************************************************/
void AvgAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades)
{
	int i, j, avg, sum;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		sum = 0;
		avg = 0;

		// Go over all the grades of the students and sumerize them.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			sum += (*pGrades)[i][j];
		}

		// Calculating the avg.
		avg = sum / (*pnumOfgrades)[i];
		printf("%s, %d\n", (*pStudentsNames)[i], avg);
	}
}
/*****************************************************************************
* function name: MaxAll.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function prints all the max grade of each
* student.
*****************************************************************************/
void MaxAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades)
{
	int i, j, max;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		max = 0;

		// Go over all the grades of the students.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			// Finding the max grade.
			if ((*pGrades)[i][j] > max)
			{
				max = (*pGrades)[i][j];
			}
		}
		printf("%s, %d\n", (*pStudentsNames)[i], max);
	}
}

/*****************************************************************************
* function name: MinAll.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function prints all the min grade of each
* student.
*****************************************************************************/
void MinAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades)
{
	int i, j, min;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		min = 100;

		// Go over all the grades of the students.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			// Finding the min grade.
			if ((*pGrades)[i][j] < min)
			{
				min = (*pGrades)[i][j];
			}
		}
		printf("%s, %d\n", (*pStudentsNames)[i], min);
	}
}

/*****************************************************************************
* function name: SumAll.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function prints all the sum grade of each
* student.
*****************************************************************************/
void SumAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades)
{
	int i, j, sum;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		sum = 0;

		// Go over all the grades of the students and sumerize them.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			sum += (*pGrades)[i][j];
		}
		printf("%s, %d\n", (*pStudentsNames)[i], sum);
	}
}

/*****************************************************************************
* function name: NumOfCoursesAll.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function prints the number of courses of each
* student.
*****************************************************************************/
void NumOfCoursesAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	                int** pnumOfgrades)
{
	int i;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		printf("%s, %d\n", (*pStudentsNames)[i], (*pnumOfgrades)[i]);
	}
}
