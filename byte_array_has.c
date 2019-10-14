/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_array_has.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:44:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/12 17:47:06 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_byte			byte_array_has(t_byte_array *arr, t_byte data)
{
	size_t	i;

	i = 0;
	while (i < arr->used)
	{
		if (arr->data[i] == data)
			return (1);
		i++;
	}
	return (0);
}
