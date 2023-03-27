#include "main.h"
#include <stdio.h>
/**
* print_precision - prints precision of non custom specifiers
* @format: number of arguments
* Return: precision
*/
int print_precision(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
						break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
