/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:55:11 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/29 17:59:17 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// static size_t	_ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// static size_t	_ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	i = 0;
// 	if (src == NULL)
// 		return (0);
// 	src_len = _ft_strlen(src);
// 	if (dstsize == 0 || dst == NULL)
// 		return (src_len);
// 	while (i < dstsize - 1 && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	printf("word: %s\n", dst);
// 	return (src_len);
// }

// static char	*_ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*ptr;
// 	size_t			src_len;
// 	unsigned int	i;

// 	if (s == NULL)
// 		return (NULL);
// 	src_len = _ft_strlen(s);
// 	if (start >= src_len)
// 		len = 0;
// 	ptr = (char *) malloc(len + 1);
// 	if (ptr == NULL)
// 		return (NULL);
// 	_ft_strlcpy(ptr, &s[start], len + 1);
// 	return ((char *)ptr);
// }

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

static void	ft_lethimcook(char **arr, char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	int		count;
	char	*word;

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
		if (end > start)
		{
			word = ft_substr(s, start, end - start);
			arr[count++] = word;
		}
	}
	free(word);
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
	ft_lethimcook(arr, s, c);
	arr[words_count] = NULL;
	return (arr);
}
