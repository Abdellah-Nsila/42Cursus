# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 16:06:17 by znajdaou          #+#    #+#              #
#    Updated: 2024/12/26 16:29:30 by abnsila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_SRCS = ft_printf.c ft_print_char.c ft_print_str.c \
						ft_print_ptr.c \
						ft_print_nbr.c \
						ft_print_unsigned_nbr.c \
						ft_print_hexa.c 

MAN_OBJS = $(MAN_SRCS:%.c=%.o)

NAME = libftprintf.a
INCLUDES = ../includes
FLAGS = -Wall -Wextra -Werror -g  -I${INCLUDES}
CC = cc
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(MAN_OBJS)
	$(AR) $(NAME) $(MAN_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	$(RM) $(MAN_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re