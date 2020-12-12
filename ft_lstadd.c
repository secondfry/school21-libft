/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:20:35 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/05/18 14:22:16 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	if (!alst)
	{
		alst = &elem;
		return ;
	}
	if (!*alst)
	{
		*alst = elem;
		return ;
	}
	elem->next = *alst;
	*alst = elem;
}
