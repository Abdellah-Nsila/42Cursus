#include "get_next_line.h"

char	*ft_appendBuff(char *static_var, char *buff, ssize_t rb)
{
	char	*new_static_var;
	int		len;

	len = static_var ? ft_strlen(static_var) : 0;
	new_static_var = (char *)malloc((len + rb + 1) * sizeof(char));
	if (!new_static_var)
	{
		free(static_var); // Prevent leak if allocation fails.
		return (NULL);
	}
	if (static_var)
	{
		ft_strlcpy(new_static_var, static_var, len + 1);
		free(static_var);
	}
	ft_strlcat(new_static_var, buff, len + rb + 1);
	return (new_static_var);
}


char	*ft_getRemaining(char *static_var, char *endline)
{
	char	*new_static_var;
	size_t	remaining_len;

	remaining_len = ft_strlen(endline + 1);
	new_static_var = (char *)malloc((remaining_len + 1) * sizeof(char));
	if (!new_static_var)
	{
		free(static_var); // Prevent leak if allocation fails.
		return (NULL);
	}
	ft_strlcpy(new_static_var, endline + 1, remaining_len + 1);
	free(static_var);
	return (new_static_var);
}



char	*getLine(char *static_var, char *endline)
{
	size_t	len;
	char	*line;

	if (!static_var || !endline)
		return (NULL);
	len = (endline - static_var) + 1;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_var, len + 1);
	return (line);
}


// char	*get_next_line(int fd)
// {
// 	static char	*static_var;
// 	ssize_t		rb;
// 	char		buff[BUFFER_SIZE + 1];
// 	char		*endline;
// 	char		*line;
// 	int			count;

// 	count = 0;
// 	while (1)
// 	{
// 		rb = read(fd, buff, BUFFER_SIZE);
// 		if (rb < 0)
// 			return (NULL);
// 		else if (rb == 0)
// 			break;
// 		//TODO Fix Multiple line on one read
// 		count++;
// 		buff[rb] = '\0';
// 		static_var = ft_appendBuff(static_var, buff, rb);
// 		if (!static_var)
// 			return (NULL);
// 		printf("\n[Read Number %d]\n%s\n", count, static_var);

// 		endline = ft_strchr(static_var, '\n');
// 		if (endline)
// 		{
// 			line = getLine(static_var, endline);
// 			static_var = ft_getRemaining(static_var, endline);
// 			if (!line)
// 			{
// 				free(line);
// 				break;
// 			}
// 			printf("\n[Remaining]:\n%s\n", static_var);
// 			return (line);
// 		}
// 		// printf("\n=============== END ================\n\n\n");
// 	}
// 	if (static_var && *static_var)
// 	{
// 		line = ft_strdup(static_var);
// 		free(static_var);
// 		static_var = NULL;
// 		return (line);
// 	}
// 	free(static_var);
// 	static_var = NULL;
// 	return (NULL);
// }



char	*process_line(char **static_var, char *endline)
{
	char	*line;

	line = getLine(*static_var, endline);
	*static_var = ft_getRemaining(*static_var, endline);
	if (!line)
	{
		free(*static_var);
		*static_var = NULL;
	}
	return (line);
}

char	*handle_remainder(char **static_var)
{
	char	*line;
	char	*endline;

	if (!static_var || !*static_var || !**static_var)
	{
		free(*static_var);
		*static_var = NULL;
		return (NULL);
	}
	endline = ft_strchr(*static_var, '\n');
	if (endline)
	{
		line = getLine(*static_var, endline);
		*static_var = ft_getRemaining(*static_var, endline);
		if (!line || !*static_var)
		{
			free(*static_var);
			*static_var = NULL;
		}
		return (line);
	}
	line = ft_strdup(*static_var);
	free(*static_var);
	*static_var = NULL;
	return (line);
}



char	*get_next_line(int fd)
{
	static char	*static_var;
	ssize_t		rb;
	char		buff[BUFFER_SIZE + 1];
	char		*endline;

	while (1)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb < 0 || (rb == 0 && (!static_var || !*static_var)))
			return (handle_remainder(&static_var));
		if (rb == 0)
			break;
		buff[rb] = '\0';
		static_var = ft_appendBuff(static_var, buff, rb);
		if (!static_var)
			return (NULL);
		endline = ft_strchr(static_var, '\n');
		if (endline)
			return (process_line(&static_var, endline));
	}
	return (handle_remainder(&static_var));
}



int main()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("Error...\n");

	// 1 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");

	// 2 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");

	// 3 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");


	// 4 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");


	// 5 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");


	// 6 Call
	line = get_next_line(fd);
	if (line)
		printf("\n\033[0;32m[Line]:\n%s\033[0m", line);
	else
		printf("Error in get next line...\n");
	free(line);
	printf("\n=============== END ================\n\n\n\n");

	close(fd);
}