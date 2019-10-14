/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_array_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:21:38 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/12 17:43:29 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "array.h"

t_byte_array	*byte_array_new(size_t len)
{
	t_byte_array	*ret;

	len = len + DATA_MODEL_LONG_WIDTH - len % DATA_MODEL_LONG_WIDTH;
	ret = (t_byte_array *)malloc(sizeof(t_byte_array));
	if (!ret)
		return ((void *)0);
	ret->size = len;
	ret->used = 0;
	ret->data = (t_byte *)malloc(sizeof(t_byte) * len);
	if (!ret->data)
		ft_memdel((void **)&ret);
	return (ret);
}
