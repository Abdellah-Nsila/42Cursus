M_NAME = pipex
B_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

UTILS = ./utils/parsing_file.c ./utils/parsing_path.c \
		./utils/pipex_execution.c ./utils/struct_utils.c \
		./utils/pipex_cleanup.c ./utils/pipex_error.c \
		./utils/debug.c \

SRCS =	./src/mondatory/pipex.c ./src/mondatory/parsing_commands.c \

BSRCS =	./src/bonus/pipex.c ./src/bonus/parsing_commands.c ./src/bonus/here_doc.c \

OBUTILS = $(UTILS:.c=.o)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(LIBFT) $(M_NAME)

$(M_NAME): $(OBJS) $(OBUTILS)
	$(CC) $(CFLAGS) $(OBUTILS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(M_NAME)

bonus: $(LIBFT) $(B_NAME)

$(B_NAME): $(BOBJS) $(OBUTILS)
	$(CC) $(CFLAGS) $(OBUTILS) $(BOBJS) $(LIBFT) $(INCLUDES) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBUTILS) $(BOBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(M_NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
