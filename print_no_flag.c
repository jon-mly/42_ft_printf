#include "ft_printf.h"

int     print_no_flag(char c, t_format *format)
{
    char    *printable;

    format->type.c = c;
    if (format->width <= 1)
    {
        printable = ft_strnew(1);
        printable[0] = format->type.c;
        return (ft_pop(printable));
    }
    printable = ft_strnew(format->width);
    if (format->minus_flag)
    {
        ft_memset(printable + 1, ' ', format->width - 1);
        printable[0] = format->type.c;
    }
    else
    {
        ft_memset(printable, (format->zero_flag) ? '0' : ' ', format->width - 1);
        printable[format->width - 1] = format->type.c;
    }
    return (ft_pop(printable));
}
