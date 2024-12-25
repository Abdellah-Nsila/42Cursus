# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a

# Source files
SRCS = commands.c \
       handle_inputs.c \
       handle_calculation_move.c \
       get_position.c \
       push_swap_utils.c \
       push_swap.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = push_swap

# Include header files
INCLUDES = -I.

# Debug flag (for development)
DEBUG_FLAGS = -g

# Default rule
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to include the libft library
$(LIBFT):
	make -C Libft

# Clean object files
clean:
	rm -f $(OBJS)
	make clean -C Libft

# Clean everything including the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C Libft

# Rebuild the project
re: fclean all

# Debug mode for development
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re
