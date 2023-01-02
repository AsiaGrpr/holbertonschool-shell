#include "main.h"
#include <unistd.h>

/**
 * _strlen - function to know the length of a string
 * @s: pointer to string to mesure
 *
 * Return: Length value
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_char - function that stdout a char
 * @all: va_list used as input
 *
 * Return: length value
*/
int print_char(va_list all)
{
	int c = va_arg(all, int);

	return (write(1, &c, 1));
}

/**
 * print_string -  function that stdout a string
 * @all: va_list used as input
 *
 * Return: length value
*/
int print_string(va_list all)
{
	char *s = va_arg(all, char *);

	s == NULL ? s = "(null)" : s;
	return (write(1, s, _strlen(s)));
}

/**
 * print_int - function that prints integer
 * @all: va_list used as input
 *
 * Return: number of characters printed
 */
int print_int(va_list all)
{
	int i;
	int c = 0;
	int n = va_arg(all, int);

	if (n < 0)
	{
		c += _putchar('-');
	}
	for (i = 1000000000; i > 0; i /= 10)
	{
		if (n / i)
		{
			if ((n / i) % 10 < 0)
				c += _putchar(-(n / i % 10) + '0');
			else
				c += _putchar((n / i % 10) + '0');
		}
		else if (n / i == 0 && i == 1)
		{
			c += _putchar(n / i % 10 + '0');
		}
	}
	return (c);
}