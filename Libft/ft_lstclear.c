/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:51:16 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/02 18:52:11 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}

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

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	head = NULL;
	node1 = ft_lstnew(strdup("First Node"));
	node2 = ft_lstnew(strdup("Second Node"));
	node3 = ft_lstnew(strdup("Third Node"));
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	printf("Before clearing:\n");
	t_list *current = head;
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	ft_lstclear(&head, del); // Clear the entire list

	printf("After clearing:\n");
	// if (head == NULL)
	// {
	// 	printf("List is empty\n");
	// }
	// else
	// {
		current = head;
		while (current)
		{
			printf("%s -> ", (char *)current->content);
			current = current->next;
		}
		printf("NULL\n");
	// }

	return (0);
}