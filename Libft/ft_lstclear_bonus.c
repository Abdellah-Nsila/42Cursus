/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:51:16 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/03 16:05:47 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*current;

// 	head = NULL;
// 	node1 = ft_lstnew("First Node");
// 	node2 = ft_lstnew("Second Node");
// 	node3 = ft_lstnew("Third Node");
// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);
// 	printf("Before clearing:\n");
// 	current = head;
// 	while (current)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstclear(&head, del);
// 	printf("After clearing:\n");
// 	if (head == NULL)
// 	{
// 		printf("List is empty\n");
// 	}
// 	else
// 	{
// 		current = head;
// 		while (current)
// 		{
// 			printf("%s -> ", (char *)current->content);
// 			current = current->next;
// 		}
// 		printf("NULL\n");
// 	}
// 	return (0);
// }
