#include "ft_printf.h"

static int      wstrlen(wchar_t *wstring)
{
    int     i;

    i = 0;
    while (wstring[i])
        i++;
    return (i);
}

static char     *wstrconvert(wchar_t *wstring)
{
    int     i;
    char    *converted_str;
    char    *str_tmp;
    char    *wchar_tmp;

    i = -1;
    converted_str = ft_strnew(0);
    while (wstring[++i])
    {
        wchar_tmp = get_converted_wchar(wstring[i]);
        str_tmp = converted_str;
        converted_str = ft_strjoin(str_tmp, wchar_tmp);
        ft_strdel(&wchar_tmp);
        ft_strdel(&str_tmp);
    }
    return (converted_str);
}

char            *print_wstring(va_list args, t_format *format)
{
    char    *printable;
    char    *spaces;

    format->type.wstr = va_arg(args, wchar_t*);
    if (wstrlen(format->type.wstr) >= format->width)
        return (wstrconvert(format->type.wstr));
    spaces = ft_strnew(format->width - wstrlen(format->type.wstr));
    ft_memset(spaces, format->width - wstrlen(format->type.wstr), ' ');
    if (format->minus_flag)
        printable = ft_strjoin(wstrconvert(format->type.wstr), spaces);
    else
        printable = ft_strjoin(spaces, wstrconvert(format->type.wstr));
    ft_strdel(&spaces);
    return (printable);
}
