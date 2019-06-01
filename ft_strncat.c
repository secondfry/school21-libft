/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:33:01 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:53:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	copy_len;
	char	*ret;

	if (!s1 || !s2 || !n)
		return (s1);
	ret = s1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len > n)
		copy_len = n;
	else
		copy_len = s2_len;
	s1 += s1_len;
	ft_memcpy(s1, s2, copy_len);
	*(s1 + copy_len) = 0;
	return (ret);
}
