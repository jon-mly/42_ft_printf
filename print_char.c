#include "ft_printf.h"

char     *print_char(va_list args, t_format *format)
{
    char    *printable;

    if (format->l_flag)
        return (print_wchar(args, format))
    format->type->c = va_arg(args, char);
    if (width <= 1)
    {
        printable = ft_strnew(1);
        printable[0] = c;
        return (printable);format->type.c
    }
    printable = ft_strnew(width);
    if (format->minus_flag)
    {
        ft_memset(printable + 1, width - 1, ' ');
        printable[0] = c;
    }
    else
    {
        ft_memset(printable, width - 1, ' ');
        printable[width - 1] = c;
    }
    return (printable);
}
