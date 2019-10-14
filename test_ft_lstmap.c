#include "libft.h"
#include <stdlib.h>

t_list	*some_function(t_list *elem)
{
	char	*sk;
	t_list	*ret;

	ret = ft_lstnew(elem->content, elem->content_size);

	sk = (char *)ret->content;
	while (*sk)
	{
		*sk = ft_toupper(*sk);
		sk++;
	}

	// ret->content_size *= 2;

	return ret;
}

int		main()
{
	char	*str;
	t_list	*a;

	str = ft_strnew(5);
	a = ft_lstnew(str, 5);
	free(str);
	((char *)a->content)[0] = 'a';
	ft_putstr(">>> Initial list\n");
	ft_print_list(a);
	ft_putstr("----------------------------------------------------------------------\n");

	str = ft_strnew(5);
	a->next = ft_lstnew(str, 5);
	free(str);
	((char *)a->next->content)[0] = 'b';
	ft_putstr(">>> List with one more chain\n");
	ft_print_list(a);
	ft_putstr("----------------------------------------------------------------------\n");

	str = ft_strnew(5);
	a->next->next = ft_lstnew(str, 5);
	free(str);
	((char *)a->next->next->content)[0] = 'c';
	ft_putstr(">>> ...one more again\n");
	ft_print_list(a);
	ft_putstr("----------------------------------------------------------------------\n");

	t_list *b = ft_lstmap(a, &some_function);
	ft_putstr(">>> Initial list after map function\n");
	ft_print_list(a);
	ft_putstr("----------------------------------------------------------------------\n");
	ft_putstr(">>> New list returned from map function\n");
	ft_print_list(b);
	ft_putstr("----------------------------------------------------------------------\n");

	return 0;
}
