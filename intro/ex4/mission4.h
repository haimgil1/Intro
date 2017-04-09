/******************************************
* Haim Gil
* 203676945
* 8911003
* ex4
******************************************/
#ifndef MISSION4
#define MISSION4
void PrintsAllstud(int *pNumStudents, char ***pStudentsNames, 
	              char ****pCourseNames, int ***pGrades, int **pnumOfgrades);
void Sorting(char ***pStudentsNames, int *pNumStudents, 
	        char ****pCourseNames, int ***pGrades, int **pnumOfgrades);
void AvgAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades);
void MaxAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades);
void MinAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades);
void SumAll(int* pNumStudents, char*** pStudentsNames, int*** pGrades,
	       int** pnumOfgrades);
void NumOfCoursesAll(int* pNumStudents, char*** pStudentsNames,
	                int*** pGrades, int** pnumOfgrades);
#endif