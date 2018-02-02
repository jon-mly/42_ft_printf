NAME = libftprintf.a

TMP_LIB = libtmp.a

FLAGS = -Wall -Werror -Wextra

LIBFT_REP = libft/
LIBFT = $(LIBFT_REP)libft.a

SRCS_REP = srcs/
SRCS =  $(SRCS_REP)ft_printf.c \
		$(SRCS_REP)flags_handling.c \
		$(SRCS_REP)description_string_analysis_tools.c \
		$(SRCS_REP)print_char.c \
		$(SRCS_REP)print_pointer.c \
		$(SRCS_REP)print_signed_nb.c \
		$(SRCS_REP)print_string.c \
		$(SRCS_REP)print_unsigned_nb.c \
		$(SRCS_REP)print_wchar.c \
		$(SRCS_REP)print_wstring.c \
		$(SRCS_REP)print_percent.c \
		$(SRCS_REP)print_no_flag.c \
		$(SRCS_REP)signed_itoa.c \
		$(SRCS_REP)strjoin_tool.c \
		$(SRCS_REP)unsigned_itoa.c \
		$(SRCS_REP)wchar_tools.c \
		$(SRCS_REP)values_handling.c \
		$(SRCS_REP)type_print.c

O_FILES = ft_printf.o \
		  flags_handling.o \
		  description_string_analysis_tools.o \
		  print_char.o \
		  print_pointer.o \
		  print_signed_nb.o \
		  print_string.o \
		  print_unsigned_nb.o \
		  print_wchar.o \
		  print_wstring.o \
		  print_percent.o \
		  print_no_flag.o \
		  signed_itoa.o \
		  strjoin_tool.o \
		  unsigned_itoa.o \
		  wchar_tools.o \
		  values_handling.o \
		  type_print.o

INCLUDES_FLAG = -I includes/

%.o:%.c
	gcc -c $< -o $@

$(NAME):
	cd $(LIBFT_REP) && make
	gcc $(FLAGS) $(INCLUDES_FLAG) -c $(SRCS)
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
