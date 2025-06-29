CC = cc
# FLAGS = -Wall -Wextra -Werror -g -O2 -fsanitize=thread -pthread
FLAGS = -Wall -Wextra -Werror -pthread -g
NAME = philo_bonus


#colors
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
RESET = \033[0m


SRCS =	$(shell ls ./utils/dinner_simulation/*.c) \
		$(shell ls ./utils/error/*.c) \
		$(shell ls ./utils/init_data/*.c) \
		$(shell ls ./utils/parce/*.c) \
		$(shell ls ./utils/utils/*.c) \
		./main.c \

OFILES = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@$(CC) $(FLAGS) $(OFILES) -o $(NAME)
	@echo "$(GREEN)philo bonus compiled successfully!$(RESET)"

clean:
	@rm -f $(OFILES)
	@echo "$(YELLOW)Cleaning object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Cleaning executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
