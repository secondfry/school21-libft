/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:38:06 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 20:07:42 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	cpy_len = src_len;
	if (dst_len >= size)
		return (size + src_len);
	dst += dst_len;
	size -= dst_len;
	if (cpy_len >= size)
		cpy_len = size - 1;
	ft_memcpy(dst, src, cpy_len);
	dst[cpy_len] = 0;
	return (dst_len + src_len);
}
