#include "ft_printf.h"

t_format    *init_format(void)
{
    t_format    *format;

    if (!(format = (t_format*)ft_memalloc(sizeof(t_format))))
        return (NULL);
    format->width = -1;
    format->precision = -1;
    return (format);
}

int         set_format(const char *str, int i, t_format *format)
{
    int     incrementation;

    incrementation = 0;
    while ((incrementation += fetch_format_indicators(&str[i], format)) ||
            (incrementation += get_width(str, format, i)) ||
            (incrementation += get_precision(str, format, i)) ||
            (incrementation += fetch_size_modificators(&str[i], format)))
    {
        i += incrementation;
        incrementation = 0;
    }
    return (i);
}

t_result    *handle_flag(const char *str, va_list args, int i)
{
    t_format    *format;
    int         printed_len;
    t_result    *result;

    format = init_format();
    i++;
    i = set_format(str, i, format);
    if (!(result = (t_result*)malloc(sizeof(t_result))))
        return (NULL);
    result->printed_len = 0;
    result->next_index = i - 1;
    if ((printed_len = type_print(args, format, str, i)) < 0)
        return (result);
    result->printed_len = printed_len;
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
            printed_len += result->printed_len;
            i = result->next_index;
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
