NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

UTILS = ./utils/parsing_file.c ./utils/parsing_path.c    \
		./utils/pipex_execution.c ./utils/struct_utils.c \
		./utils/here_doc.c ./utils/parsing_commands.c    \
		./utils/pipex_cleanup.c ./utils/pipex_error.c    \

SRCS =	./src/pipex.c

OBUTILS = $(UTILS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(OBUTILS)
	$(CC) $(CFLAGS) $(OBUTILS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBUTILS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
