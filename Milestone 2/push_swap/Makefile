NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDES = -Iincludes -ILibft
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ./src/push_swap/handle_commands.c \
       ./src/push_swap/handle_inputs.c \
       ./src/push_swap/handle_calculations_move.c \
       ./src/push_swap/handle_positions.c \
	   ./src/push_swap/handle_perfect_chipset.c \
	   ./src/push_swap/handle_sort.c \
       ./src/push_swap/push_swap_utils.c \
       ./src/push_swap/push_swap.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
