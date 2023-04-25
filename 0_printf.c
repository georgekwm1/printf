#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - prints
 *
 *
 * @str: describe the parameter
 * @format: primary argument of function that holds string type
 *
 * Return: Always 0 (Success)
 */
int _printf(const char *format, ...)
{

char *str, *charac;

va_list str_list;

va_start(str_list, format);
if (*format)
{
if (*format == '%'){
(format++);
switch (*format)
{

case 's':
str = va_arg(str_list, char*);
printf("%s", str);
break;

case 'c':
charac = va_arg(str_list, int);
 //i++;
printf("%c", charac);
break;

case '%':
str = va_arg(str_list, char*);
printf("%%");
break;
}
}
else
{
putchar(*format);
i++;
}
format++;
}
va_end(str_list);
return 0;
}
