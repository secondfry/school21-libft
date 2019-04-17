/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_advance_by_eight_ulongs.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:27:46 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/17 17:24:34 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_mem_advance_by_eight_ulongs(void **b, t_ulong cell, size_t len)
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
