#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct print_character - structure for get_func
 * @specifier: the specifier of %
 * @f: the function associated
 */

typedef struct print_character
{
	const char *specifier ;
	int (*f)(va_list) ;
} flag_fn;

int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
int print_char(va_list all);
int print_string(va_list all);
int (*get_func(const char *format))(va_list);

#endif /* MAIN_H */
