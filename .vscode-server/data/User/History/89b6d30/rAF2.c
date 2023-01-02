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
		{"%", print_percent},
		{0, NULL}
	};

	int n = 0;

	while (func[n].specifier != 0)
	{
		if (*func[n].specifier == *format)
			return (func[n].f);
		n++;
	}
	return (0);
}

/**
 * _printf - prints anything
 * @format: list of arguments
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list all;
	int i = 0, counter = 0, (*f)(va_list);

	va_start(all, format);

	if (format == NULL)
		return (-1);

	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			f = get_func(&format[i + 1]);

			if (f)
			{
				counter += f(all);
				i++;
			}
			else
			{
			_putchar('%');
			counter++;
			}
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
