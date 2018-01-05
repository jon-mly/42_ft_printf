#include "ft_printf.h"

/*
** Regroups the functions to handle format indicators, size modificators and
** type specification (for a given char).
** FIXME: bad space managment !
** FIXME: bad "hh" and "ll" managment as can't be embed in "while" loop
*/

int     fetch_format_indicators(const char *position, t_format *format)
{
    if (!(ft_char_search(position, "#0-+ ")))
        return (0);
    if (*position == '#')
        format->sharp_flag = 1;
    else if (*position == '+')
    {
        format->plus_flag = 1;
        format->space_flag = 0;
    }
    else if (*position == ' ' && !(format->plus_flag))
        format->space_flag = 1;
    else if (*position == '-')
        format->minus_flag = 1;
    else if (*position == '0' && !(format->minus_flag))
        format->zero_flag = 1;
    return (1);
}

int     fetch_size_modificators(const char *position, t_format *format)
{
    if (!(ft_char_search(position, "hljz")))
        return (0);
    if (*position == 'j')
        format->j_flag = 1;
    else if (*position == 'z')
        format->z_flag = 1;
    else if (*position == 'l')
    {
        format->l_flag = !(format->l_flag);
        if (!(format->l_flag))
            format->ll_flag = 1;
    }
    else if (*position == 'h')
    {
        format->h_flag = !(format->h_flag);
        if (!(format->h_flag))
            format->hh_flag = 1;
    }
    return (1);
}

int     fetch_type_descriptor(const char *position, t_format *format)
{
    if (!(ft_char_search(position, "sScCdDioOuUxXp")))
        return (0);
    return (1);
}
