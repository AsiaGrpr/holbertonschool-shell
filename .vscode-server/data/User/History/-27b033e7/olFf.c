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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - function that stdout a char
 * @all: va_list used as input
 * 
 * Return: NULL value
*/
void print_char(va_list all)
{
  int c = va_arg(all, int);
  write(1, &c, 1);
}

/**
 * print_string -  function that stdout a string
 * @all: va_list used as input
 * 
 * Return: NULL value
*/
void print_string(va_list all)
{
  char *s = va_arg(all, char *);
  write(1, s, _strlen(s));
}