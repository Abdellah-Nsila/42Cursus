#include "get_next_line.h"

char	*ft_appendBuff(char *static_var, char *buff, ssize_t rb)
{
	char	*new_static_var;
	int		len;

	if (!static_var)
		len = 0;
	else
		len = ft_strlen(static_var);
	new_static_var = (char *) malloc((len + rb + 1) * sizeof(char));
	if (!new_static_var)
		return (NULL);
	if (static_var)
		ft_strlcpy(new_static_var, static_var, len + 1);
	ft_strlcat(new_static_var, buff, len + rb + 1);
	free(static_var);
	return (new_static_var);
}

char	*ft_getRemaining(char *static_var, char *endline)
{
	printf("[Line len] %d\n\n", ft_strlen(static_var) - ft_strlen(endline));
	printf("[EndLine]:%s\n", endline);
	char	*new_static_var;
	int		i;

	new_static_var = (char *) malloc((ft_strlen(endline) - 1) * sizeof(char));
	if (!new_static_var)
		return (NULL);
	i = 0;
	while (i < ft_strlen(endline))
	{
		//printf("%c", endline[i]);
		new_static_var[i] = endline[i + 1];
		i++;
	}
	free(static_var);
	return (new_static_var);
}

char	*getLine(char *static_var, char *endline)
{
	size_t	len;
	char	*line;
	size_t	i;

	len = ft_strlen(static_var) - ft_strlen(endline) + 1;
	line = (char *) malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		line[i] = static_var[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_var;
	ssize_t		rb;
	char		buff[BUFFER_SIZE + 1];
	char		*endline;
	char		*line;
	int			count;

	count = 0;
	while (rb = read(fd, buff, BUFFER_SIZE))
	{
		count++;
		buff[rb] = '\0';
		static_var = ft_appendBuff(static_var, buff, rb);
		if (!static_var)
			return (NULL);
		printf("[Read %d]\n%s\n\n", count, static_var);

		endline = ft_strchr(static_var, '\n');
		if (endline)
		{
			line = getLine(static_var, endline);
			static_var = ft_getRemaining(static_var, endline);
			printf("[Remaining] %s\n", static_var);
			return (line);
		}
		// printf("\n=============== END ================\n\n\n");
	}
	if (static_var && *static_var)
	{
		printf("[Line] %s\n", static_var);
		printf("[Line len] %d\n\n", ft_strlen(static_var));
		printf("%d\n", rb);
	}
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
		printf("[Line]:%s\n", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n");
}