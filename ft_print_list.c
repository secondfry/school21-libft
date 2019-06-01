/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:49:56 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 17:02:52 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *root)
{
	size_t	i;

	if (!root)
	{
		ft_putstr("Trying to print void list!\n");
		return ;
	}
	i = 0;
	ft_putstr(">> List with root on ");
	ft_print_ptr((void *)root);
	ft_putchar('\n');
	while (root)
	{
		ft_putstr("> ");
		ft_putnbr(i);
		ft_putstr(" [");
		ft_print_ptr((void *)root);
		ft_putstr("] -> [");
		ft_print_ptr((void *)root->next);
		ft_putstr("]\n");
		ft_print_memory(root->content, root->content_size);
		i++;
		root = root->next;
	}
}
