#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int     main(int ac, char **av)
{
    int system_return = printf("S:@moulitest: %#.o %#.0o\n", 0, 0);
    // printf("SYSTEM RETURN = %d\n", system_return);
    int custom_return = ft_printf("C:@moulitest: %#.o %#.0o\n", 0, 0);
    // printf("CUSTOM RETURN = %d\n", custom_return);
    return (0);
}
