/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_array_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:30:32 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/05/31 13:52:51 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_byte_array	*byte_array_add(t_byte_array *arr, t_byte data)
{
	if (arr->size == arr->used)
		arr = byte_array_resize(arr, arr->size);
	arr->data[arr->used] = data;
	arr->used++;
	return (arr);
}
