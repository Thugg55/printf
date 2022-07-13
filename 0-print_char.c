#include "main.h"
#include <unistd.h>
#include <stdlib.h>


/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 *
 * Return: on Success 1
 * On Error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints character
 * @list: list of arguments
 * Return: Number of characters printed.
 */

int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_str - Prints a string
 * @list: list of arguments
 * Return: Number of characters printed.
 */

int print_str(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Number of characters printed.
 */

int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}


/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
