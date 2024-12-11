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

