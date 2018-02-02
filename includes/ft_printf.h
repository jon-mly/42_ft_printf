#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDES
*/

# include "../libft/libft.h"
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
}               t_type;

/*
** STRUCTURES
*/

typedef struct  s_format
{
    int     hh_flag;
    int     h_flag;
    int     l_flag;
    int     ll_flag;
    int     z_flag;
    int     j_flag;
    int     zero_flag;
    int     minus_flag;
    int     plus_flag;
    int     space_flag;
    int     sharp_flag;
    int     precision;
    int     width;
    int     o_type;
    int     u_type;
    int     x_type;
    int     X_type;
    t_type  type;
}               t_format;

typedef struct  s_result
{
    int     next_index;
    int     printed_len;
}               t_result;

/*
** TYPEDEF DIVERS
*/

typedef void (*t_fn)(va_list, t_format*);

/*
** PROTOTYPES
*/

int     ft_printf(const char *format, ...);
int     ft_pop(char *str);
int     ft_pop_unalloc(char *str);
int     ft_pop_char(char c);
int     print_char(va_list args, t_format *format);
int    print_signed_nb(va_list args, t_format *format);
int    print_string(va_list args, t_format *format);
int            print_wstring(va_list args, t_format *format);
int     print_wchar(va_list args, t_format *format);
int    print_unsigned_nb(va_list args, t_format *format);
int    print_pointer(va_list args, t_format *format);
int    print_percent(t_format *format);
int     print_no_flag(t_format *format, char c);
char            *get_converted_wchar(wchar_t wc);
char            *ft_unsigned_itoa_base(uintmax_t nb, t_format *format);
char    *ft_absolute_signed_itoa(intmax_t nb);
char    *strcombine(char *s1, char *s2);
int     ft_char_search(const char *position, char *searched);
int     fetch_format_indicators(const char *position, t_format *format);
int     fetch_size_modificators(const char *position, t_format *format);
int     get_precision(const char *str, t_format *format, int i);
int     get_width(const char *str, t_format *format, int i);
int     type_print(va_list args, t_format *format, const char *str, int i);
char    *get_required_spaces(t_format *format, int len);

#endif
