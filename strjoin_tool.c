#include "ft_printf.h"

// The returned value should be given to s1 !
char    *strcombine(char *s1, char *s2)
{
    char    *tmp;
    char    *result;

    tmp = s1;
    result = ft_strjoin(tmp, result);
    ft_strdel(tmp);
    return (result);
}
