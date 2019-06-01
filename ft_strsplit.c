/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:17:06 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/01 15:42:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *str, char sep)
{
	size_t	ret;
	t_byte	flag;

	ret = 0;
	flag = 0;
	while (*str)
	{
		if (*str != sep)
		{
			flag = 1;
		}
		else
		{
			if (flag)
				ret++;
			flag = 0;
		}
		str++;
	}
	if (flag)
		ret++;
	return (ret);
}

static char		*make_word(char const **str, char sep)
{
	char const	*tmp;
	char		*ret;
	char		*start;
	char		*end;
	size_t		len;

	tmp = *str;
	while (*tmp == sep)
		tmp++;
	start = (char *)tmp;
	end = ft_strchr(start, sep);
	if (end)
		len = end - start;
	else
		len = ft_strlen(start);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return ((void *)0);
	ft_strncpy(ret, tmp, len);
	ret[len] = 0;
	*str = end;
	return (ret);
}

static void		cleanup(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ft_memdel((void **)&arr[i]);
	ft_memdel((void **)&arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words_count;
	size_t	i;
	char	**ret;

	if (!s)
		return ((void *)0);
	words_count = count_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!ret)
		return ((void *)0);
	ret[words_count] = (void *)0;
	i = 0;
	while (i < words_count)
	{
		ret[i] = make_word(&s, c);
		if (!ret[i])
		{
			cleanup(ret, i);
			return ((void *)0);
		}
		i++;
	}
	return (ret);
}
