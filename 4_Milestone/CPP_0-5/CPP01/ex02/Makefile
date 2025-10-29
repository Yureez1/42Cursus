NAME = brain
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98

LILA = \033[1;38;5;206m
GREEN = \033[32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(LILA)brain...$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)brain... COMPILED!$(NC)"

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