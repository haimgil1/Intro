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
//haim gil: math,79; infi ,56;
//haim  gil: math,79; infi ,56;
//haim: infi ,98; math,99;
//haim: infi ,98; ath,99;
//haim: math,79; infi ,56;
//haim: math,79; infi ,56; logic,34;
//haigm: infi ,98; math,99; haha,56;
//gil: english ,56; bdida,78;
//gil: english ,56; bdida,99;
//lil: english ,98; bdida,99;

/*****************************************************************************
* function name: InsertStudent
* The Input: Number of student, name of the student, name of the courses,
* grades and nummber of grades.
* The output: None
* The Function operation: The function recives from the user name of student,
* his courses and his grades and save or update them.
* Note: In case the input is illegal, error message will be printed.
*****************************************************************************/
void InsertStudent(int *pNumStudents, char ***pStudentsNames, 
	char ****pCourseNames, int ***pGrades, int **pnumOfgrades)
{
	int i = 0, j = 0, check = 0, sizeStr = 10;
	char *tempString = NULL;
	char *tempName = NULL;
	char **tempCourseName = NULL;
	char **tempGrades = NULL;
	int *grades = NULL;
	int numOfcourses = 0;
	char dummy, ch;

	// Ignoring the '\n' that recived from tha main.
	scanf("%c", &dummy);
	// Allocate size to temp string.
	tempString = (char*)malloc(sizeStr * sizeof(char*));
	FailedOneCharArr(tempString);
	
	// Scaning the input from the user.
	do
	{
		scanf("%c", &ch);
		tempString[i] = ch;

		// Reallocate more size.
		if (i == sizeStr)
		{
			sizeStr += 10;
			tempString = (char*)realloc(tempString, sizeStr * sizeof(char*));
			FailedOneCharArr(tempString);
		}
		i++;
	} while (ch != '\n');
	// Mark the last input.
	tempString[i] = '\0';

	// Check if the student name is legal.
	tempName = CheckInput(':', tempString, &check, &j);

	/* Split the temp string to temp course and temp name and checks if
	the course name and grades are legal*/
	do
	{
		// Reallocate more size.
		tempCourseName = (char**)realloc(tempCourseName, (numOfcourses + 1) * 
			             sizeof(char**));
		FailedTwoCharArr(tempCourseName, numOfcourses + 1);
		
		// Check if the courses are legal.
		tempCourseName[numOfcourses] = CheckInput(',', tempString, &check, &j);
		
		// Reallocate more size.
		tempGrades = (char**)realloc(tempGrades, (numOfcourses + 1) * sizeof(char**));
		FailedTwoCharArr(tempGrades, numOfcourses + 1);
		// Check if the grades are legal.
		tempGrades[numOfcourses] = CheckInput(';', tempString, &check, &j);
		
		// Reallocate more size.
		grades = (int*)realloc(grades, (numOfcourses + 1) * sizeof(int*));
		FailedOneIntArr(grades);
		// Casting char array into int.
		grades[numOfcourses] = CharCasting(tempGrades[numOfcourses]);
		
		// Check if the grade is legal.
		if (grades[numOfcourses] > 100 || grades[numOfcourses] < 0)
		{
			check = 1;
		}
		numOfcourses++;
	} while (tempString[j + 1] != '\n');

	// Free temp string.
	free(tempString);
	// Free temp grades.
	FreeData(tempGrades, numOfcourses);

	// If the input is legal, insert or update student.
	if (check == 0)
	{
		// Finding if there is student and save his index.
		i = FindingStudent(pNumStudents, tempName, pStudentsNames);
		
		// If it's new student the function return -1.
		if (i != -1)
		{
			// Update the student.
			UpdateStudent(pCourseNames, numOfcourses, pnumOfgrades, pGrades,
				          tempCourseName, grades, i, tempName);

			// Free tempName.
			free(tempName);
			// Free grades.
			free(grades);
			// Free tempCourseName.
			free(tempCourseName);
		}
		else
		{
			// Reallocate more size.
			*pStudentsNames = (char**)realloc(*pStudentsNames, 
				              (*pNumStudents + 1) * sizeof(char**));
			FailedTwoCharArr(*pStudentsNames, *pNumStudents + 1);
			*pCourseNames = (char***)realloc(*pCourseNames, 
				            (*pNumStudents + 1) * sizeof(char***));
			FailedThreeCharArr(*pCourseNames, *pNumStudents + 1);
			*pGrades = (int**)realloc(*pGrades, 
				       (*pNumStudents + 1) * sizeof(int**));
			//FailedTwoIntArr(*pGrades, *pNumStudents + 1);
			*pnumOfgrades = (int*)realloc(*pnumOfgrades, 
				            (*pNumStudents + 1) * sizeof(int*));
			FailedOneIntArr(*pnumOfgrades);
			
			// Saving the new student.
			(*pStudentsNames)[*pNumStudents] = tempName;
			(*pCourseNames)[*pNumStudents] = tempCourseName;
			(*pGrades)[*pNumStudents] = grades;
			(*pnumOfgrades)[*pNumStudents] = numOfcourses;
			printf("Student ""\"%s\" added.\n", tempName);
			*pNumStudents += 1;
		}
		return;
	}

	// Input is illegal.
	else
	{
		printf("Error: invalid name or grade.\n");
		
		// Free tempName.
		free(tempName);
		// Free grades.
		free(grades);
		// Free tempCourseName.
		FreeData(tempCourseName, numOfcourses);
		return;
	}
}
/*****************************************************************************
* function name: CharCasting
* The Input: String array.
* The output: grade.
* The Function operation: The function recives grade by char array and do
* casting into grade by int.
* Note: I took this function from stackoverflow.
*****************************************************************************/
int CharCasting(char *buffer)
{
	int grade = 0, i;
	for (i = 0; buffer[i] != '\0'; ++i)
	{
		grade = grade * 10 + buffer[i] - '0';
	}
	return grade;
}

