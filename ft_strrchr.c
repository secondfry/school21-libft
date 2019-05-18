/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:52:55 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/20 18:44:36 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ret;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	ret = (void *)0;
	ptr = (char *)s;
	while (*ptr)
	{
		ptr = ft_memchr(ptr, c, ft_strlen(ptr) + 1);
		if (!ptr)
			return (ret);
		ret = ptr;
		ptr++;
	}
	if (ret)
		return (ret);
	return ((void *)0);
}
