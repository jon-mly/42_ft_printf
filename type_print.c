#include "ft_printf.h"

void    set_format_unsigned(t_format *format, char type)
{
    if (type == 'o')
        format->o_type = 1;
    else if (type == 'u')
        format->u_type = 1;
    else if (type == 'x')
        format->x_type = 1;
    else if (type == 'X')
        format->X_type = 1;
}

char    *type_print(va_list args, t_format *format, const char *str, int i)
{
    if (!(ft_char_search(str + i, "sSdDioOuUxXpcC")))
        return (NULL);
    if (ft_char_search(str + i, "s"))
        return (print_string(args, format));
    if (ft_char_search(str + i, "S"))
        return (print_wstring(args, format));
    if (ft_char_search(str + i, "c"))
        return (print_char(args, format));
    if (ft_char_search(str + i, "C"))
        return (print_wchar(args, format));
    if (ft_char_search(str + i, "di"))
        return (print_signed_nb(args, format));
    if (ft_char_search(str + i, "ouxX"))
    {
        set_format_unsigned(format, str[i]);
        return (print_unsigned_nb(args, format));
    }
    if (ft_char_search(str + i, "p"))
        return (print_pointer(args, format));
    return (NULL);
}
