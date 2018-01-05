#include "ft_printf.h"

// TRY: all values should be put in a intmax_t object (imax)
/*
void    load_signed_type(t_format *format, va_list args)
{
    if (format->hh_flag)
        format->type.c = va_arg(args, char);
    else if (format->h_flag)
        format->type.si = va_arg(args, short int);
    else if (format->l_flag)
        format->type.l = va_arg(args, long int);
    else if (format->ll_flag)
        format->type.ll = va_arg(args, long long int);
    else if (format->z_flag)
        format->type.st = va_arg(args, size_t);
    else if (format->j_flag)
        format->type.imax = va_arg(args, intmax_t);
    else
        format->type.i = va_arg(args, int);
}
*/
void    load_signed_type(t_format *format, va_list args)
{
    if (format->hh_flag)
        format->type.imax = (char)va_arg(args, int);
    else if (format->h_flag)
        format->type.imax = (short int)va_arg(args, int);
    else if (format->l_flag)
        format->type.imax = va_arg(args, long int);
    else if (format->ll_flag)
        format->type.imax = va_arg(args, long long int);
    else if (format->z_flag)
        format->type.imax = va_arg(args, size_t);
    else if (format->j_flag)
        format->type.imax = va_arg(args, intmax_t);
    else
        format->type.imax = va_arg(args, int);
}

/*
** Return the elements to be added before any sign
** Only concerns width without '-' or '0' flags
*/
char    *left_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;
    int     max_len;

    if (format->width > 0 && !(format->minus_flag) && !(format->zero_flag))
    {
        max_len = (nb_len > format->precision) ? nb_len : format->precision;
        if (format->width > max_len)
            len = format->width - max_len -
                (format->plus_flag || format->space_flag);
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
char    *middle_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;

    // Precision wider than number len.
    if (format->precision >= 0 && format->precision > nb_len)
        len = format->precision - nb_len;
        //len = format->precision - nb_len - (format->plus_flag ||
            //format->space_flag);
    // No precision, width wider than number len and '0' flag (implies no '-' flag)
    else if (format->zero_flag && format->precision < 0 && format->width >= 0 &&
        format->width > nb_len && !(format->minus_flag))
        len = format->width - nb_len - (format->plus_flag ||
            format->space_flag);
    else
        len = 0;
ft_putstr("LEN : "); ft_putnbr(len); ft_putchar('\n');
    if (len <= 0)
        return (ft_strdup(""));
ft_putendl("STEP 6.1");
    fill = ft_strnew(len);
ft_putendl("STEP 6.2");
    ft_memset(fill, '0', len);
ft_putendl("STEP 6.3");
ft_putendl(fill);
    return (fill);
}

/*
** Return the spaces to be added right after the number
** Only concerns minus flag
*/
char    *right_fill(t_format *format, int nb_len)
{
    char    *fill;
    int     len;

    if (format->minus_flag)
    {
        if (format->width > nb_len)
            len = format->width - nb_len -
                (format->plus_flag || format->space_flag);
        else if (format->width > format->precision)
            len = format->width - format->precision -
                (format->plus_flag || format->space_flag);
        else
            len = 0;
        len = (len < 0) ? 0 : len;
        fill = ft_strnew(len);
        ft_memset(fill, ' ', len);
        return (fill);
    }
    return (ft_strdup(""));
}

char    *print_signed_nb(va_list args, t_format *format)
{
    char    *printable;
    char    *converted_value;

ft_putendl("STEP 1");
    load_signed_type(format, args);
ft_putendl("STEP 2");
    converted_value = ft_absolute_signed_itoa(format->type.imax);
ft_putendl(converted_value);
ft_putendl("STEP 3");
    printable = ft_strnew(0);
ft_putendl("STEP 4");
    printable = strcombine(printable,
        left_fill(format, ft_strlen(converted_value)));
ft_putendl(printable);
ft_putendl("STEP 5");
    if (format->type.imax < 0 || format->plus_flag || format->space_flag)
    {
        if (format->type.imax < 0)
            printable = strcombine(printable, ft_strdup("-"));
        else if (format->type.imax >= 0 && (format->plus_flag ||
            format->space_flag))
            printable = strcombine(printable, (format->plus_flag) ? ft_strdup("+") : ft_strdup(" "));
    }
ft_putendl("STEP 6");
    printable = strcombine(printable,
        middle_fill(format, ft_strlen(converted_value)));
ft_putendl("STEP 7");
    printable = strcombine(printable, converted_value);
ft_putendl("STEP 8");
    printable = strcombine(printable,
        right_fill(format, ft_strlen(converted_value)));
    return (printable);
}
