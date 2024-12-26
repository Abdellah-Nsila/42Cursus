SRCS = get_next_line.c \
			 get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o) 
B_OBJS = $(B_SRCS:%.c=%.o) 

INCLUDES = ../includes
FLAGS = -Wall -Wextra -Werror -g  -I${INCLUDES}
NAME = get_next_line.a
CC = cc
AR = ar rc
RM = rm -f

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
