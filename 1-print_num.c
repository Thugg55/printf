#include "main.h"
#include <stdlib.h>

/**
 * print_int - Prints an integer
 * @list: list of arguments
 * Return: Number of characters printed.
 */

int print_int(va_list list)
{
	int len;

	len = print_num(list);
	return (len);
}


/**
 * print_unsigned - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */

int print_unsigned(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (unsigned_int(num));

	if (num < 1)
		return (-1);
	return (unsigned_int(num));
}


/* Helper functions */

/**
 * print_num - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */

int print_num(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * unsigned_int - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */

int unsigned_int(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
