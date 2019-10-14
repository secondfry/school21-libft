/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:23:19 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/12 17:48:12 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H

# define ARRAY_H

# include "libft.h"

typedef struct	s_byte_array
{
	t_byte	*data;
	size_t	used;
	size_t	size;
}				t_byte_array;

t_byte_array	*byte_array_new(size_t len);
t_byte_array	*byte_array_resize(t_byte_array *arr, size_t len);
t_byte_array	*byte_array_add(t_byte_array *arr, t_byte data);
t_byte			byte_array_has(t_byte_array *arr, t_byte data);

#endif
