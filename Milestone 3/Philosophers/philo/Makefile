NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC_DIR = ./src
FUNC_DIR = ./functions
INCLUDES = -I./includes

SRCS =	$(SRC_DIR)/philo.c $(SRC_DIR)/philo_parsing.c $(SRC_DIR)/philo_init.c \
		$(SRC_DIR)/philo_threads.c $(SRC_DIR)/philo_monitor.c $(SRC_DIR)/philo_destroy.c \
		$(SRC_DIR)/philo_simulation.c $(SRC_DIR)/philo_log.c $(SRC_DIR)/philo_time.c \

FUNCS =	$(FUNC_DIR)/functions_1.c $(FUNC_DIR)/functions_2.c

OBJS = $(SRCS:.c=.o)
FUNCO = $(FUNCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FUNCO)
	$(CC) $(CFLAGS) $(OBJS) $(FUNCO) $(INCLUDES) -o $(NAME)

%.o: %.c ./includes/philo.h ./includes/functions.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(FUNCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
