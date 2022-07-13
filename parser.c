#include "main.h"
#include <stdlib.h>

/**
 * parser - Takes the format string and prints regular content of the
 * string and calls appropriate helper functions for format specifier.
 * @format: Formatted input string
 * @func_list: Struct for all the functions
 * @args: A list containing all the arguments passed to the function
 * Return: Number of characters printed
 */

int parser(const char *format, conver_t func_list[], va_list args)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++)/* Iterates through the main string */
	{
		if (format[i] == '%') /* Check for format specifiers */
		{
			/* Iterate through struct to find the right function */
			for (j = 0; func_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == func_list[j].sym[0])
				{
					r_val = func_list[j].f(args);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (func_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /*Update i to skip format symbols*/
		}
		else
		{
			_putchar(format[i]); /*call the putchar function*/
			printed_chars++;
		}
	}
	return (printed_chars);
}
