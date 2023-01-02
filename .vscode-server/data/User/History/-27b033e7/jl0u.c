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
 * print_integer - function that prints integer
 * @all: va_list used as input
 *
 * Return: number of characters printed
 */
