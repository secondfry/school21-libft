/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:13:33 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/05/18 14:34:28 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	del(tmp->content, tmp->content_size);
	free(tmp);
	*alst = (void *)0;
}
