#include "ft_printf.h"

char     *print_char(va_list args, t_format *format)
{
    char    *printable;

    if (format->l_flag)
        return (print_wchar(args, format));
    format->type.c = (char)va_arg(args, int);
    if (format->width <= 1)
    {
        printable = ft_strnew(1);
        printable[0] = format->type.c;
        return (printable);
    }
    printable = ft_strnew(format->width);
    if (format->minus_flag)
    {
        ft_memset(printable + 1, format->width - 1, ' ');
        printable[0] = format->type.c;
    }
    else
    {
        ft_memset(printable, format->width - 1, ' ');
        printable[format->width - 1] = format->type.c;
    }
    return (printable);
}
