#include "ft_printf.h"

// The returned value should be given to s1 !
char    *strcombine(char *s1, char *s2)
{
    char    *tmp;
    char    *result;

    tmp = s2;
    if (ft_strlen(tmp) > 0)
        result = ft_strjoin(s1, tmp);
    ft_strdel(&tmp);
ft_putendl("FREED");
    return (result);
}
