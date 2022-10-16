#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - output value to stdio
 * @format: param
 * Return: int
 */


int _printf(const char *format, ...)
{
	int len = 0;
	f_id func_list[] = {/*pairing the format id to a handling function*/
		{"c", _print_char},
		{"s", _putstr},
		{"%", _print_percent},
		{"d", _print_int},
		{"i", _print_int},
		{"r", _print_reversed},
		{"b", _print_binary},
		{"R", rot13},
		{"u", unsigned_int},
		{"o", _print_octal},
		{"x", _print_hex},
		{"X", _print_heX},
		{NULL, NULL}
	};
	va_list args;

	if (!format)
		return (-1); /*false value used to check if format is empty*/

	va_start(args, format);
	len = _identifier(format, func_list, args);
	va_end(args);
	return (len);
}


/**
 * _identifier - marches id to functions
 * @format: param
 * @func_list: param
 * @args: param
 * Return: int
 */

int _identifier(const char *format, f_id func_list[], va_list args)
{
	int i, j, k, len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/*if %, we loop through the stuct list above*/
			for (j = 0; func_list[j].id != NULL; j++)
			{
				if (format[i + 1] == func_list[j].id[0])
				{
					k = func_list[j].func(args);
					if (k == -1)
						return (-1);
					len += k;
					break;
				}
			}
			if (func_list[j].id == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					len += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	return (len);
}
