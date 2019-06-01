/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:28:13 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 22:35:22 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return ((void *)0);
	if (len + 1 == 0)
		return ((void *)0);
	ret = ft_strnew(len + 1);
	if (!ret)
		return ((void *)0);
	ft_strncpy(ret, s + start, len);
	ret[len] = 0;
	return (ret);
}
