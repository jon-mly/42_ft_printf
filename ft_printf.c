# include "ft_printf.h"

extern  void print_string(void *object);
extern  void print_char(void *object);
extern  void print_int(void *object);
extern  void print_hexa_min(void *object);
extern  void print_hexa_max(void *object);

t_fn   fn_list[5] = {
    &print_string,
    &print_char,
    &print_int,
    &print_hexa_min,
    &print_hexa_max
};

int     handle_flag(const char *format, va_list args, int i)
{
    if (format[++i] && (format[i] == 'd' || format[i] == 'i'))
        (*fn_list[2])(va_arg(args, void*));
    if (format[i] && format[i] == 's')
        (*fn_list[0])(va_arg(args, void*));
    if (format[i] && format[i] == 'c')
        (*fn_list[1])(va_arg(args, void*));
    if (format[i] && format[i] == 'x')
        (*fn_list[3])(va_arg(args, void*));
    if (format[i] && format[i] == 'X')
        (*fn_list[4])(va_arg(args, void*));
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
