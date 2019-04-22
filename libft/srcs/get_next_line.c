/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:33:55 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/02 13:35:19 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cut_line(int fd, char **line, char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[fd][i] != '\n' && array[fd][i])
		i++;
	if (array[fd][i] == '\n')
	{
		*line = ft_strsub(array[fd], 0, i);
		temp = ft_strdup(array[fd] + i + 1);
		free(array[fd]);
		array[fd] = temp;
		if (!array[fd][0])
			ft_strdel(&array[fd]);
	}
	else if (!array[fd][i])
	{
		*line = ft_strdup(array[fd]);
		ft_strdel(&array[fd]);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *array[256];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd == -1 || !line)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!array[fd])
			array[fd] = ft_strnew(1);
		temp = ft_strjoin(array[fd], buffer);
		free(array[fd]);
		array[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && (!array[fd] || !array[fd][0]))
		return (0);
	return (ft_cut_line(fd, line, array));
}
