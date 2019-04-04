/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:33:29 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 18:55:14 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	dst_byte = ((unsigned char *)dst) + len;
	src_byte = ((const unsigned char *)src) + len;
	while (len--)
		*--dst_byte = *--src_byte;
	return (dst);
}
