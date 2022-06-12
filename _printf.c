#include "main.h"
/**
 * printIdentifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the indentifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int printidentifier(char next, va_list arg)
{
	int functsIndex;

	handler functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].identifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].identifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}

/**
 *main - prints its number of arguments, followed by a new line.
 *@char: number of arguments in the command line
 *
 *Return: Returns 0
 *
 */
int _printf(char *format, ...)
{
	unsigned int i;
	int identifier, count = 0;

	va_list arg;

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if( format[i] != '%')
		{
			_write(format[i]);
			count++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_write('%');
			count++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
		{
			return (-1);
		}

		identifier = printidentifier(format[i + 1], arg);
		if (identifier == -1 || identifier !=0)
		{
			i++;
		}
		if (identifier > 0)
		{
			count += identifier;
		}
		if (identifier == 0)
		{
			_write('%');
			count++;
		}

	}
	va_end(arg);
	return (count);
}
