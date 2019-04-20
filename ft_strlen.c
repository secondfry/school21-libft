/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:11:17 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/20 11:50:48 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	max_size;
	void	*ptr;

	max_size = -1;
	ptr = ft_memchr(s, 0, max_size);
	if (!ptr)
		return (max_size);
	return ((const char *)ptr - s);
}
