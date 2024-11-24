NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror -I includes/
SRCS=ft_printf.c flags_parse.c basic_tools.c \
	 convert_funcs1.c convert_funcs2.c len_calc.c \
	 convert_funcs3.c convert_handle.c unicode.c \
	 basic_tools2.c convert_funcsh.c len_calc2.c \
	 convert_funcshh.c convert_funcsll.c \
	 convert_funcsl.c convert_funcsj.c \
	 convert_funcsz.c ft_atoi.c ft_putnbr.c \
	 ft_putstr.c ft_putchar.c \
	 ft_strlen.c ft_bzero.c print_funcs.c \
	 print_funcs2.c norm_shit.c print_funcsj.c \
	 print_funcsl.c print_funcsz.c
OBJS=$(SRCS:.c=.o)
SRCDIR=sources/
OBJDIR=objects/
SOURCES=$(addprefix $(SRCDIR), $(SRCS))
OBJETS=$(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(OBJETS):
	gcc $(FLAGS) -c $(SOURCES)
	mkdir -p $(OBJDIR)
	mv $(OBJS) $(OBJDIR)

$(NAME): $(OBJETS)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
