NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
HEADER = ft_printf.h
SOURCES = ft_printf.c ft_printhex.c ft_printid.c ft_printp.c \
	ft_printu.c ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft