SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_isnumber.c
SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

DIR_PRINTF = ./ft_printf
NAME_FT_PRINTF = libftprintf.a
OBJS_FT_PRINTF= ${DIR_PRINTF}/ft_printf.o \
						${DIR_PRINTF}/ft_print_char.o \
						${DIR_PRINTF}/ft_print_str.o \
						${DIR_PRINTF}/ft_print_ptr.o \
						${DIR_PRINTF}/ft_print_nbr.o \
						${DIR_PRINTF}/ft_print_unsigned_nbr.o \
						${DIR_PRINTF}/ft_print_hexa.o

DIR_GET_NEXT_LINE = ./get_next_line
NAME_GET_NEXT_LINE = get_next_line.a
OBJS_GET_NEXT_LINE = ${DIR_GET_NEXT_LINE}/get_next_line.o \
									${DIR_GET_NEXT_LINE}/get_next_line_utils.o

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
INCLUDES = ./includes
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g  -I$(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJS) printf get_next_line
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	cc $(CFLAGS) -c $(SRCS)

bonus : $(OBJSB)clean:
	${RM} ${MOBJS} ${BOBJS}
	make -C ${FT_PRINTF} clean
	make -C ${GET_NEXT_LINE} clean

fclean: clean
	${RM} ${NAME}
	make -C ${FT_PRINTF} fclean
	make -C ${GET_NEXT_LINE} fclean

re: fclean all

.PHONY : all clean fclean re bonus printf mandaory get_next_line

$(OBJSB) : $(SRCSB)
	cc $(CFLAGS) -c $(SRCSB)
	ar rcs $(NAME) $(OBJSB)

printf:
	$(CC) $(CFLAGS) -c ${DIR_PRINTF}/*.c
	$(LIBC) $(NAME) $(OBJS_PRINTF)

get_next_line:
	$(CC) $(CFLAGS) -c ${DIR_GET_NEXT_LINE}/*.c
	$(LIBC) $(NAME) $(OBJS_GET_NEXT_LINE)

clean:
	${RM} ${OBJS} ${OBJSB}
	make -C ${DIR_PRINTF} clean
	make -C ${DIR_GET_NEXT_LINE} clean

fclean: clean
	${RM} ${NAME}
	make -C ${DIR_PRINTF} fclean
	make -C ${DIR_GET_NEXT_LINE} fclean

re: fclean all

.PHONY : all clean fclean re bonus printf mandaory get_next_line
