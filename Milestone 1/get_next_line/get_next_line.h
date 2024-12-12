#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 999999999

char	*get_next_line(int fd);

size_t	ft_strlen(char	*s);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char    *ft_strdup(const char *s1);

char	*ft_clean(char **static_var);
char	*ft_append_buff(char **static_var, char *buff, ssize_t rb);
char	*ft_get_remaining(char **static_var, char *buff, char *end_line);
char	*ft_get_line(char *static_var, char *end_line);
char	*ft_process_read_content(char **static_var, char *buff, char *end_line);
char	*ft_handle_end_of_read(char **static_var, ssize_t rb);

#endif