#include "ft_printf.h"

/*
** a 'p' flag is equivalent to a '#lx' flag.
*/

char    *print_pointer(va_list args, t_format *format)
{
    format->sharp_flag = 1;
    format->l_flag = 1;
    format->x_type = 1;
    return (print_unsigned_nb(args, format));
}
