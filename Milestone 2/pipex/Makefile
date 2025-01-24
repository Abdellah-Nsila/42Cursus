M_NAME = pipex
# B_NAME = 
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	./src/pipex.c ./src/parsing_file.c ./src/parsing_path.c \
		./src/pipex_execution.c ./src/parsing_commands.c ./src/struct_utils.c \
		./src/here_doc.c ./src/pipex_cleanup.c ./src/pipex_error.c \
		./src/debug.c \

# BSRCS = ./src/

OBJS = $(SRCS:.c=.o)
# BOBJS = $(BSRCS:.c=.o)

all: $(LIBFT) $(M_NAME)

$(M_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(M_NAME)

# bonus: $(LIBFT) $(B_NAME)

# $(B_NAME): $(BOBJS)
# 	$(CC) $(CFLAGS) $(BOBJS) $(LIBFT) $(INCLUDES) -o $(B_NAME)

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
