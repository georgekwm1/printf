#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - prints
 *
 *
 * @bin_num: holds the integer to be converted to binary
 * @mod:holds the modulus of the integer to be converted
 * @mod_sto: array holding modulus of integer
 * @inv_bin: inverts the outputted binary numbers
 * @format: primary argument of function that holds string type
 * @i: integer used for increment
 * @j: integer used for increment
 *
 * Return: Always 0 (Success)
 */
int _printf(const char *format, ...)
{

int num, j, i = 0;
unsigned int bin_num, mod, mod_sto[5], inv_bin[5];

va_list str_list;
va_start(str_list, format);

if (*format)
{
if (*format == '%')
{
(format++);
switch (*format)
{
case 'b':
bin_num = va_arg(str_list, int);
j = (sizeof(mod_sto) / 4) - 1;

while (bin_num)
{

if (bin_num > 0)
mod = bin_num % 2;
i++;
bin_num /= 2;
{
mod_sto[i] = mod;

inv_bin[j] = mod_sto[i];
printf("%d", inv_bin[j]);
j--;
}

}
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
return (0);
}
