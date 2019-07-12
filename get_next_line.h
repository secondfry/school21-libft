/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:30:57 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/07/12 16:45:05 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 1
# define NL 2
# define STATUS_ERR -1
# define STATUS_EOF 0
# define STATUS_READ 1

typedef struct	s_fd_list
{
	int					fd;
	char				*leftovers;
	char				buffer[BUFF_SIZE + 1];
	struct s_fd_list	*next;

}				t_fd_list;

int				get_next_line(const int fd, char **line);

#endif
