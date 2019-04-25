/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:17:03 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/04/25 15:23:40 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_byte	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static t_byte	is_same_sign(long a, long b)
{
	if (a < 0 && b < 0)
		return (1);
	if (a >= 0 && b >= 0)
		return (1);
	return (0);
}

/*
** endptr is not implemented
** base is not implemented
*/

long			ft_strtol(const char *str, char **endptr, int base)
{
	long	ret;
	char	sign;
	size_t	i;

	base = 10;
	endptr = (char**)0;
	ret = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (!is_same_sign(ret, ret * base))
			return (sign == -1 ? LONG_MIN : LONG_MAX);
		ret = ret * base + str[i] - 48;
		i++;
	}
	return (sign * ret);
}
