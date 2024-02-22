NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = ${OBJS:.o=.d}
INC = ./includes/push_swap.h
BONUS_INC = ./get_next_line/includes/get_next_line_bonus.h
CHECKER_INC = ./includes/checker.h
SRC_PATH = ./srcs
OBJS_PATH = ./objs

SRCS = sort_mediane_utils.c size_utils.c \
    sort_mediane.c parsing.c order_or_not.c tab_to_lst.c parsing_utils.c reverse_rotate.c rotate.c swap.c push.c \
    algo_five.c algo_final.c algo_two.c algo_three.c algo_final_utils.c main.c

BONUS_SRCS = checker.c checker_utils.c get_next_line.c get_next_line_utils.c instructions.c sort_mediane_utils.c size_utils.c \
    sort_mediane.c parsing.c order_or_not.c tab_to_lst.c parsing_utils.c reverse_rotate.c rotate.c swap.c push.c instructions_three.c \
    algo_five.c algo_final.c algo_two.c algo_three.c algo_final_utils.c main_checker.c instructions_two.c

OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJS_PATH)/, $(BONUS_SRCS:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
YELLOW = \033[33m

mandatory: $(NAME)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS) $(INC)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation complete! \n$(YELLOW)$(NAME) is ready to execute.$(NC)"

$(NAME_BONUS): $(BONUS_OBJS) $(CHECKER_INC) $(BONUS_INC)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
	@echo "$(GREEN)Compilation complete! \n$(YELLOW)$(NAME_BONUS) is ready to execute with bonuses.$(NC)"

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$(GREEN)Compiled:$(NC) $<"

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c $(BONUS_INC)
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$(GREEN)Compiled:$(NC) $<"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Cleaned up object files.$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)Cleaned up executables.$(NC)"

re: fclean all

-include $(DEPS)

.PHONY: mandatory bonus all clean fclean re