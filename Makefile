NAME = libftprintf.a

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
		signed_itoa.c \
		strjoin_tool.c \
		unsigned_itoa.c \
		wchar_tools.c \
		values_handling.c \
		type_print.c

O_FILES = $(SRCS:.c=.o)

INCLUDES = includes/

$(NAME):
	cd $(LIBFT_REP) && make
	gcc  -I $(INCLUDES) -c $(SRCS) $(LIBFT)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

all: $(NAME)

clean:
	cd $(LIBFT_REP) && make clean
	rm -f $(O_FILES)

fclean: clean
	cd $(LIBFT_REP) && make fclean
	rm -f $(NAME)

re: fclean all
