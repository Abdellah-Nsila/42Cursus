/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/22 17:04:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *memset(void *ptr, int x, size_t n)
{
    char *p;
    unsigned char c;
    int i;

    i = 0;
    p = ptr;
    c = x;
    while (p[i] && i < n)
    {
        p[i] = c;
        i++;
    };
    return (ptr);
}


#include <stdio.h>
int main()
{
    char str[] = "Hello World";
    memset(str + 1, '#', 3);
    printf("%s", str);
}