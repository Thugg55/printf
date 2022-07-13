#ifndef GUARD_H
#define GUARD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/**
 * struct convert - define a structure for symbols and their functions
 * @sym: format specifier
 * @f: associated function
 */

struct convert
{
	char *sym;
	int  (*f)(va_list);
};
typedef struct convert conver_t;


/* Main Functions */
int _printf(const char *format, ...);
int parser(const char *format, conver_t func_list[], va_list args);
int _putchar(char);
int print_char(va_list);
int print_str(va_list);
int print_int(va_list);
int print_percent(va_list);
int print_unsigned(va_list);
int print_binary(va_list);
int print_octal(va_list);
int print_hex(va_list);
int print_hex_caps(va_list);
int print_rev_str(va_list);
int print_rot13(va_list);
int print_pointer(va_list);
int print_ascii(va_list);

/* Helper Functions */
int unsigned_int(unsigned int);
int print_num(va_list);
int hex_check(int, char);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int hex_print(char c);
char *convert(unsigned long int num, int base, int lowercase);
int _puts(char *str);



#endif
