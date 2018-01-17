#include "ft_printf.h"

/*
** a 'p' flag is equivalent to a '#lx' flag.
*/

/*
** Return the elements to be added before any sign
** Only concerns width without '-' or '0' flags
*/
int     left_up_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;
    int     max_len;

    if (format->width > 0 && !(format->minus_flag) && !(format->zero_flag))
    {
        max_len = (nb_len > format->precision) ? nb_len : format->precision;
        if (format->width > max_len)
            len = format->width - max_len -
                (format->plus_flag || format->space_flag) - 2;
        else
            len = 0;
        len = (len < 0) ? 0 : len;
        fill = ft_strnew(len);
        ft_memset(fill, ' ', len);
        return (ft_pop(fill));
    }
    return (0);
}

/*
** Return the zeros to be added between the sign (if any) and the number
** If width + precision, concerns precision. If no precision, width.
** '0' flag is handled here.
*/
int     middle_up_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;

    // Precision wider than number len.
    if (format->precision >= 0 && format->precision > nb_len)
        len = format->precision - nb_len;
    // No precision, width wider than number len and '0' flag (implies no '-' flag)
    else if (format->zero_flag && format->precision < 0 && format->width >= 0 &&
        format->width > nb_len && !(format->minus_flag))
        len = format->width - nb_len - 2;
    else
        len = 0;
    len = (len < 0) ? 0 : len;
    if (len == 0)
        return (0);
    fill = ft_strnew(len);
    ft_memset(fill, '0', len);
    return (ft_pop(fill));
}

/*
** Return the spaces to be added right after the number
** Only concerns minus flag if no precision
*/
int     right_up_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;
    int     max_len;

    max_len = (nb_len >= format->precision) ? nb_len : format->precision;
    if (!(format->minus_flag && format->width > max_len))
        return (0);
    len = format->width - max_len - 2;
    len = (len < 0) ? 0 : len;
    if (len == 0)
        return (0);
    fill = ft_strnew(len);
    ft_memset(fill, ' ', len);
    return (ft_pop(fill));
}

int     print_pointer(va_list args, t_format *format)
{
    int     total_len;
    char    *converted_value;

    format->type.ul = va_arg(args, long int);
    format->x_type = 1;
    converted_value = ft_unsigned_itoa_base(format->type.uimax, format);
    if (format->type.uimax == 0 && format->precision == 0)
        converted_value = ft_strnew(0);
    total_len = left_up_fill(format, ft_strlen(converted_value));
    total_len += ft_pop_unalloc("0x");
    total_len += middle_up_fill(format, ft_strlen(converted_value));
    total_len += ft_pop(converted_value);
    total_len += right_up_fill(format, ft_strlen(converted_value));
    return (total_len);
}
