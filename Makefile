NAME = libftprintf.a

TMP_LIB = libtmp.a

FLAGS = -Wall -Werror -Wextra

SRCS_REP = sources/

LIBFT_REP = libft/

LIBFT = $(LIBFT_REP)libft.a

SRCS =  ft_printf.c \
		flags_handling.c \
		description_string_analysis_tools.c \
		print_char.c \
		print_pointer.c \
		print_signed_nb.c \
		print_string.c \
		print_unsigned_nb.c \
		print_wchar.c \
		print_wstring.c \
		print_percent.c \
		print_no_flag.c \
		signed_itoa.c \
		strjoin_tool.c \
		unsigned_itoa.c \
		wchar_tools.c \
		values_handling.c \
		type_print.c

O_FILES = $(SRCS:.c=.o)

INCLUDES = includes/

$(LIBFT):
	cd $(LIBFT_REP) && make

$(NAME): $(LIBFT)
	gcc $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	ar -rc $(TMP_LIB) $(O_FILES)
	ranlib $(TMP_LIB)
	libtool -static -o $(NAME) $(TMP_LIB) $(LIBFT)
	rm -f $(TMP_LIB)

all: $(NAME)

clean:
	cd $(LIBFT_REP) && make clean
	rm -f $(O_FILES)

fclean: clean
	cd $(LIBFT_REP) && make fclean
	rm -f $(NAME)

re: fclean all
