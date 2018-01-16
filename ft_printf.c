#include "ft_printf.h"

/*
int     handle_flag(const char *format, va_list args, int i)
{
    if (format[++i] == '%')
    {
        ft_putchar('%');
        return (1);
    }
    (fn_for_tag(format[i]))(va_arg(args, void*));
    return (1);
}
*/
void    print_format(t_format *format)
{
    printf("hh_flag : %d\n", format->hh_flag);
    printf("h_flag : %d\n", format->h_flag);
    printf("l_flag : %d\n", format->l_flag);
    printf("ll_flag : %d\n", format->ll_flag);
    printf("z_flag : %d\n", format->z_flag);
    printf("j_flag : %d\n", format->j_flag);
    printf("zero_flag : %d\n", format->zero_flag);
    printf("minus_flag : %d\n", format->minus_flag);
    printf("plus_flag : %d\n", format->plus_flag);
    printf("space_flag : %d\n", format->space_flag);
    printf("sharp_flag : %d\n", format->sharp_flag);
    printf("precision : %d\n", format->precision);
    printf("width : %d\n", format->width);
    printf("o_type : %d\n", format->o_type);
    printf("u_type : %d\n", format->u_type);
    printf("x_type : %d\n", format->x_type);
    printf("X_type : %d\n\n", format->X_type);
}

t_format    *init_format(void)
{
    t_format    *format;

    if (!(format = (t_format*)ft_memalloc(sizeof(t_format))))
        return (NULL);
    format->width = -1;
    format->precision = -1;
    return (format);
}

t_result    *handle_flag(const char *str, va_list args, int i)
{
    t_format    *format;
    char        *printable;
    t_result    *result;

    format = init_format();
    i++;
    while (fetch_format_indicators(&str[i], format))
        i++;
    i += get_width(str, format, i);
    i += get_precision(str, format, i);
    while (fetch_size_modificators(&str[i], format))
        i++;
    if (!(result = (t_result*)malloc(sizeof(t_result))))
        return (NULL);
    result->str = "";
    result->next_index = i - 1;
    if (!(printable = type_print(args, format, str, i)))
        return (result);
    result->str = printable;
    result->next_index++;
    return (result);
}


int     ft_printf(const char *str, ...)
{
    va_list     args;
    int         i;
    int         printed_len;
    t_result    *result;

    va_start(args, str);
    i = -1;
    printed_len = 0;
    while (str[++i])
    {
        if (str[i] == '%' && (result = handle_flag(str, args, i)))
        {
            printed_len += ft_strlen(result->str);
            ft_putstr(result->str);
            i = result->next_index;
            ft_memdel((void**)&result);
        }
        else
        {
            ft_putchar(str[i]);
            printed_len++;
        }
    }
    va_end(args);
	return (printed_len);
}
