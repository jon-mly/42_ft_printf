#include "ft_printf.h"

char    *print_percent(t_format *format)
{
    char    *printable;
    char    *spaces;

    format->type.str = "%";
    if ((int)ft_strlen(format->type.str) >= format->width)
        return (format->type.str);
    spaces = ft_strnew(format->width - ft_strlen(format->type.str));
    ft_memset(spaces, ' ', format->width - ft_strlen(format->type.str));
    if (format->minus_flag)
        printable = ft_strjoin(format->type.str, spaces);
    else
        printable = ft_strjoin(spaces, format->type.str);
    ft_strdel(&spaces);
    return (printable);
}
