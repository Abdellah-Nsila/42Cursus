NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
INCLUDES = -I./includes -I./Libft/includes
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	$(SRC_DIR)/pipex.c $(SRC_DIR)/parsing_file.c          	\
		$(SRC_DIR)/pipex_execution.c $(SRC_DIR)/parsing_path.c	\
		$(SRC_DIR)/here_doc.c $(SRC_DIR)/parsing_commands.c   	\
		$(SRC_DIR)/pipex_cleanup.c $(SRC_DIR)/struct_utils.c  	\
		$(SRC_DIR)/pipex_error.c              					\

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
