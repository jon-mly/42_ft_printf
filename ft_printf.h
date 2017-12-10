#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef void (*t_fn)(void*);

int     ft_printf(const char *format, ...);

#endif
