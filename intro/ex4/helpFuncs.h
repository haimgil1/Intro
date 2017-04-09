/******************************************
* Haim Gil
* 203676945
* 8911003
* ex4
******************************************/
#ifndef HELP_FUNCS
#define HELP_FUNCS
void ShortMenu();
void PrintMenu();
void PrintAggregation();
int FindingStudent(int *pNumStudents, char *tempName, char ***pStudentsNames);
void FreeData(char** names, int size);
void CleanExit(int NumStudents, char **StudentsNames, char ***CourseNames,
	          int **Grades, int *numOfgrades);
void FailedThreeCharArr(char*** names, int size);
void FailedOneCharArr(char* names);
void FailedOneIntArr(int* names);
void FailedTwoCharArr(char** names, int size);
void FailedTwoIntArr(int** names, int size);
#endif