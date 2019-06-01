/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:30:31 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 16:42:58 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	char	*tmp;
	size_t	needle_len;

	if (!haystack || !needle || !*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	ptr = (char *)haystack;
	while (ptr && len > 0)
	{
		tmp = ft_strchr(ptr, *needle);
		if ((t_ulong)(tmp - ptr) > len)
			return ((void *)0);
		len -= tmp - ptr;
		ptr = tmp;
		if (!ptr)
			return ((void *)0);
		if (len < needle_len)
			return ((void *)0);
		if (ft_strncmp(ptr, needle, ft_strlen(needle)) == 0)
			return (ptr);
		ptr++;
		len--;
	}
	return ((void *)0);
}
