#include "ft_printf.h"

/*
** Return 1 if one of the char in searched matches the first char pointed by
** position.
*/
int     ft_char_search(const char *position, char *searched)
{
    int     i;

    i = -1;
    while (searched[++i])
    {
        if (ft_strchr(position, searched[i]) == position)
            return (1);
    }
    return (0);
}
