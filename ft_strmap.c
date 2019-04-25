/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:50 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/25 17:24:04 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	if (!s || !f)
		return ((void *)0);
	ret = ft_strdup(s);
	if (!ret)
		return ((void *)0);
	i = 0;
	while (ret[i])
	{
		ret[i] = f(ret[i]);
		i++;
	}
	return (ret);
}
