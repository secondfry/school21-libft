/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:48:25 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/20 19:07:37 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;

	if (!*needle)
		return ((char *)haystack);
	ptr = (char *)haystack;
	while (ptr)
	{
		ptr = ft_strchr(ptr, *needle);
		if (!ptr)
			return ((void *)0);
		if (ft_strncmp(ptr, needle, ft_strlen(needle)) == 0)
			return (ptr);
		ptr++;
	}
	return ((void *)0);
}
