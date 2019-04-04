/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:23:47 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 18:51:17 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;

	dst_byte = (unsigned char *)dst;
	src_byte = (const unsigned char *)src;
	while (n--)
		*dst_byte++ = *src_byte++;
	return (dst);
}
