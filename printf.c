#include "main.h"

/**
*_print - print string as printf
*@format: number of arguments
*Return: number of charter
**/

int _printf(const char *format, ...)
{
	va_list p;
	unsigned int i, result;
	result = 0;
	va_start(p, format);

	for (i = 0; format != '\0'; i++)
	{
		if (format[i] == '%')
		{
			result +=
		}
	}
}