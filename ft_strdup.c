/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:15:47 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/23 16:26:29 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ret = ft_strnew(len);
	if (!ret)
		return ((void *)0);
	ft_memcpy(ret, s1, len);
	return (ret);
}
