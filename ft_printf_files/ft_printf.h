#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef void (*t_fn)(void*);

int     ft_printf(const char *format, ...);
void	ft_putnbr_base(unsigned int nbr, char *base);

#endif
