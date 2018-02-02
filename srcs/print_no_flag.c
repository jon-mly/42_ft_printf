#include "ft_printf.h"

int     print_no_flag(t_format *format, char c)
{
    char    *spaces;

    format->type.c = c;
    if (format->width <= 1)
        return (ft_pop_char(format->type.c));
    spaces = ft_strnew(format->width - 1);
    ft_memset(spaces, format->zero_flag ? '0' : ' ', format->width - 1);
    if (format->minus_flag)
        return (ft_pop_char(format->type.c) + ft_pop(spaces));
    else
        return (ft_pop(spaces) + ft_pop_char(format->type.c));
}
