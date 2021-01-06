/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:33:29 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:00:00 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_static(long n)
{
	static char     buffer[sizeof(long) * 8 / 3];
	t_ulong         tmp;
	t_byte          i;

	if (n == 0)
		return ("0");
	ft_bzero(buffer, sizeof(long) * 8 / 3);
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
