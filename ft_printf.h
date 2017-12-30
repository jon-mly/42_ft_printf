#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDES
*/

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

/*
** UNIONS
*/

typedef union   u_type
{
    char                    c;
    unsigned char           uc;
    char                    *str;
    wchar_t                 wc;
    wchar_t                 *wstr;
    short int               si;
    unsigned short int      usi;
    int                     i;
    unsigned int            ui;
    long int                li;
    unsigned long int       ul;
    long long int           ll;
    unsigned long long int  ull;
    size_t                  st;
    intmax_t                imax;
    uintmax_t               uimax;
}               t_type

/*
** STRUCTURES
*/

typedef struct  s_format
{
    int     hh_flag:0;
    int     h_flag:0;
    int     l_flag:0;
    int     ll_flag:0;
    int     z_flag:0;
    int     j_flag:0;
    int     zero_flag:0;
    int     minus_flag:0;
    int     plus_flag:0;
    int     space_flag:0;
    int     sharp_flag:0;
    int     precision:-1;
    int     width:-1;
    int     o_type:0;
    int     u_type:0;
    int     x_type:0;
    int     X_type:0;
    t_type  type;
}               t_format

/*
** TYPEDEF DIVERS
*/

typedef void (*t_fn)(va_list, t_format*);

/*
** PROTOTYPES
*/

int     ft_printf(const char *format, ...);
void	ft_putnbr_base(unsigned int nbr, char *base);

#endif
