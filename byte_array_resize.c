/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_array_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:30:40 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:00:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "array.h"

t_byte_array	*byte_array_resize(t_byte_array *arr, size_t len)
{
	t_byte_array	*ret;

	if (!arr)
		return ((void *)0);
	len = len + sizeof(long) - len % sizeof(long);
	ret = byte_array_new(len);
	if (!ret)
		return ((void *)0);
	ft_memcpy(ret->data, arr->data, arr->used);
	ret->used = arr->used;
	ft_memdel((void **)&arr);
	return (ret);
}
