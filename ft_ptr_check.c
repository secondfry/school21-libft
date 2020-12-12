/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:21:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/13 20:41:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

void	ft_ptr_check(void *ptr, char *msg, size_t args, ...)
{
	va_list	ap;
	void	*tmp;

	if (ptr)
		return ;
	ft_putendl_fd(msg, 2);
	ft_memdel(&ptr);
	va_start(ap, args);
	while (args)
	{
		tmp = va_arg(ap, void *);
		if (tmp)
			ft_memdel(&tmp);
		args--;
	}
	va_end(ap);
	exit(ENOMEM);
}
