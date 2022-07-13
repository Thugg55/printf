#include "main.h"
#include <stdlib.h>


/**
 * print_rev_str - Reverse and print a string
 * @list: Arguments passed to the function
 * Return: Number of characters printed
 */

int print_rev_str(va_list list)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}



/**
 * print_rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */

int print_rot13(va_list list)
{
	int i;
	int j;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (str[i] == s[j])
			{
				_putchar(u[j]);
				break;
			}
		}
		if (j == 53)
			_putchar(str[i]);
	}
	return (i);
}
