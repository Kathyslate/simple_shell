#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'a program that accepts two integers and sum them up'
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int integer1, integer2, sum;

	printf("Enter two integers to be added: ");
	scanf("%d %d", &integer1, &integer2);

	sum = integer1 + integer2;

	printf("%d + %d = %d", integer1, integer2, sum);
	return (0);
}
