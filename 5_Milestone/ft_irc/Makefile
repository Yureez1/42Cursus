NAME        = ircserv
CXX         = c++
CXXFLAGS    = -Werror -Wall -Wextra -std=c++98

SRCS_DIR    = .
OBJS_DIR    = obj

SRCS        = main.cpp srcs/Server.cpp srcs/Channel.cpp srcs/Client.cpp
OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

LILA        = \033[1;38;5;206m
GREEN       = \033[32m
NC          = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(LILA)LINKING IRCSERV...$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)IRCSERV COMPILED! $(NC)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)COMPILED: $<✅"

clean:
	@echo "$(LILA)CLEANING OBJECTS FILES...$(NC)"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)OBJECTS FILES CLEANED!$(NC)"

fclean: clean
	@echo "$(LILA)CLEANING EXECUTABLE...$(NC)"
	@rm -f $(NAME)
	@echo "$(LILA)ALL FILES CLEANED!$(NC)"

re: fclean all

.PHONY: all clean fclean re
