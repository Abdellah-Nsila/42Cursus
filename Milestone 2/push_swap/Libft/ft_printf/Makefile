# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 16:06:17 by znajdaou          #+#    #+#              #
#    Updated: 2024/12/26 17:01:57 by abnsila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_print_char.c ft_print_str.c \
						ft_print_ptr.c \
						ft_print_nbr.c \
						ft_print_unsigned_nbr.c \
						ft_print_hexa.c 

OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a
INCLUDES = ../includes
FLAGS = -Wall -Wextra -Werror -g  -I${INCLUDES}
CC = cc
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re