#include "ft_printf.h"

char    load_char(va_list args)
{
    char    c;

    c = (char)va_arg(args, int);
    if (c == 0)
    {
        ft_putchar('^');
        return ('@');
    }
    return (c);
}

char     *print_char(va_list args, t_format *format)
{
    char    *printable;

    if (format->l_flag)
        return (print_wchar(args, format));
    format->type.c = load_char(args);
    if (format->width <= 1)
    {
        printable = ft_strnew(1);
        printable[0] = format->type.c;
        return (printable);
    }
    printable = ft_strnew(format->width);
    if (format->minus_flag)
    {
        ft_memset(printable + 1, ' ', format->width - 1);
        printable[0] = format->type.c;
    }
    else
    {
        ft_memset(printable, ' ', format->width - 1);
        printable[format->width - 1] = format->type.c;
    }
    return (printable);
}
