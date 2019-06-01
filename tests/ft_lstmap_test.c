/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:19:33 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 17:21:33 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *inc(t_list *elem)
{
	char *str = (char *)elem -> content;
	while (*str)
	{
		*str = (*str) + 1;
		str++;
	}
	return (elem);
}

int main()
{
	t_list *a = ft_lstnew("abcd", 4);
	ft_lstadd(&a, ft_lstnew("BCDE", 4));

	t_list *b = ft_lstmap(a, inc);

	ft_print_list(a);

	ft_print_list(b);

	return (0);
}
