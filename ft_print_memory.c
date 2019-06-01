/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:56:57 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 16:58:48 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_byte	ft_print_memory_hex(t_byte *data, size_t size)
{
	t_byte	i;
	t_byte	q;

	i = 0;
	while (i < 16 && i < size)
	{
		if (i % 8 == 0 && i != 0)
			ft_putchar(' ');
		ft_putchar("0123456789ABCDEF"[data[i] / 16]);
		ft_putchar("0123456789ABCDEF"[data[i] % 16]);
		ft_putchar(' ');
		i++;
	}
	q = 0;
	while (i + q < 16)
	{
		if ((i + q) % 8 == 0)
			ft_putchar(' ');
		ft_putstr("   ");
		q++;
	}
	return (i);
}

static t_byte	ft_print_memory_data(t_byte *data, size_t size)
{
	t_byte	i;

	i = 0;
	ft_putstr(" |");
	while (i < 16 && i < size)
	{
		if (data[i] > 31 && data[i] < 127)
			ft_putchar(data[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
	return (i);
}

void			ft_print_memory(const void *addr, size_t size)
{
	t_byte	*data;
	t_byte	i;

	i = 0;
	data = (t_byte*)addr;
	while (size)
	{
		ft_print_ptr(data);
		ft_putchar(' ');
		i = ft_print_memory_hex(data, size);
		i = ft_print_memory_data(data, size);
		size -= i;
		data += i;
		ft_putchar('\n');
	}
}
