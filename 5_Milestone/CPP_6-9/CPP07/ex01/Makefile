NAME = Iter
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -g

# =============================================#
# =================🔹FOLDERS🔹=================#
# =============================================#
SRCS_DIR = .
OBJS_DIR = obj

# =============================================#
# ================🔹SRCS/OBJS🔹================#
# =============================================#
SRCS = main.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

# =============================================#
# =================🔹COLORS🔹==================#
# =============================================#

LILA = \033[1;38;5;206m
GREEN = \033[32m
NC = \033[0m

# =============================================#
# ==================🔹RULES🔹==================#
# =============================================#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(LILA)ITER...$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)ITER COMPILED!✅​$(NC)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<✅​"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(LILA)CLEANING OBJECTS FILES...$(NC)"
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)OBJECTS FILES CLEANED!$(NC)"

fclean: clean
	@echo "$(LILA)CLEANING ALL FILES...$(NC)"
	@rm -f $(NAME)
	@echo "$(LILA)ALL FILES CLEANED!$(NC)"

re: fclean all

.PHONY: all clean fclean re
