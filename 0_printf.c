#include "main.h"

/**
 * main - 0_printf function
 * description: To print s, c, %
 * return: %d
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	for (const char *ptr = format; *ptr; ++ptr)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			count++;
			continue;
		}

		ptr++;
		switch (*ptr)
				{
				case 'c':
					{
						char c = (char) va_arg(args, int);
						putchar(c);
						count++;
						break;
					}

				case 's':
					{
						const char *s = va_arg(args, const char *);
						for (const char *p = s; *p; ++p)
						{
							putchar(*p);
							count++;
						}
						break;
					}

				case '%':
					{
						putchar('%');
						count++;
						break;
					}

				default:
					{
						break;
					}
				}
	}
	va_end(args);
	return count;
}
