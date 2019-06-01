/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:42:38 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 23:57:33 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	char	*ret;

	if (!s1 || !s2)
		return ((void *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	if (len + 1 < s1_len)
		return ((void *)0);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return ((void *)0);
	ft_strcpy(ret, s1);
	ft_strcpy(ret + s1_len, s2);
	ret[len] = 0;
	return (ret);
}
