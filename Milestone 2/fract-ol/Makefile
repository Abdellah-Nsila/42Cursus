NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
UTILS_DIR = ./utils
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	$(SRC_DIR)/fractol.c
UTILS =	$(UTILS_DIR)/fractol_utils.c $(UTILS_DIR)/complex_plan.c $(UTILS_DIR)/events_hook.c

OBJS = $(SRCS:.c=.o)
UTILSOBJS = $(UTILS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(UTILSOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(UTILSOBJS) $(LIBFT) $(INCLUDES) -o $(NAME) libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(UTILSOBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
