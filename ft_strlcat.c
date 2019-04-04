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

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	// dst += dst_len;
	// ft_memcpy()
	// i = 0;
	// q = 0;
	// while (*dst++)
	// 	i++;
	// dst--;
	// while (*src && i + q < size)
	// 	*dst++ = *src++;
	
	// dst_len = ft_strlen(dst);
	// src_len = ft_strlen(src);
	// if (dst_len > size)
	// 	return (dst_len + src_len);
	// copy_len = size - dst_len;
	// ft_strncpy(dst, src, copy_len);
	return (dst_len + src_len + size - size);
}
