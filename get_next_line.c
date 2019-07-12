/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:30:47 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/06/05 19:06:07 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*create_fd_list(const int fd)
{
	t_fd_list	*ret;

	ret = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!ret)
		return ((void *)0);
	ret->fd = fd;
	ret->leftovers = ft_strnew(1);
	ft_bzero(ret->buffer, BUFF_SIZE + 1);
	ret->next = (void *)0;
	return (ret);
}

static t_fd_list	*get_entry(t_fd_list **db, const int fd)
{
	t_fd_list	*elem;

	if (fd < 0)
		return ((void *)0);
	if (!*db)
		return (*db = create_fd_list(fd));
	elem = *db;
	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	elem = create_fd_list(fd);
	if (!elem)
		return ((void *)0);
	elem->next = *db;
	*db = elem;
	return (*db);
}

static int			gnl_leftovers(t_fd_list *elem, char **line, char *status)
{
	char	*nl_ptr;
	size_t	len;
	char	*tmp;

	nl_ptr = ft_strchr(elem->leftovers, '\n');
	if (!nl_ptr)
	{
		*line = ft_strdup(elem->leftovers);
		free(elem->leftovers);
		elem->leftovers = ft_strnew(1);
		free(nl_ptr);
		if (!*line)
			return (*status = STATUS_ERR);
		return (0);
	}
	len = nl_ptr - elem->leftovers;
	*line = ft_strsub(elem->leftovers, 0, len);
	if (!*line)
		return (*status = STATUS_ERR);
	len++;
	tmp = ft_strsub(elem->leftovers, len, ft_strlen(elem->leftovers) - len);
	free(elem->leftovers);
	elem->leftovers = tmp;
	return (*status = STATUS_READ);
}

static int			gnl_buffer(
	t_fd_list *elem,
	char **line,
	ssize_t rsize,
	char *status
)
{
	char	*tmp[3];
	ssize_t	len;

	if ((tmp[NL] = ft_strchr(elem->buffer, '\n')))
	{
		len = tmp[NL] - elem->buffer > rsize - 1 ?
			rsize - 1 : tmp[NL] - elem->buffer;
		tmp[1] = ft_strsub(elem->buffer, 0, len);
		tmp[0] = ft_strjoin(*line, tmp[1]);
		free(tmp[1]);
		free(*line);
		*line = tmp[0];
		if (!*line)
			return (*status = STATUS_ERR);
		len++;
		free(elem->leftovers);
		elem->leftovers = ft_strsub(elem->buffer, len, rsize - len);
		return (*status = STATUS_READ);
	}
	tmp[0] = ft_strjoin(*line, elem->buffer);
	free(*line);
	*line = tmp[0];
	if (rsize < BUFF_SIZE)
		return (*status = STATUS_READ);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_fd_list	*db;
	t_fd_list			*elem;
	ssize_t				rsize;
	char				status;

	if (!line)
		return (-1);
	status = STATUS_READ;
	elem = get_entry(&db, fd);
	if (!elem)
		return (-1);
	if (gnl_leftovers(elem, line, &status))
		return (status);
	while ((rsize = read(fd, elem->buffer, BUFF_SIZE)) > 0)
	{
		elem->buffer[rsize] = '\0';
		if (gnl_buffer(elem, line, rsize, &status))
			return (status);
	}
	if (ft_strlen(*line))
		return (1);
	return (rsize);
}
