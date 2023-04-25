#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


/**
 * _printf - prints
 *
 * 
 * @str: describe the parameter
 * @bin_num: holds the integer to be converted to binary
 * @mod:holds the modulus of the integer to be converted
 * @mod_sto: array holding modulus of integer
 * @inv_bin: inverts the outputted binary numbers
 * @charac: holds the character argument
 * @format: primary argument of function that holds string type
 * 
 * Return: Always 0 (Success)
 */





int _printf(const char *format, ...)
{

int num,j , i = 0;
unsigned int bin_num, mod, mod_sto[5], inv_bin[5];
char *str, *charac;
va_list str_list;

va_start(str_list, format);
if (*format)
{
if (*format == '%'){
(format++);
switch (*format)
{
case 'd':
num = va_arg(str_list, int);
i++;
printf("%d", num);
break;

case 'i':
num = va_arg(str_list, int);
i++;
printf("%i", num);
break;
case 'b':
bin_num = va_arg(str_list, int);
j = (sizeof(mod_sto) / 4) - 1;

while (bin_num){

if (bin_num > 0)
mod = bin_num % 2;
i++;
bin_num /= 2;
{
mod_sto[i]= mod;


inv_bin[j] = mod_sto[i];
 printf("%d", inv_bin[j]);
 j--;

}

}
break;

case 's':
 str = va_arg(str_list, char*);

printf("%s", str);
break;

case 'r':
str = va_arg(str_list, char*);
len = strlen(str);
j = len -1;
while(j >= 0){
printf("%c", str[j]);
j--;
}

break;

case 'c':
charac = va_arg(str_list, int);

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
return (0);
}
