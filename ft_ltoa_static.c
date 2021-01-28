/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:33:29 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/28 14:17:35 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_static(long n)
{
	static char	buffer[DATA_MODEL_LONG_DECIMAL_WIDTH];
	t_ulong		tmp;
	t_byte		i;

	if (n == 0)
		return ("0");
	ft_bzero(buffer, DATA_MODEL_LONG_DECIMAL_WIDTH);
	tmp = n < 0 ? -n : n;
	i = 0;
	while (tmp != 0)
	{
		buffer[i++] = tmp % 10 + 48;
		tmp /= 10;
	}
	if (n < 0)
		buffer[i] = '-';
	return (ft_strrev(buffer));
}
