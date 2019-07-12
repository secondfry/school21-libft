/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:33:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/05 16:41:33 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char *str, t_byte color)
{
	ft_putstr("\033[0;");
	ft_putnbr(color);
	ft_putchar('m');
	ft_putstr(str);
	ft_putstr("\033[0m");
}
