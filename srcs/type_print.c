#include "ft_printf.h"

void    set_format_unsigned(t_format *format, char type)
{
    if (type == 'O' || type == 'U')
        format->l_flag = 1;
    if (type == 'o' || type == 'O')
        format->o_type = 1;
    else if (type == 'u' || type == 'U')
        format->u_type = 1;
    else if (type == 'x')
        format->x_type = 1;
    else if (type == 'X')
        format->X_type = 1;
}

char    *type_print(va_list args, t_format *format, const char *str, int i)
{
   if (!(ft_char_search(str + i, "sSdDioOuUxXpcC%")))
       return (NULL);
    if (str[i] == 's')
        return (print_string(args, format));
    if (str[i] == 'S')
        return (print_wstring(args, format));
    if (str[i] == 'c')
        return (print_char(args, format));
    if (str[i] == 'C')
        return (print_wchar(args, format));
    if (str[i] == 'D' || str[i] == 'd' || str[i] == 'i')
    {
        if (str[i] == 'D')
            format->l_flag = 1;
        return (print_signed_nb(args, format));
    }
    if (ft_char_search(str + i, "ouxXUO"))
    {
        set_format_unsigned(format, str[i]);
        return (print_unsigned_nb(args, format));
    }
    if (str[i] == 'p')
        return (print_pointer(args, format));
    if (str[i] == '%')
        return (print_percent(format));
    // return (print_no_flag(str[i], format));
    return (NULL);
}
