/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:14:59 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/27 09:49:45 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_adr_info
{
	void	*adr;
	int		tag;
	void	(*del)(void *);
}			t_adr_info;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif