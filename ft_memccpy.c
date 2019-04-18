/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:28:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/18 16:14:21 by oadhesiv         ###   ########.fr       */
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

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_ulong			*dst_ulong;
	const t_ulong	*src_ulong;
	t_byte			*dst_byte;
	const t_byte	*src_byte;


	dst_ulong = (t_ulong*)dst;
	src_ulong = (const t_ulong*)src;
	while (n > DATA_MODEL_LONG_WIDTH && check_long(src_ulong, (t_byte)c))
	{
		*dst_ulong++ = *src_ulong++;
		n -= DATA_MODEL_LONG_WIDTH;
	}
	dst_byte = (t_byte*)dst_ulong;
	src_byte = (t_byte*)src_ulong;
	while (n--)
	{
		*dst_byte++ = *src_byte++;
		if (*(src_byte - 1) == (t_byte)c)
			return ((void*)dst_byte);
	}
	return (NULL);
}
