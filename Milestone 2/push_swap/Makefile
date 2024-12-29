M_NAME = push_swap
B_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

UTILS = ./utils/handle_commands.c ./utils/handle_inputs.c \
		./utils/handle_utils.c  ./utils/push_swap_utils.c \

SRCS =	./src/push_swap/push_swap.c \
		./src/push_swap/handle_sort_utils.c ./src/push_swap/handle_push_back.c \
		./src/push_swap/handle_positions.c ./src/push_swap/handle_sort.c \
		./src/push_swap/handle_perfect_chipset.c ./src/push_swap/handle_calculations_move.c \

BSRCS = ./src/checker/checker.c

OUTILS = $(UTILS:.c=.o)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(LIBFT) $(M_NAME)

$(M_NAME): $(OUTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OUTILS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(M_NAME)

bonus: $(LIBFT) $(B_NAME)

$(B_NAME): $(OUTILS) $(BOBJS)
	$(CC) $(CFLAGS) $(OUTILS) $(BOBJS) $(LIBFT) $(INCLUDES) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OUTILS) $(BOBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(M_NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
