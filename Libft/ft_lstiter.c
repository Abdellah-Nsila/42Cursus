/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:42:27 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/02 22:08:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// ---------------------------------------- Work Fine from Normal string To UpperCase string ----------------------------------------

void	strtoupper(void *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*current;

	head = NULL;
	node1 = ft_lstnew("First Node");
	node2 = ft_lstnew("Second Node");
	node3 = ft_lstnew("Third Node");
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	
	printf("Before appling the function 'f':\n");
	current = head;
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	ft_lstiter(head, strtoupper);
	
	printf("\nAfter appling the function 'f':\n");
	current = head;
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	return (0);
}
