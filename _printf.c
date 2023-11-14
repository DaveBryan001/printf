#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			if (*(format + 1) == 'c')
			{
				putchar(va_arg(args, int));
				count++;
			} else if (*(format + 1) == 's')
			{
				count += printf("%s", va_arg(args, char *));
			} else if (*(format + 1) == '%')
			{
				putchar('%');
				count++;
			} else
			{
				putchar('%');
				count++;
			}
			format += 2;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}

	va_end(args);
	return (count);
}

