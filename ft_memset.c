/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:49:01 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:48:08 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ulong	make_memory_cell(int c)
{
	t_ulong	ret;
	t_byte	i;

	ret = (t_byte)c;
	i = 1;
	while (i < DATA_MODEL_LONG_WIDTH)
		ret |= ret << 8 * i++;
	return (ret);
}

static void		align_pointer(void **b, int c, size_t *len)
{
	t_byte	*dest;

	dest = (t_byte*)*b;
	while ((t_ulong)dest % DATA_MODEL_LONG_WIDTH != 0 && *len > 0)
	{
		*dest++ = (t_byte)c;
		*len -= 1;
	}
	*b = (void*)dest;
}

static size_t	fill_eight_ulongs(void **b, t_ulong cell, size_t len)
{
	t_ulong	*dest;
	size_t	ops;
	size_t	size;

	dest = (t_ulong*)*b;
	size = 8 * DATA_MODEL_LONG_WIDTH;
	ops = len / size;
	while (ops--)
	{
		*dest = cell;
		*(dest + 1) = cell;
		*(dest + 2) = cell;
		*(dest + 3) = cell;
		*(dest + 4) = cell;
		*(dest + 5) = cell;
		*(dest + 6) = cell;
		*(dest + 7) = cell;
		dest += 8;
		len -= size;
	}
	*b = (void*)dest;
	return (len);
}

static size_t	fill_ulong(void **b, t_ulong cell, size_t len)
{
	t_ulong	*dest;
	size_t	ops;

	dest = (t_ulong*)*b;
	ops = len / DATA_MODEL_LONG_WIDTH;
	while (ops--)
	{
		*dest++ = cell;
		len -= DATA_MODEL_LONG_WIDTH;
	}
	*b = (void*)dest;
	return (len);
}

void			*ft_memset(void *b, int c, size_t len)
{
	t_ulong	cell;
	t_ulong	*dest;
	t_byte	*dest_byte;
	void	*ret;

	if (!b || !len)
		return (b);
	ret = b;
	cell = make_memory_cell(c);
	align_pointer(&b, c, &len);
	dest = (t_ulong*)b;
	len = fill_eight_ulongs((void**)&dest, cell, len);
	len = fill_ulong((void**)&dest, cell, len);
	dest_byte = (t_byte*)dest;
	while (len--)
		*dest_byte++ = (t_byte)c;
	return (ret);
}
