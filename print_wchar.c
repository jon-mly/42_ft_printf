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

char     *print_wchar(va_list args, t_format *format)
{
    char    *printable;
    char    *converted_wchar;

    format->type->wc = va_arg(args, wchar_t);
    converted_wchar = get_converted_wchar(format->type->wc);
    if (width <= 1)
        return (converted_wchar);
    printable = ft_strnew(width - ft_strlen(converted_wchar));
    if (format->minus_flag)
    {
        ft_memset(printable + ft_strlen(converted_wchar),
            width - ft_strlen(converted_wchar), ' ');
        printable = fill_printable(converted_wchar, printable, 0);
    }
    else
    {
        ft_memset(printable, width - ft_strlen(converted_wchar), ' ');
        printable = fill_printable(converted_wchar, printable,
            width - ft_strlen(converted_wchar));
    }
    return (printable);
}
