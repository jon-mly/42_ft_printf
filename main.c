#include "ft_printf.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    char *str = "Salut";
    int custom_return = ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
    printf("CUSTOM RETURN = %d\n", custom_return);
    int system_return = printf("@moulitest: %#.x %#.0x\n", 0, 0);
    printf("SYSTEM RETURN = %d\n", system_return);
    return (0);
}
