# include "ft_printf.h"

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

int     ft_printf(const char *format, ...)
{
    va_list args;
    int     i;

    va_start(args, format);
    i = -1;
    while (format[++i])
    {
        if (format[i] == '%')
            i += handle_flag(format, args, i);
        else
            ft_putchar(format[i]);
    }
    va_end(args);
	return (0);
}
