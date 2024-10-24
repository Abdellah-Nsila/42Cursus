/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:16 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/24 16:54:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return ((s1[i] - s2[i]));
}


#include <stdio.h> 
#include <string.h>  
int main() 
{  
   char str_1[] = "java";  
   char str_2[] = "java";      
   if (strncmp(str_1, str_2, 4) == 0)
   {  
      printf("The strings '%s' and '%s' are equal.\n", str_1, str_2);  
   }  
   else 
   {  
      printf("The strings '%s' and '%s' are not equal.\n", str_1, str_2);  
   }  
   return 0;  
}  
