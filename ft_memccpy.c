/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:28:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:46:05 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	copy_len;

	if (!dst || !src || !n)
		return ((void *)0);
	ptr = ft_memchr(src, c, n);
	if (ptr)
	{
		copy_len = ptr - src + 1;
		ft_memcpy(dst, src, copy_len);
		return (dst + copy_len);
	}
	ft_memcpy(dst, src, n);
	return ((void*)0);
}
