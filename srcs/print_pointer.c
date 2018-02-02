#include "ft_printf.h"

/*
** a 'p' flag is equivalent to a '#lx' flag.
*/

/*
** Return the elements to be added before any sign
** Only concerns width without '-' or '0' flags
*/
char    *left_up_fill(t_format *format, int nb_len)
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
        return (fill);
    }
    return (ft_strdup(""));
}

/*
** Return the zeros to be added between the sign (if any) and the number
** If width + precision, concerns precision. If no precision, width.
** '0' flag is handled here.
*/
char    *middle_up_fill(t_format *format, int nb_len)
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
    fill = ft_strnew(len);
    ft_memset(fill, '0', len);
    return (fill);
}

/*
** Return the spaces to be added right after the number
** Only concerns minus flag if no precision
*/
char    *right_up_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;
    int     max_len;

    max_len = (nb_len >= format->precision) ? nb_len : format->precision;
    if (!(format->minus_flag && format->width > max_len))
        return (ft_strnew(0));
    len = format->width - max_len - 2;
    len = (len < 0) ? 0 : len;
    fill = ft_strnew(len);
    ft_memset(fill, ' ', len);
    return (fill);
}

char    *print_pointer(va_list args, t_format *format)
{
    char    *printable;
    char    *converted_value;

    format->type.ul = va_arg(args, long int);
    format->x_type = 1;
    converted_value = ft_unsigned_itoa_base(format->type.uimax, format);
    if (format->type.uimax == 0 && format->precision == 0)
        converted_value = ft_strnew(0);
    printable = ft_strnew(0);
    printable = strcombine(printable,
        left_up_fill(format, ft_strlen(converted_value)));
    printable = strcombine(printable, ft_strdup("0x"));
    printable = strcombine(printable,
        middle_up_fill(format, ft_strlen(converted_value)));
    printable = strcombine(printable, converted_value);
    printable = strcombine(printable,
        right_up_fill(format, ft_strlen(converted_value)));
    return (printable);
}

/*
char    *print_pointer(va_list args, t_format *format)
{
    format->sharp_flag = 1;
    format->l_flag = 1;
    format->x_type = 1;
    return (print_unsigned_nb(args, format));
}
*/
