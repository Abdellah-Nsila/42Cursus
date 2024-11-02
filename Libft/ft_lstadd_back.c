/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:45:47 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/02 14:44:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	while (*lst)
	{
		if (!((*lst)->next))
		{
			(*lst)->next = new;
			return ;
		}
		lst = &((*lst)->next);
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	head = NULL;
	node1 = ft_lstnew((void *)"First Node");
	node2 = ft_lstnew((void *)"Second Node");
	node3 = ft_lstnew((void *)"Third Node");
	node4 = ft_lstnew((void *)"The End");
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	printf("Last Node content: %s\n", (char *)ft_lstlast(head)->content);
	printf("Len of linked list: %d\n\n", ft_lstsize(head));
	ft_lstadd_back(&head, node4);
	printf("Last Node content: %s\n", (char *)ft_lstlast(head)->content);
	printf("Len of linked list: %d\n\n", ft_lstsize(head));
	return (1);
}