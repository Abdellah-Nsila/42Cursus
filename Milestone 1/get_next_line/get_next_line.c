#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search_str;
	size_t			i;

	search_str = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == search_str)
			return ((char *)(&str[i]));
		i++;
	}
	if (search_str == '\0')
		return ((char *)(&str[i]));
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (!dst && !src && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (((dst_len + i) < (dstsize - 1)) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

char	*ft_extractLine(char *s)
{
	char	*endline;
	char	*line;
	int		len;

	endline = ft_strchr(s, '\n');
	printf("end line addr: %s\n", endline);
	len = 0;
	if (endline)
	{
		while (s && s[len] != '\n')
			len++;
		line = (char *) malloc((len + 1) * sizeof(char));
		if (!line)
			return (NULL);
		len = 0;
		while (s && s[len] != '\n')
		{
			line[len] = s[len];
			len++;
		}
		line[len] = '\n';
		return (line);
	}
	return ("\n");
}

char	*ft_handleNextBuf(char *s, char buf[BUFFER_SIZE])
{
	char	*temp;

	temp = (char *) malloc((ft_strlen(s) + ft_strlen(buf)) * sizeof(char));
	if (!temp)
		return (NULL);
	if (s)
		ft_strlcat(temp, s, ft_strlen(s));
	ft_strlcat(temp, buf, ft_strlen(buf));
	s = temp;
	return (s);
}

static char	*ft_appendBuff(char *static_var, char *buf, ssize_t rb)
{
	char	*new_static_var;
	size_t	len;

    if (!static_var)
        len = 0;
    else
        len = ft_strlen(static_var);
	new_static_var = (char *) malloc((len + rb + 1) * sizeof(char));
	if (!new_static_var)
		return (NULL);
	if (static_var)
        ft_strlcpy(new_static_var, static_var, len);
    ft_strlcat(new_static_var, buf, rb);

    free(static_var);
    return (new_static_var);

}

char	*get_next_line(int fd)
{
	static char	*static_var;
	ssize_t		rb;
	int			i;
	char 		buf[BUFFER_SIZE];
	int		line_len;
	char	*line;

	while (rb = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[rb] = '\0';
		static_var = ft_appendBuff(static_var, buf, rb);
		line = ft_strchr(static_var, '\n');
		if (line)
		{
			line_len = static_var - line + 1;
			line = strndup(static_var, line_len);
		}

	}
	return (NULL);
}

int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error...\n");
	
	// First Call
	line = get_next_line(fd);
	if (line)
		printf("line: %s\n", line);
	else
		printf("Error in get next line...\n");

	// Second Call
	line = get_next_line(fd);
	if (line)
		printf("line: %s\n", line);
	else
		printf("Error in get next line...\n");
}