/*****************************************************************************
* function name: UpdateStudent
* The Input: Number of student, name of the student, name of the courses,
* grades and nummber of grades, index and temp string array.
* The output: None
* The Function operation: The function recives the index of the number of the
* student and update his courses and his grades.
* Note: In case there is new grades for exsiting courses the funcsion will
* update.
*****************************************************************************/
void UpdateStudent(char ****pCourseNames, int numOfcourses, int **pnumOfgrades,
	 int ***pGrades, char **tempCourseName, int *grades, int i, char *tempName)
{
	int l, j;

	// Go over tempCourseName.
	for (l = 0; l < numOfcourses; l++)
	{
		// Go over exsiting courses and update the grade.
		for (j = 0; j < (*pnumOfgrades)[i]; j++)
		{
			if (strcmp((*pCourseNames)[i][j], tempCourseName[l]) == 0)
			{
				(*pGrades)[i][j] = grades[l];
				free(tempCourseName[l]);
				break;
			}
		} //end of for j

		// Saving new courses and grades.
		if (j == (*pnumOfgrades)[i])
		{
			(*pCourseNames)[i] = (char**)realloc((*pCourseNames)[i], 
				                 ((*pnumOfgrades)[i] + 1) * sizeof(char**));
			FailedTwoCharArr((*pCourseNames)[i], (*pnumOfgrades)[i] + 1);
			(*pGrades)[i] = (int*)realloc((*pGrades)[i], 
				            ((*pnumOfgrades)[i] + 1) * sizeof(int*));
			FailedOneIntArr((*pGrades)[i]);
			(*pCourseNames)[i][j] = tempCourseName[l];
			(*pGrades)[i][j] = grades[l];
			(*pnumOfgrades)[i] += 1;
		}
	} //end of for l
	printf("Student ""\"%s\" updated.\n", tempName);
}

/*****************************************************************************
* function name: CheckInput
* The Input: A symbol, string array, flag check and index.
* The output: String array.
* The Function operation: The function recives string array, check if it
* is legal and split the temp array by symbol.
*****************************************************************************/
char* CheckInput(char symbol, char *st, int *check, int *i)
{
	int space = 0, size = 10, j = 0;
	char *buffer = NULL;
	buffer = (char*)malloc(size * sizeof(char*));
	FailedOneCharArr(buffer);

	// The loop stop with symbol or '/n'.
	do
	{
		// Ignoring the symbol.
		if ((st[*i] == ':') || (st[*i] == ',') || (st[*i] == ';'))
		{
			*i += 1;
			continue;
		}

		// Legal check for name or course.
		if (symbol == ':' || symbol == ',' || symbol == '\n')
		{
			// Student name and course must include characters and spaces only.
			if ((st[*i]<'A' || st[*i]>'Z') && 
				(st[*i]<'a' || st[*i]>'z') && (st[*i] != 32))
			{
				*check = 1;
			}
		}

		// Legal check for grade.
		if (symbol == ';')
		{
			// Grades must include numbers and spaces before the grade.
			if ((st[*i] < 48 || st[*i] > 57) && st[*i] != 32)
			{
				*check = 1;
			}

			// If there is spaces after one digit, its illegal.
			if ((space == 1) && (st[*i] == 32))
			{
				*check = 1;
			}
		}

		// Flag that check spaces.
		if (st[*i] != 32)
		{
			space = 1;
		}

		// Ignoring the Spaces before names, courses and grades. 
		if (space == 1)
		{
			buffer[j] = st[*i];
			j++;
		}

		// Reallocate more size.
		if (j == size)
		{
			size += 10;
			buffer = (char*)realloc(buffer, size * sizeof(char*));
			FailedOneCharArr(buffer);
		}
		*i += 1;

		// Empty names and courses its illegal.
		if ((st[*i] == symbol) && (space == 0))
		{
			*check = 1;
		}
	} while ((st[*i] != symbol) && (st[*i] != '\n'));

	//Mark the last input.
	buffer[j] = '\0';
	return buffer;
}


