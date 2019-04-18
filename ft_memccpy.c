/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:28:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/18 17:16:03 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	copy_len;

	ptr = ft_memchr(src, c, n);
	if (ptr != (void*)0)
	{
		copy_len = ptr - src + 1;
		ft_memcpy(dst, src, copy_len);
		return (dst + copy_len);
	}
	ft_memcpy(dst, src, n);
	return ((void*)0);
}
