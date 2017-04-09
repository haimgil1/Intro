
#include <math.h> 
#include <stdio.h>
/******************************************
* Haim Gil
* 203676945
* 8911003
* ex1
******************************************/
int main()
{
	int grade1, grade2, grade3;
	int inComputerScience = 0, objectProgramming = 0, algorithms = 0;
	double dataStructures = 0, linearAlgebra = 0, max = 0;
	char courseName1, courseName2, courseName3;
	printf("Please input three courses grades: \n");
	scanf("%d %c", &grade1, &courseName1);
	scanf("%d %c", &grade2, &courseName2);
	scanf("%d %c", &grade3, &courseName3);
	//this if checks wheather the user entered numbers between 0-100 
	if ((grade1>100 || grade1<0) || (grade2>100 || grade2<0) || (grade3>100 || grade3<0))
	{
		printf("Error\n");
		return 0;
	}
	// this if checks wheather the user entered two grades of the same course
	if ((courseName1 == courseName2) || (courseName1 == courseName3) || (courseName2 == courseName3))
	{
		printf("Error\n");
		return 0;
	}
	// this switch chekcs which course the user entered first and put his grade into max
	switch (courseName1)
{
	case 'I':
	{
		inComputerScience = grade1 + 2;
		if (inComputerScience > 100)
		{
			inComputerScience = 100;
		}
		max = inComputerScience;
		break;
	}

	case 'O':
	{
		objectProgramming = grade1 - 3;
		if (objectProgramming > 100)
		{
			objectProgramming = 100;
		}
		if (objectProgramming < 0)
		{
			objectProgramming = 0;
		}
		max = objectProgramming;
		break;
	}
	case 'A':
	{
		algorithms = grade1 + 8;
		if (algorithms > 100)
		{
			algorithms = 100;
		}
		max = algorithms;
		break;
	}
	case 'D':
	{
		dataStructures = grade1*1.06;
		if (dataStructures > 100)
		{
			dataStructures = 100;
		}
		max = dataStructures;
		break;
	}
	case 'L':
	{
		linearAlgebra = sqrt(grade1) * 10;
		if (linearAlgebra > 100)
		{
			linearAlgebra = 100;
		}
		max = linearAlgebra;
		break;
	}
	default:
	{
		printf("Error\n");
		return 0;
	}
}
	//this switch checks which course the user entered second 
	switch (courseName2)
	{
	    case 'I':
	   {
			inComputerScience = grade2 + 2;
			if (inComputerScience > 100)
			{
				inComputerScience = 100;
			}
			if (inComputerScience > max)
			{
				max = inComputerScience;
			}
			break;
		}
		case 'O':
		{
			objectProgramming = grade2 - 3;
			if (objectProgramming > 100)
			{
				objectProgramming = 100;
			}
			if (objectProgramming < 0)
			{
				objectProgramming = 0;
			}
			if (objectProgramming > max)
			{
				max = objectProgramming;
			}
			break;
		}
		case 'A':
		{
			algorithms = grade2 + 8;
			if (algorithms > 100)
			{
				algorithms = 100;
			}
			if (algorithms > max)
			{
				max = algorithms;
			}
			break;
		}
		case 'D':
		{
			dataStructures = grade2*1.06;
			if (dataStructures > 100)
			{
				dataStructures = 100;
			}
			if (dataStructures > max)
			{
				max = dataStructures;
			}
			break;
		}
		case 'L':
		{
			linearAlgebra = sqrt(grade2) * 10;
			if (linearAlgebra > 100)
			{
				linearAlgebra = 100;
			}
			if (linearAlgebra > max)
			{
				max = linearAlgebra;
			}
			break;
		}
		default:
		{
			printf("Error\n");
			return 0;
		}
	}
     //this switch checks which course the user entered third 
      switch (courseName3)
	{
	     case 'I':
	    {
			inComputerScience = grade3 + 2;
			if (inComputerScience > 100)
			{
				inComputerScience = 100;
			}
			if (inComputerScience > max)
			{
				max = inComputerScience;
			}
			break;
		}
		 case 'O':
		 {
			objectProgramming = grade3 - 3;
			if (objectProgramming > 100)
			{
				objectProgramming = 100;
			}
			if (objectProgramming < 0)
			{
				objectProgramming = 0;
			}
			if (objectProgramming > max)
			{
				max = objectProgramming;
			}
			break;
		}
		 case 'A':
		 {
			algorithms = grade3 + 8;
			if (algorithms > 100)
			{
				algorithms = 100;
			}
			if (algorithms > max)
			{
				max = algorithms;
			}
			break;
		}
		 case 'D':
		 {
			dataStructures = grade3*1.06;
			if (dataStructures > 100)
			{
				dataStructures = 100;
			}
			if (dataStructures > max)
			{
				max = dataStructures;
			}
			break;
		}
		 case 'L':
		 {
			linearAlgebra = sqrt(grade3) * 10;
			if (linearAlgebra > 100)
			{
				linearAlgebra = 100;
			}
			if (linearAlgebra > max)
			{
				max = linearAlgebra;
			}
			break;
		}
		 default:
		{
			printf("Error\n");
			return 0;
		}
	}
	  //this if checks wheather the course equal to max and print it
    if (inComputerScience == max)
	{
		printf("Your max grade is %.2f \n", max);
		printf("You received this grade in Introduction to computer science ");
	}
	else if (objectProgramming == max)
	{
		printf("Your max grade is %.2f \n", max);
		printf("You received this grade in Object oriented programming ");
	}
	else if (algorithms == max)
	{
		printf("Your max grade is %.2f \n", max);
		printf("You received this grade in Algorithms  ");
	}
	else if (dataStructures == max)
	{
		printf("Your max grade is %.2f \n", max);
		printf("You received this grade in Data Structures ");
	}
	else
	{
		printf("Your max grade is %.2f \n", max);
		printf("You received this grade in Linear algebra  ");
	}
	
	return 0;
}
