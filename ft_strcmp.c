/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:52:36 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:54:09 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	cmp_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2) + 1;
	if (s1_len > s2_len)
		cmp_len = s2_len;
	else
		cmp_len = s1_len;
	return (ft_memcmp(s1, s2, cmp_len));
}
