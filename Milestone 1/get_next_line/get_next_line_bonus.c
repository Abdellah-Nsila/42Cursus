/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:39:38 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/05 11:47:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_append_buff(char **static_var, char *buff, ssize_t rb)
{
	char	*new_static_var;
	int		len;

	if (*static_var)
		len = ft_strlen(*static_var);
	else
		len = 0;
	new_static_var = (char *)malloc((len + rb + 1) * sizeof(char));
	if (!new_static_var)
		return (ft_clean(static_var));
	if (static_var)
	{
		ft_strlcpy(new_static_var, *static_var, len + 1);
		ft_clean(static_var);
	}
	ft_strlcat(new_static_var, buff, len + rb + 1);
	return (new_static_var);
}

char	*ft_get_line(char **static_var, char *end_line)
{
	char	*line;
	size_t	len;
	char	*new_static_var;
	size_t	remaining_len;

	len = (end_line - *static_var) + 1;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (_ft_clean(static_var));
	_ft_strlcpy(line, *static_var, len + 1);
	if (*(end_line + 1))
	{
		remaining_len = _ft_strlen(end_line + 1);
		new_static_var = (char *)malloc((remaining_len + 1) * sizeof(char));
		if (!new_static_var)
			return (_ft_clean(static_var));
		_ft_strlcpy(new_static_var, end_line + 1, remaining_len + 1);
		_ft_clean(static_var);
		*static_var = new_static_var;
	}
	else
		_ft_clean(static_var);
	return (line);
}

char	*ft_handle_end_of_read(char **static_var, char *buff, ssize_t rb)
{
	char	*end_line;
	char	*line;
	size_t	len;

	free(buff);
	if (rb < 0 || !static_var || !*static_var)
		return (ft_clean(static_var));
	end_line = ft_strchr(*static_var, '\n');
	if (end_line)
		return (ft_get_line(static_var, end_line));
	if (**static_var)
	{
		len = ft_strlen(*static_var) + 1;
		line = (char *) malloc(len * sizeof(char));
		if (!line)
			return (ft_clean(static_var), NULL);
		ft_strlcpy(line, *static_var, len);
		ft_clean(static_var);
		return (line);
	}
	return (ft_clean(static_var));
}

char	*get_next_line(int fd)
{
	static char	*static_var[MAX_FD];
	ssize_t		rb;
	char		*buff;
	char		*end_line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rb = read(fd, buff, BUFFER_SIZE);
	while (rb > 0)
	{
		buff[rb] = '\0';
		static_var[fd] = ft_append_buff(&static_var[fd], buff, rb);
		if (!static_var[fd])
			return (free(buff), NULL);
		end_line = ft_strchr(static_var[fd], '\n');
		if (end_line)
			return (free(buff), ft_get_line(&static_var[fd], end_line));
		rb = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_handle_end_of_read(&static_var[fd], buff, rb));
}
