#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * main - arrays
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	printf("Enter the first integer: ");
	scanf("%d", &num1);
	printf("Enter the second integer: ");
	scanf("%d", &num2);

	int sum = num1 + num2;

	printf("The sum of %d and %d is %d.\n", num1, num2, sum);

	return (0);
}
