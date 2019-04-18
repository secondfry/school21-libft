/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:56:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/18 17:11:51 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_byte	check_long(const t_ulong *hay, t_byte needle)
{
	t_byte	*hay_byte;
	t_byte	i;

	hay_byte = (t_byte*)hay;
	i = 0;
	while (i < DATA_MODEL_LONG_WIDTH)
	{
		if (hay_byte[i] == needle)
			return (0);
		++i;
	}
	return (1);
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	t_ulong	*str_ulong;
	t_byte	*str_byte;

	str_ulong = (t_ulong *)s;
	while (n > DATA_MODEL_LONG_WIDTH && check_long(str_ulong, (t_byte)c))
	{
		++str_ulong;
		n -= DATA_MODEL_LONG_WIDTH;
	}
	str_byte = (t_byte *)str_ulong;
	while (n--)
		if (*str_byte++ == (t_byte)c)
			return (--str_byte);
	return (NULL);
}
