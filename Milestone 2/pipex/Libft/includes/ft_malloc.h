/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:12:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/26 12:31:34 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "structs.h"
# include "t_bool.h"

void		*ft_malloc(size_t size, t_list **list, int tag,
				void (*del)(void *));
t_bool		ft_free_tag(t_list **lst, int tag);
t_bool	ft_free_all_tags(t_list **lst);

#endif
