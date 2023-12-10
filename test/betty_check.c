#include <stdio.h>
#include <stdlib.h>

/**
 * main - code to pass betty check
 *
 * Return: sum of two numbers
 */

int main (int ac, **char argv[])
{
	int counter, sum;

	if ( ac < 2)
	{
		printf("Incomplete parameters");
		return (-1);
	}

	while (ac > 2)
	{
		sum += argv[counter];
		counter++;
	}

	printf("The sum of the numbers is %d\n", sum);
	return (0);
}
