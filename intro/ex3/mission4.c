/******************************************
* Haim Gil
* 203676945
* 8911003
* ex3
******************************************/
#include <stdio.h>
#include "mission4.h"
/************************************************************************
* function name: SimpleCalculator
* The Input:none
* The output:none
* The Function operation: The function recives from the user equation
* and calculate it.
* Note: In case the equation is only 0/0 the function will print 0/1.
* Note: The equation ends with 0/0.
*************************************************************************/
void SimpleCalculator()
{
	int numerator, denominator, gcd;
	int result1 = 0, result2 = 0;
	char fraction, operator = '^';
	printf("Please enter your equation:\n");

	do
	{
	// Scaning the fraction.
	scanf("%d", &numerator);
	scanf("%c", &fraction);
	scanf("%d", &denominator);
	// The equation ends with 0/0. 
	if (denominator == 0)
	{
    	break;
	}
	 switch (operator)
	 {
		case '+':
		{
			// If the fractions have the same denominator.
			if (result2 == denominator)
			{
				result1 = result1 + numerator;
			}
			// Common denominator.
			else
			{
				result1 = (result1*denominator) + (result2*numerator);
				result2 = result2*denominator;
			}
			break;
		}
		case '-':
		{
			// If the fractions have the same denominator.
			if (result2 == denominator)
			{
				result1 = result1 - numerator;
			}
			// Common denominator.
			else
			{
				result1 = (result1*denominator) - (result2*numerator);
				result2 = result2*denominator;
			}
			break;
		}
		case '/':
		{
			// Multiplication inverse 
			result1 = result1*denominator;
			result2 = result2*numerator;
			break;
		}
		case '*':
		{
			// Multiplication
			result1 = result1*numerator;
			result2 = result2*denominator;
			break;
		}
		default:
		{
	   		// saving the first fraction
			result1 = numerator;
			result2 = denominator;
			break;
		}
   } // End of switch.

	// Scaning the operator.
	scanf("%c", &operator);
	} while (denominator != 0);

		if (result1 == 0)
		{
			result2 = 1;
		}

		// Reducing the fraction.
		gcd = Gcd(result1, result2);
		result1 = result1 / gcd;
		result2 = result2 / gcd;
		printf("Result %d%c%d.\n\n", result1, fraction, result2);
	}

/************************************************************************
* function name: Gcd
* The Input: Numerator and denominator
* The output: Great common divisor
* The Function operation: The function recives Numerator and denominator
* and find the great common divisor. I used Euclidean algorithm idea in
* this function.
*************************************************************************/
int Gcd(int result1, int result2)
{
	int gcd;

	// Finding the great common divisor.
	while (result1 != 0)
	{
		gcd = result2 % result1;
		result2 = result1;
		result1 = gcd;
	}
	// Returning the great common divisor.
	return result2;
}



