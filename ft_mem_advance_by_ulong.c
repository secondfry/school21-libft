/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_advance_by_ulong.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:27:46 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/17 17:26:45 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_mem_advance_by_ulong(void **b, t_ulong cell, size_t len)
{
	t_ulong *dest;
	size_t  ops;

	dest = (t_ulong*)*b;
	ops = len / DATA_MODEL_LONG_WIDTH;
	while (ops--)
	{
		*dest = cell;
		dest += 1;
		len -= DATA_MODEL_LONG_WIDTH;
	}
	*b = (void*)dest;
	return (len);
}
