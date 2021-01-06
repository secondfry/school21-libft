/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:11:17 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:00:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ulong	make_memory_cell(int c)
{
	t_ulong	ret;
	t_byte	i;

	ret = (t_byte)c;
	i = 1;
	while (i < sizeof(long))
		ret |= ret << 8 * i++;
	return (ret);
}

static void		*align_pointer(const char **b)
{
	t_byte	*dest;

	dest = (t_byte*)*b;
	while ((t_ulong)dest % sizeof(long) != 0)
	{
		if (*dest == 0)
			return (dest);
		dest++;
	}
	*b = (void*)dest;
	return ((void *)0);
}

static void		*check_bytes(t_byte *data)
{
	if (*(data + 0) == 0)
		return ((void *)(data + 0));
	if (*(data + 1) == 0)
		return ((void *)(data + 1));
	if (*(data + 2) == 0)
		return ((void *)(data + 2));
	if (*(data + 3) == 0)
		return ((void *)(data + 3));
	if (*(data + 4) == 0)
		return ((void *)(data + 4));
	if (*(data + 5) == 0)
		return ((void *)(data + 5));
	if (*(data + 6) == 0)
		return ((void *)(data + 6));
	if (*(data + 7) == 0)
		return ((void *)(data + 7));
	return ((void *)0);
}

static void		*check_ulong(t_ulong *data)
{
	t_ulong	cell_one;
	t_ulong	cell_eighties;
	void	*ptr;

	cell_one = make_memory_cell(0x01);
	cell_eighties = make_memory_cell(0x80);
	if (((*data - cell_one) & ~*data & cell_eighties) != 0)
	{
		ptr = check_bytes((t_byte *)data);
		if (ptr)
			return (ptr);
	}
	return ((void *)0);
}

size_t			ft_strlen(const char *s)
{
	void	*ret;
	void	*save;
	t_ulong	*str_ulong;

	if (!s)
		return (0);
	save = (void *)s;
	ret = align_pointer(&s);
	if (ret)
		return (ret - save);
	str_ulong = (t_ulong *)s;
	while (1)
	{
		ret = check_ulong(str_ulong);
		if (ret)
			return (ret - save);
		str_ulong++;
	}
	return (0);
}
