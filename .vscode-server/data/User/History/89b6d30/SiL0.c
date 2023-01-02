#include "main.h"
#include <stdlib.h>
/**
 * get_func - Checks format specifier
 * Description: This is a longer description.
 * @format: format specifier
 * Return: pointer to function
 **/
int (*get_func(const char *format))(va_list)
{
	flag_fn func[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int}
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
 *
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	va_list all;
	int i = 0, counter = 0, (*f)(va_list);

	va_start(all, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				counter += _putchar(format[i]);
				i++;
			}
			else
			{
				f = get_func(&format[i + 1]);
				if (f)
				{
					counter += f(all);
					i++;
				}
				else
					counter += _putchar(format[i]);
			}
		}
		else
			counter += _putchar(format[i]);
		i++;
	}
	va_end(all);
	return (counter);
}
