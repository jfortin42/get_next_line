/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:44:19 by jfortin           #+#    #+#             */
/*   Updated: 2016/01/26 16:23:26 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_fd
{
	int				fd;
	char			*str;
}					t_fd;

typedef struct		s_lst_fd
{
	t_fd			*data;
	struct s_lst_fd	*next;
}					t_lst_fd;

int					get_next_line(int const fd, char **line);

#endif
