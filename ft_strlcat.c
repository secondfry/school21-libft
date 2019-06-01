/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:38:06 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 16:44:20 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	if (!dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	dst += dst_len;
	size -= dst_len;
	if (src_len >= size)
		cpy_len = size - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dst, src, cpy_len);
	*(dst + cpy_len) = 0;
	return (dst_len + src_len);
}
