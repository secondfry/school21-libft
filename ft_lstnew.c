/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:00:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:42:10 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;
	void	*tmp;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return ((void *)0);
	if (!content)
	{
		tmp = (void *)0;
		content_size = 0;
	}
	else
	{
		tmp = (void *)malloc(content_size);
		if (!tmp)
		{
			ft_memdel((void **)&ret);
			return ((void *)0);
		}
		ft_memcpy(tmp, content, content_size);
	}
	ret->content = tmp;
	ret->content_size = content_size;
	ret->next = (void *)0;
	return (ret);
}
