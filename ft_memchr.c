/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:56:22 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:48:54 by oadhesiv         ###   ########.fr       */
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

static void		*align_pointer(const void **b, t_byte c, size_t *len)
{
	t_byte	*dest;

	dest = (t_byte*)*b;
	while ((t_ulong)dest % DATA_MODEL_LONG_WIDTH != 0 && *len)
	{
		if (*dest == c)
			return (dest);
		dest++;
		*len -= 1;
	}
	*b = (void*)dest;
	return ((void *)0);
}

static void		*check_bytes(t_byte *data, t_byte c, t_byte len)
{
	if (len > 0 && *(data + 0) == c)
		return ((void *)(data + 0));
	if (len > 1 && *(data + 1) == c)
		return ((void *)(data + 1));
	if (len > 2 && *(data + 2) == c)
		return ((void *)(data + 2));
	if (len > 3 && *(data + 3) == c)
		return ((void *)(data + 3));
	if (len > 4 && *(data + 4) == c)
		return ((void *)(data + 4));
	if (len > 5 && *(data + 5) == c)
		return ((void *)(data + 5));
	if (len > 6 && *(data + 6) == c)
		return ((void *)(data + 6));
	if (len > 7 && *(data + 7) == c)
		return ((void *)(data + 7));
	return ((void *)0);
}

static void		*check_ulong(t_ulong *data, t_byte c)
{
	t_ulong	cell;
	t_ulong	cell_one;
	t_ulong	cell_eighties;
	t_ulong temp;
	void	*ptr;

	cell = make_memory_cell(c);
	cell_one = make_memory_cell(0x01);
	cell_eighties = make_memory_cell(0x80);
	temp = *data ^ cell;
	if (((temp - cell_one) & ~temp & cell_eighties) != 0)
	{
		ptr = check_bytes((t_byte *)data, c, 8);
		if (ptr)
			return (ptr);
	}
	return ((void *)0);
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	void	*ret;
	t_ulong	*str_ulong;
	t_byte	c_byte;

	if (!s || !n)
		return ((void *)0);
	c_byte = (t_byte)c;
	ret = align_pointer(&s, c_byte, &n);
	if (ret)
		return (ret);
	str_ulong = (t_ulong *)s;
	while (n > DATA_MODEL_LONG_WIDTH)
	{
		ret = check_ulong(str_ulong, c_byte);
		if (ret)
			return (ret);
		str_ulong++;
		n -= DATA_MODEL_LONG_WIDTH;
	}
	ret = check_bytes((t_byte *)str_ulong, c_byte, n);
	if (ret)
		return (ret);
	return ((void *)0);
}
