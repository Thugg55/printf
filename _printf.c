#include "main.h"
#include <stdlib.h>

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int characters_printed;
	conver_t func_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"r", print_rev_str},
		{"R", print_rot13},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex_caps},
		{"S", print_ascii},
		{"p", print_pointer},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	characters_printed = parser(format, func_list, args);
	va_end(args);
	return (characters_printed);
}
