/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:50:25 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:58 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_color(char c, t_byte color)
{
	ft_putstr("\033[0;");
	ft_putnbr(color);
	ft_putchar('m');
	ft_putchar(c);
	ft_putstr("\033[0m");
}
