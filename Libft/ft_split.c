/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:55:11 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/30 11:29:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freearray(char **arr, int count)
{
	while (count > 0)
	{
		free(arr[count]);
		count--;
	}
	free(arr);
	return (NULL);
}

static int	ft_wordscount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_lethimcook(char **arr, char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	int		count;

	i = 0;
	start = 0;
	end = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		arr[count] = ft_substr(s, start, end - start);
		if (arr[count] == NULL)
			return (ft_freearray(arr, count));
		count++;
	}
	arr[count] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = ft_wordscount(s, c);
	arr = (char **) malloc((words_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_lethimcook(arr, s, c));
}
