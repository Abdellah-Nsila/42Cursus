/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:45:47 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/03 16:05:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
	{
		lst = &(*lst)->next;
	}
	(*lst)->next = new;
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;

// 	head = NULL;
// 	node1 = ft_lstnew((void *)"First Node");
// 	node2 = ft_lstnew((void *)"Second Node");
// 	node3 = ft_lstnew((void *)"Third Node");
// 	node4 = ft_lstnew((void *)"The End");
// 	ft_lstadd_front(&head, node3);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node1);
// 	printf("Last Node content: %s\n", (char *)ft_lstlast(head)->content);
// 	printf("Len of linked list: %d\n\n", ft_lstsize(head));
// 	ft_lstadd_back(&head, node4);
// 	printf("Last Node content: %s\n", (char *)ft_lstlast(head)->content);
// 	printf("Len of linked list: %d\n\n", ft_lstsize(head));
// 	return (1);
// }

// int	main(void)
// {
//     t_list	*head;
//     t_list	*node1;
//     t_list	*node2;
//     t_list	*node3;
//     t_list	*node4;

//     head = NULL;
//     node1 = ft_lstnew((void *)"First Node");
//     node2 = ft_lstnew((void *)"Second Node");
//     node3 = ft_lstnew((void *)"Third Node");
//     node4 = ft_lstnew((void *)"The End");

//     ft_lstadd_back(&head, node1);
//     ft_lstadd_back(&head, node2);
//     ft_lstadd_back(&head, node3);
//     ft_lstadd_back(&head, node4);

//     // Print the list to verify
//     t_list *current = head;
//     while (current)
//     {
//         printf("%s -> ", (char *)current->content);
//         current = current->next;
//     }
//     printf("NULL\n");

//     return (0);
// }