/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:52:39 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/01 22:38:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	head = NULL;
// 	node1 = ft_lstnew((void *)"First Node");
// 	node2 = ft_lstnew((void *)"Second Node");
// 	node3 = ft_lstnew((void *)"Third Node");
// 	ft_lstadd_front(&head, node3);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node1);
// 	printf("Head content: %s\n", (char *)head->content);
// 	printf("Len of linked list: %d\n", ft_lstsize(head));
// 	return (1);
// }
