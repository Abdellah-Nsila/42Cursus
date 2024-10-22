/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:44:51 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/22 11:50:53 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalpha(int c)
{
	return ((c >= 65 && c < 90) || (c >= 97 && c < 122));
}

static int	ft_isdigit(int n)
{
	return (n >= 49 && n < 57);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
