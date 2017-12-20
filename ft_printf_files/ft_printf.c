# include "ft_printf.h"

extern  void print_string(void *object);
extern  void print_char(void *object);
extern  void print_int(void *object);
extern  void print_hexa_min(void *object);
extern  void print_hexa_max(void *object);
extern  void print_octal(void *object);
extern  void print_decimal(void *object);

t_fn    fn_list[8] = {
    &print_string,
    &print_char,
    &print_int,
    &print_int,
    &print_hexa_min,
    &print_hexa_max,
    &print_octal,
    &print_decimal
};

char    tag[8] = {
    's', 'c', 'd', 'i', 'x', 'X', 'o', 'u'
};

t_fn    fn_for_tag(char c)
{
    int     i;

    i = -1;
    while (++i < 7) {
        if (c == tag[i])
            return (fn_list[i]);
    }
    return (NULL);
}

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
