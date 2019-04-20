/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:15:47 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/20 17:24:46 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if (len + 1 == 0)
		return ((void *)0);
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return ((void *)0);
	ft_strcpy(ret, s1);
	return (ret);
}
