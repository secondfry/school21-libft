/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:23:49 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:42:03 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	cleanup(void *content, size_t len)
{
	len = 0;
	ft_memdel((void **)&content);
}

static char	check(t_list **lst, t_list *elem)
{
	if (!elem)
	{
		ft_lstdel(lst, &cleanup);
		return (0);
	}
	return (1);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*prev;
	t_list	*tmp;

	ret = (void *)0;
	prev = (void *)0;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (!check(&ret, tmp))
			return ((void *)0);
		tmp = f(tmp);
		if (!check(&ret, tmp))
			return ((void *)0);
		if (!ret)
			ret = tmp;
		if (prev)
			prev->next = tmp;
		lst = lst->next;
		prev = tmp;
	}
	return (ret);
}
