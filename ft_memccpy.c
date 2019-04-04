/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:28:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 19:01:41 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;

	dst_byte = (unsigned char *)dst;
	src_byte = (const unsigned char *)src;
	while (n--)
	{
		*dst_byte++ = *src_byte++;
		if (*(src_byte - 1) == (unsigned char)c)
			return ((void*)dst_byte);
	}
	return (NULL);
}
