#include "ft_printf.h"

char    *print_string(va_list args, t_format *format)
{
    char    *printable;
    char    *spaces;

    if (format->l_flag)
        return (print_wstring(args, format));
    format->type.str = va_arg(args, char*);
    if (ft_strlen(format->type.str) >= format->width)
        return (format->type.str);
    spaces = ft_strnew(format->width - ft_strlen(format->type.str));
    ft_memset(spaces, format->width - ft_strlen(format->type.str), ' ');
    if (format->minus_flag)
        printable = ft_strjoin(format->type.str, spaces);
    else
        printable = ft_strjoin(spaces, format->type.str);
    ft_strdel(&spaces);
    return (printable);
}
