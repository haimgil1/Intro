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
#include "mission3.h"
#include "helpFuncs.h"

/*****************************************************************************
* function name: studWithMaxComputedGrade.
* The Input: Number of student, name of the students, name of the courses,
* grades and nummber of grades.
* The output: None
* The Function operation: The function recives from the user a-e characters.
* Note: In case the input is 0, the function return to main menu.
*****************************************************************************/
void studWithMaxComputedGrade(int *pNumStudents, char ***pStudentsNames,
	char ****pCourseNames, int ***pGrades, int **pnumOfgrades)
{
	// No student error massage.
	if (*pNumStudents == 0)
	{
		printf("Error: there are no students.\n");
		return;
	}
	PrintAggregation();
	char dummy, mission;
	scanf("%c", &dummy);
	scanf("%c", &mission);
	switch (mission)
	{
	case 48:
	{
		break;
	}
	case 'a':
	{
		Avg(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'b':
	{
		Max(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'c':
	{
		Min(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'd':
	{
		Sum(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	case 'e':
	{
		NumOfCourses(pNumStudents, pStudentsNames, pGrades, pnumOfgrades);
		break;
	}
	default:
	{
		break;
	}
	}
}

/*****************************************************************************
* function name: Avg.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function finds the student with the max average
* grades and print it.
*****************************************************************************/
void Avg(int* pNumStudents, char*** pStudentsNames,
	    int*** pGrades, int** pnumOfgrades)
{
	int i, j, avg = 0, student = 0, sum, max = 0;;
	
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

		// Finding the max avg.
		if (avg > max)
		{
			max = avg;
			student = i;
			continue;
		}

		/* If there are two max avg grades, the student that placed before
		   the other in the 'abc' will be the max grade.
		 */
		if (avg == max)
		{
			if (strcmp((*pStudentsNames)[student], (*pStudentsNames)[i]) > 0)
			{
				max = avg;
				student = i;
			}
		}
	}
	printf("%s, %d\n", (*pStudentsNames)[student], max);
}

/*****************************************************************************
* function name: Max.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function finds the student with the max
* grade and print it.
*****************************************************************************/
void Max(int* pNumStudents, char*** pStudentsNames,
	    int*** pGrades, int** pnumOfgrades)
{
	int i, j, max = 0, student = 0;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		// Go over all the grades of the students.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			// Finding the max grade.
			if ((*pGrades)[i][j] > max)
			{
				max = (*pGrades)[i][j];
				student = i;
				continue;
			}

			/* If there are two max grades, the student that placed before the
			   other in the 'abc' will be the max grade.
			*/
			if ((*pGrades)[i][j] == max)
			{
			  if (strcmp((*pStudentsNames)[student], (*pStudentsNames)[i]) > 0)
				{
					max = (*pGrades)[i][j];
					student = i;
				}
			}
		}
	}
	printf("%s, %d\n", (*pStudentsNames)[student], max);
}

/*****************************************************************************
* function name: Min.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function finds the student with the biggest min
* grade and print it.
*****************************************************************************/
void Min(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	    int** pnumOfgrades)
{
	int i, j, min, student = 0, max = 0;

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

		// Finding the max grade.
		if (min > max)
		{
			max = min;
			student = i;
			continue;
		}

		/* If there are two max grades, the student that placed before the other
		in the 'abc' will be the max grade.
		*/
		if (min == max)
		{
			if (strcmp((*pStudentsNames)[student], (*pStudentsNames)[i]) > 0)
			{
				max = min;
				student = i;
			}
		}
	}
	printf("%s, %d\n", (*pStudentsNames)[student], max);
}

/*****************************************************************************
* function name: Sum.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function finds the student with the biggest max
* grade and print it.
*****************************************************************************/
void Sum(int* pNumStudents, char*** pStudentsNames,
	    int*** pGrades, int** pnumOfgrades)
{
	int i, j, student = 0, sum, max = 0;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{
		sum = 0;
		// Go over all the grades of the students and sumerize them.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			sum += (*pGrades)[i][j];
		}

		// Finding the max sum.
		if (sum > max)
		{
			max = sum;
			student = i;
			continue;
		}

		/* If there are two max sum, the student that placed before the other
		in the 'abc' will be the max grade.
		*/
		if (sum == max)
		{
			if (strcmp((*pStudentsNames)[student], (*pStudentsNames)[i]) > 0)
			{
				max = sum;
				student = i;
			}
		}
	}
	printf("%s, %d\n", (*pStudentsNames)[student], max);
}

/*****************************************************************************
* function name: NumOfCourses.
* The Input:Number of student, name of students, grades and nummber of grades
* The output: None
* The Function operation: The function finds the student with the biggest 
* number of grades and print it.
*****************************************************************************/
void NumOfCourses(int* pNumStudents, char*** pStudentsNames,
	             int*** pGrades, int** pnumOfgrades)
{
	int i, student = 0, max = 0;

	// Go over all the students.
	for (i = 0; i < *pNumStudents; i++)
	{

		// Finding the student with the biggest number of courses.
		if ((*pnumOfgrades)[i] > max)
		{
			max = (*pnumOfgrades)[i];
			student = i;
			continue;
		}

		/* If there are two students with the max number of courses,the student
		   that placed before the other in the 'abc' will be the max grade.
		*/
		if ((*pnumOfgrades)[i] == max)
		{
			if (strcmp((*pStudentsNames)[student], (*pStudentsNames)[i]) > 0)
			{
				max = (*pnumOfgrades)[i];
				student = i;
			}
		}
	}
	printf("%s, %d\n", (*pStudentsNames)[student], max);
}
