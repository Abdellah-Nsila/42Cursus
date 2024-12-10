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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (i < n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, n);
	return (dst);
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

char	*ft_strndup(const char *s1, int n)
{
	char	*dst;
	size_t	src_len;

	if (!s1)
		return (NULL);
	src_len = ft_strlen((char *)s1);
	if (n > (int)src_len)
		n = src_len;
	dst = (char *)malloc(n + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, n + 1);
	return (dst);
}

static char	*ft_appendBuff(char *static_var, char *buf, ssize_t rb)
{
	char	*new_static_var;
	size_t	len;

	if (!static_var)
		len = 0;
	else
		len = ft_strlen(static_var);
	new_static_var = (char *)malloc(len + rb + 1);
	if (!new_static_var)
		return (NULL);
	if (static_var)
		ft_strlcpy(new_static_var, static_var, len + 1);
	ft_strlcat(new_static_var, buf, len + rb + 1);
	free(static_var); 
	return (new_static_var);
}


char	*get_next_line(int fd)
{
	static char	*static_var;
	ssize_t		rb;
	char		buf[BUFFER_SIZE + 1];
	char		*endline;
	int			line_len;
	char		*line;

	while ((rb = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rb] = '\0';
		static_var = ft_appendBuff(static_var, buf, rb);
		if (!static_var)
			return (NULL);
		endline = ft_strchr(static_var, '\n');
		if (endline)
		{
			line_len = endline - static_var + 1;
			line = ft_strndup(static_var, line_len);
			ft_memmove(static_var, endline + 1, ft_strlen(endline + 1) + 1);
			return (line);
		}
	}
	if (static_var && *static_var)
	{
		line = ft_strndup(static_var, ft_strlen(static_var));
		free(static_var);
		static_var = NULL;
		return (line);
	}
	free(static_var);
	static_var = NULL;
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
	free(line);

	// Second Call
	line = get_next_line(fd);
	if (line)
		printf("line: %s\n", line);
	else
		printf("Error in get next line...\n");
	free(line);


	// Third Call
	line = get_next_line(fd);
	if (line)
		printf("line: %s\n", line);
	else
		printf("Error in get next line...\n");
	free(line);
	
}