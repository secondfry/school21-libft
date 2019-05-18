/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:50:25 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/05/18 13:16:37 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*find_end(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		while (*str && !ft_isspace(*str))
			str++;
		ret = str;
		while (ft_isspace(*str))
			str++;
	}
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*ret;
	size_t	len;

	if (!s)
		return ((void *)0);
	while (ft_isspace(*s))
		s++;
	start = (char *)s;
	end = find_end(start);
	len = end - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return ((void *)0);
	ft_strncpy(ret, start, len);
	ret[len] = 0;
	return (ret);
}
