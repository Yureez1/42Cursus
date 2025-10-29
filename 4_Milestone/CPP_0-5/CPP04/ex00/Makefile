NAME = Polymorph
CXX = c++
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -g
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

LILA = \033[1;38;5;206m
GREEN = \033[32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(LILA)POLYMORPH...$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)POLYMORPH COMPILED!$(NC)"

clean:
	@echo "$(LILA)CLEANING OBJECTS FILES...$(NC)"
	@rm -f $(OBJS)
	@echo "$(GREEN)OBJECTS FILES CLEANED!$(NC)"

fclean: clean
	@echo "$(LILA)CLEANING ALL FILES...$(NC)"
	@rm -f $(NAME)
	@echo "$(LILA)ALL FILES CLEANED!$(NC)"

re: fclean all

.PHONY: all clean fclean re
