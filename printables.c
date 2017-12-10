#include "ft_printf.h"

// s flag
void print_string(void *object) {
    ft_putstr((char *)object);
}

// c flag
void print_char(void *object)
{
    ft_putchar((char)object);
}

// i & d flag
void print_int(void *object)
{
    ft_putnbr((int)object);
}

// x flag
void print_hexa_min(void *object)
{
    ft_putnbr_base((unsigned int)object, "0123456789abcdef");
}

// X flag
void print_hexa_max(void *object)
{
    ft_putnbr_base((unsigned int)object, "0123456789ABCDEF");
}
