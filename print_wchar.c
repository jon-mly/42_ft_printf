#include "ft_printf.h"

char    *fill_printable(char *converted_wchar, char *printable, int index)
{
    int     size;
    int     i;

    size = ft_strlen(converted_wchar);
    i = -1;
    while (++i < size)
        printable[index + i] = converted_wchar[i];
    return (printable);
}

static int     ft_pop_wchar(char *str)
{
    if (*str)
        return (ft_pop(str));
    ft_putchar(0);
    return (1);
}

int     print_wchar(va_list args, t_format *format)
{
    char    *spaces;
    char    *converted_wchar;

    format->type.wc = va_arg(args, wchar_t);
    converted_wchar = get_converted_wchar(format->type.wc);
    if (format->width <= 1)
        return (ft_pop_wchar(converted_wchar));
    spaces = ft_strnew(format->width - ft_strlen(converted_wchar));
    ft_memset(spaces, ' ', format->width - ft_strlen(converted_wchar));
    if (format->minus_flag)
        return (ft_pop_wchar(converted_wchar) + ft_pop(spaces));
    else
        return (ft_pop(spaces) + ft_pop_wchar(converted_wchar));
}
