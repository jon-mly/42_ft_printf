#include "ft_printf.h"

void print_octal(void *object)
{
    ft_putnbr_base((unsigned int)object, "01234567");
}
