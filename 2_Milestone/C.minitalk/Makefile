# Nom des programmes
NAME_CLIENT = client
NAME_SERVER = server

# Répertoires
DIR_PRINTF = ft_printf
DIR_LIBFT = ft_printf/libft

# Fichiers sources
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_UTILS = utils.c

# Fichiers sources de ft_printf et libft
SRC_PRINTF = $(wildcard $(DIR_PRINTF)/*.c)
SRC_LIBFT = $(wildcard $(DIR_LIBFT)/*.c)

# Fichiers objets
OBJ_CLIENT = $(SRC_CLIENT:.c=.o) $(SRC_UTILS:.c=.o) $(OBJ_PRINTF) $(OBJ_LIBFT)
OBJ_SERVER = $(SRC_SERVER:.c=.o) $(SRC_UTILS:.c=.o) $(OBJ_PRINTF) $(OBJ_LIBFT)

# Fichiers objets de ft_printf et libft
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règle par défaut
all: $(NAME_CLIENT) $(NAME_SERVER)
# Compilation du client
$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@echo "\033[0;32mEverything Compiled\033[0m"

# Compilation du serveur
$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

# Règle pour créer les fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_PRINTF) $(OBJ_LIBFT)
		@echo "\033[0;32mCleaning .o files\033[0m"

# Nettoyage complet (fichiers objets + exécutables)
fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "\033[0;32mCleaning everything\033[0m"

# Recompile tout
re: fclean all

# Indique que ces règles ne sont pas des fichiers
.PHONY: all clean fclean re