#include "ft_printf.h"

void print_octal(void *object)
{
    ft_putnbr_base((unsigned int)object, "01234567");
}

void print_decimal(void *object)
{
    ft_putnbr_base((unsigned int)object, "0123456789");
}
