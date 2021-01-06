/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:42 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:00:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_ulong	*s1_ulong;
	const t_ulong	*s2_ulong;
	const t_byte	*s1_byte;
	const t_byte	*s2_byte;

	if (!s1 || !s2 || !n)
		return (0);
	s1_ulong = (const t_ulong *)s1;
	s2_ulong = (const t_ulong *)s2;
	while (n > sizeof(long))
	{
		if (*s1_ulong != *s2_ulong)
			break ;
		s1_ulong += 1;
		s2_ulong += 1;
		n -= sizeof(long);
	}
	s1_byte = (const t_byte *)s1_ulong;
	s2_byte = (const t_byte *)s2_ulong;
	while (n--)
		if (*s1_byte++ != *s2_byte++)
			return (*--s1_byte - *--s2_byte);
	return (0);
}
