/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:42 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 19:09:23 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_us;
	const unsigned char	*s2_us;

	s1_us = (const unsigned char *)s1;
	s2_us = (const unsigned char *)s2;
	while (n--)
		if (*s1_us++ != *s2_us++)
			return (*--s1_us - *--s2_us);
	return (0);
}
