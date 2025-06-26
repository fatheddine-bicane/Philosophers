CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g
NAME = philo
BNAME = philo_bonus



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

BONUS = 


OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@rm -f $(BNAME)
	@$(CC) $(FLAGS) $(OFILES) -o $(NAME)
	@echo "$(GREEN)philo compiled successfully!$(RESET)"

bonus: $(BNAME)

$(BNAME): $(BOFILES)
	@rm -f $(NAME)
	@$(CC) $(FLAGS) $(BOFILES) -o $(BNAME)
	@echo "$(GREEN)philo bonus compiled successfully!$(RESET)"

clean:
	@rm -f $(OFILES) $(BOFILES)
	@echo "$(YELLOW)Cleaning object files$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "$(YELLOW)Cleaning executables$(RESET)"

re: fclean all

re_bonus : fclean bonus

.PHONY: all bonus clean fclean re
