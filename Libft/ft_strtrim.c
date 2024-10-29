/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:07:41 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/29 08:47:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkchr(const char *str, int c)
{
	unsigned char	search_str;
	int				i;

	search_str = c;
	i = 0;
	while (str[i])
	{
		if (str[i] == search_str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start_index;
	int		end_index;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (s1[start_index] && ft_checkchr(set, s1[start_index]))
		start_index++;
	end_index = strlen(s1) - 1;
	while (end_index >= start_index && ft_checkchr(set, s1[end_index]))
		end_index--;
	ptr = (char *) malloc((end_index - start_index + 1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start_index + i <= end_index)
	{
		ptr[i] = s1[start_index + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int	main(int ac, char **av)
// {
// 	char	*res;

// 	if (ac != 3)
// 		return (0);
// 	res = ft_strtrim(av[1], av[2]);
// 	printf("\nResult: %s\n\n", res);
// 	free(res);

// 	char *s1 = "ab**Hello World**ba";
// 	char *set = "ab*";
// 	char *trimmed = ft_strtrim(s1, set);
// 	printf("Test 10: %s\n\n", trimmed);  // Expected result: "Hello World"
// 	free(trimmed);

// 	char *s2 = "abcabc";
// 	char *set2 = "abc";
// 	char *trimmed2 = ft_strtrim(s2, set2);
// 	printf("Test 11: %s\n\n", trimmed2);  // Expected result: ""
// 	free(trimmed2);
// }
