/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:44:32 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 18:29:50 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinats	**ft_malloc_array(int linesize, int columnsize)
{
	int				i;
	t_coordinats	**array;

	i = 0;
	array = (t_coordinats **)malloc(sizeof(t_coordinats *) * linesize);
	while (i < linesize)
	{
		array[i] = (t_coordinats *)malloc(sizeof(t_coordinats) * columnsize);
		i++;
	}
	return (array);
}

t_coordinats	**ft_make_array(int linesize, int columnsize,
								char *lines, int *stat_arr)
{
	int				arr[3];
	t_coordinats	**array;
	char			**splited_line;
	void			*ptrs[2];

	ptrs[0] = mlx_init();
	ptrs[1] = mlx_new_window(ptrs[0], 1000, 1000, "someWindow");
	ft_bzero(arr, sizeof(arr));
	splited_line = ft_strsplit(lines, ' ');
	array = ft_malloc_array(linesize, columnsize);
	while (splited_line[arr[2]])
	{
		if (arr[1] == columnsize)
		{
			arr[1] = 0;
			arr[0]++;
		}
		ft_init_array(array, arr, splited_line, ptrs);
		array[arr[0]][arr[1]].stat_arr = stat_arr;
		arr[2]++;
		arr[1]++;
	}
	array[0][0].main_arr = ft_copy_array(array, linesize, columnsize);
	return (array);
}

t_coordinats	**ft_read(char *argv, int *s)
{
	char	*line;
	int		arr[3];
	char	*l;
	char	**splited_line;

	l = ft_strnew(1);
	ft_bzero(arr, sizeof(arr));
	if ((arr[2] = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(arr[2], &line))
	{
		if (line[0] == ' ' || line[0] == '\0')
			break ;
		splited_line = arr[0] == 0 ? ft_strsplit(line, ' ') : splited_line;
		l = ft_strjoin(l, line);
		l = ft_strjoin(l, " ");
		arr[0]++;
	}
	if (arr[0] < 2)
		return (NULL);
	while (splited_line[arr[1]])
		arr[1]++;
	s[0] = arr[0];
	s[1] = arr[1];
	return (close(arr[2] == -1) ? NULL : ft_make_array(arr[0], arr[1], l, s));
}

int				ft_make_decimal(char *line)
{
	int i;
	int len;
	int base;
	int dec_val;

	base = 1;
	dec_val = 0;
	len = ft_strlen(line);
	i = len - 1;
	while (i >= 0)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			dec_val += (line[i] - 48) * base;
			base = base * 16;
		}
		else if (line[i] >= 'A' && line[i] <= 'F')
		{
			dec_val += (line[i] - 55) * base;
			base = base * 16;
		}
		i--;
	}
	return (dec_val);
}

int				ft_gets_colour(t_coordinats **arr, char *line, int i, int j)
{
	char *temp;

	if ((temp = ft_strchr(line, ',')))
	{
		temp = temp + 3;
		arr[i][j].colour = ft_make_decimal(temp);
	}
	else
		arr[i][j].colour = 0xFFFFFF;
	return (arr[i][j].colour);
}
