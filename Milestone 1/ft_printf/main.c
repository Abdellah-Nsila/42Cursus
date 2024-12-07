/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:27:30 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/07 16:58:40 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	put_it(int a, int b)
{
	printf("Return values: ft_printf = %d, printf = %d\n\n", a, b);
}

int	main(void)
{
	int	ret_orig;
	int	ret_ft;

	ret_orig = printf("Test 1.1: Char: %p\n", NULL);
	ret_ft = ft_printf("Test 1.2: Char: %p\n", NULL);
	put_it(ret_ft, ret_orig);
	ret_orig = printf(NULL, 42);
	ret_ft = ft_printf(NULL, 42);
	put_it(ret_ft, ret_orig);
	ret_orig = printf("Test 3.1: Char: %p\n");
	ret_ft = ft_printf("Test 3.2: Char: %p\n");
	put_it(ret_ft, ret_orig);
	ret_orig = printf("%s %d\n", NULL, 1337);
	ret_ft = ft_printf("%s %d\n", NULL, 1337);
	put_it(ret_ft, ret_orig);
	return (0);
}
