NAME=libftprintf.a
LIBFTDIR=libft
LIBFT=libft/libft.a
FLAGS=-Wall -Wextra -Werror
CC=cc
HDRS=ft_printf.h
SRCS=ft_printf.c convert_functions1.c convert_functions2.c handle_convert.c print_functions.c
HDRS=ft_printf.h
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	ar rc -I $(HDRS) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -I $(HDRS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
