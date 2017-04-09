/******************************************
* Haim Gil
* 203676945
* 8911003
* ex4
******************************************/
#ifndef INSERT_STUDENT
#define INSERT_STUDENT
void InsertStudent(int *pNumStudents, char ***pStudentsNames, 
	              char ****pCourseNames, int ***pGrades, int **numOfgrades);
char* CheckInput(char symbol, char *tempString, int *check, int *i);
int CharCasting(char *buffer);
void UpdateStudent(char ****pCourseNames, int numOfcourses, int **pnumOfgrades,
	              int ***pGrades, char **tempCourseName, int *grades,
	              int i, char *tempName);
#endif