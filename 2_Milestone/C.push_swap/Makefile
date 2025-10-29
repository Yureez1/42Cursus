# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbanchon <jbanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:27:50 by julien            #+#    #+#              #
#    Updated: 2024/11/20 16:25:12 by jbanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
HEADER = push_swap.h

# Fichiers sources
SRCS = push_more.c push_swap.c error.c init_list.c \
       push.c reverse_rotate.c rotate.c swap.c \
		utils.c main.c \

OBJS = $(SRCS:.c=.o)

# Répertoires pour ft_printf et libft
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = $(PRINTF_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Règle principale
all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	@echo "\033[0;32mCompiling Pushswap...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[0;32mEverything Compiled\033[0m"

# Compilation de ft_printf (qui inclut libft)
$(PRINTF_LIB): $(LIBFT_LIB)
	@echo "\033[0;32mCompiling printf...\033[0m"
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "\033[0;32mPrintf OK\033[0m"

# Compilation de libft
$(LIBFT_LIB):
	@echo "\033[0;32mCompiling libft...\033[0m"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "\033[0;32mLibft OK\033[0m"

# Exécution avec ou sans arguments
run: $(NAME)
	@if [ -z "$(ARG)" ]; then \
		./$(NAME); \
	else \
		./$(NAME) $(ARG); \
	fi

# Nettoyage
clean:
	@echo "\033[0;32mCleaning Objects files...\033[0m"
	@rm -f @$(OBJS)
	@make clean -C $(PRINTF_DIR) > /dev/null 2>&1
	@make clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "\033[0;32mObjects files OK\033[0m"

fclean: clean
	@echo "\033[0;32mFull cleaning...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@make fclean -C $(PRINTF_DIR) > /dev/null 2>&1
	@make fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@rm -f ARG*
	@echo "\033[0;32mFull cleaning OK\033[0m"

re: fclean all

.PHONY: all clean fclean re run