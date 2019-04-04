/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:42 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/04 19:40:41 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_byte;
	const unsigned char	*s2_byte;

	s1_byte = (const unsigned char *)s1;
	s2_byte = (const unsigned char *)s2;
	while (n--)
		if (*s1_byte++ != *s2_byte++)
			return (*--s1_byte - *--s2_byte);
	return (0);
}
