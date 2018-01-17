#include "ft_printf.h"

char    *get_required_spaces(t_format *format, int len)
{
    char    *spaces;

    len = format->width - ft_strlen(format->type.str);
    spaces = ft_strnew(len);
    if (format->zero_flag && !(format->minus_flag))
        ft_memset(spaces, '0', len);
    else
        ft_memset(spaces, ' ', len);
    return (spaces);
}

static char    *precision_string(va_list args, t_format *format)
{
    char    *tmp;
    char    *printable;

    tmp = va_arg(args, char*);
    if (tmp == NULL)
        tmp = "(null)";
    if (format->precision < 0 || (int)ft_strlen(tmp) <= format->precision)
        return (ft_strdup(tmp));
    printable = ft_strnew(format->precision);
    ft_strncpy(printable, tmp, format->precision);
    return (printable);
}


char    *print_string(va_list args, t_format *format)
{
    char    *printable;
    char    *spaces;

    if (format->l_flag)
        return (print_wstring(args, format));
    format->type.str = precision_string(args, format);
    if ((int)ft_strlen(format->type.str) >= format->width)
        return (format->type.str);
    spaces = get_required_spaces(format, format->width -
        ft_strlen(format->type.str));
    if (format->minus_flag)
        printable = ft_strjoin(format->type.str, spaces);
    else
        printable = ft_strjoin(spaces, format->type.str);
    ft_strdel(&spaces);
    return (printable);
}
