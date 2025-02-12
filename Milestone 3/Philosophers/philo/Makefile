NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
INCLUDES = -I./includes

SRCS =	$(SRC_DIR)/philosophers.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) -g -pthread $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c ./includes/philosophers.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
