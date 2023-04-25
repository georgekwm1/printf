#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: ...
 * @buffer: ...
 * @flags:  ...
 * @width: get width
 * @precision: Specification
 * @size: Size
 * Return: ...
 */
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int x = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = (num % 10) + '0';
                num /= 10;
        }

                x++;

                return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: Precision
 * @size: Size
 * Return: ...
 */
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{

        int x = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = (num % 8) + '0';
                num /= 8;
        }

        if (flags & F_HASH && init_num != 0)
                buffer[x--] = '0';

        x++;

        return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: ...
 */
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return (print_hexa(types, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal
 * @types: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: ...
 */
int print_hexa_upper(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return (print_hexa(types, "0123456789ABCDEF", buffer,
                flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: ...
 * @map_to: ...
 * @buffer: ...
 * @flags:  ...
 * @flag_ch: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * @size: ...
 * Return: ...
 */
int print_hexa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size)
{
        int x = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = map_to[num % 16];
                num /= 16;
        }

        if (flags & F_HASH && init_num != 0)
        {
                buffer[x--] = flag_ch;
                buffer[x--] = '0';
        }

                x++;

                return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
