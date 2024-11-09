/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:52:39 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/08 16:06:09 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// #include <stdio.h>

// void	printlst(t_list *lst)
// {
// 	printf("%p\n", lst);
// 	if (lst)
// 	{
// 		while (lst)
// 		{
// 			printf("%s - ", (char *)(lst->content));
// 			lst = lst->next;
// 		}
// 		printf("NULL\n");
// 	}
// }

// int	main()
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	node1 = ft_lstnew("First (1)");
// 	node2 = ft_lstnew("Second (2)");
// 	node3 = ft_lstnew("Third (3)");
	
// 	ft_lstadd_back(&node1, node2);
// 	ft_lstadd_back(&node1, node3);
	
// 	printlst(node1);
// 	printf("Size: %d\n", ft_lstsize(node1));
// }
