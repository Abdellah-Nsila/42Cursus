/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:52:39 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/01 18:58:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst && lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

int	main() {
	t_list	*head;
	t_list	*new_node;

	head = NULL;
	ft_lstadd_front(&head, ft_lstnew((void *)"First Node"));
	printf("Head content: %s\n", (char *)head->content);
	printf("Len of linked list: %d\n", ft_lstsize(new_node));
	return (1);
}
