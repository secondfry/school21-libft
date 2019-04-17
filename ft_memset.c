/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:49:01 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/17 17:24:11 by oadhesiv         ###   ########.fr       */
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
		*dest = (t_byte)c;
		dest += 1;
		*len -= 1;
	}
	*b = (void*)dest;
}

void	*ft_memset(void *b, int c, size_t len)
{
	t_ulong	cell;
	t_ulong	*dest;
	t_byte	*dest_byte;
	void	*ret;

	if (!b || !len)
	{
		return (0);
	}
	ret = b;
	cell = make_memory_cell(c);
	align_pointer(&b, c, &len);
	dest = (t_ulong*)b;
	len = ft_mem_advance_by_eight_ulongs((void**)&dest, cell, len);
	len = ft_mem_advance_by_ulong((void**)&dest, cell, len);
	dest_byte = (t_byte*)dest;
	while (len--)
		*dest_byte++ = (t_byte)c;
	return (ret);
}
