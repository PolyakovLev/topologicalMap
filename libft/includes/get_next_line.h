/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:35:39 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/02 13:35:42 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 20

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

int	ft_cut_line(int fd, char **line, char **array);
int	get_next_line(const int fd, char **line);

#endif
