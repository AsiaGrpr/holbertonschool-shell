#include "main.h"
#include <stdlib.h>

/**
 * get_func - checks format specifier
 * @format: format specifier
 * Return: pointer to function
 */

int (*get_func(const char *format))(va_list)
{
	flag_fn func[] = {
		{"c", print_char},
		{"s", print_string},
		{0, NULL}
	};

	int n = 0;

	while (func[n].specifier != 0)
	{
		if (func[n].specifier == format)
			return (func[n].f);
		n++;
	}
	return (n);
}

/**
 * _printf - prints anything
 * @format: list of arguments
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list all;
	int i = 0;
	int counter = 0;
	int (*f)(va_list);

	if (format[i] == NULL)
		return (0);

	va_start(all, format);

	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			f = get_func(format[i + 1]);
			counter += f(all);
			i++;
		}
		else
		{
			_putchar(format[i]);
			counter++;
		}
		i++;
	}

	va_end(all);
	return (counter);
}
