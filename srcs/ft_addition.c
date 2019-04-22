/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:55:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 17:53:40 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			ft_get_color(t_coordinats point1, t_coordinats point2, int d)
{
	double percent;

	percent = 1.0;
	if (point1.z != point2.z)
		percent = 1.0 / d;
	return (percent);
}

t_coordinats	**ft_copy_array(t_coordinats **array,
							int linesize, int columnsize)
{
	int				arr[2];
	t_coordinats	**new_array;

	ft_bzero(arr, sizeof(arr));
	new_array = (t_coordinats**)malloc(sizeof(t_coordinats*) * linesize);
	while (arr[0] < linesize)
	{
		new_array[arr[0]] = (t_coordinats*)malloc(sizeof(t_coordinats)
									* columnsize);
		arr[0]++;
	}
	arr[0] = 0;
	while (arr[0] < linesize)
	{
		arr[1] = 0;
		while (arr[1] < columnsize)
		{
			new_array[arr[0]][arr[1]].x = array[arr[0]][arr[1]].x;
			new_array[arr[0]][arr[1]].y = array[arr[0]][arr[1]].y;
			new_array[arr[0]][arr[1]].z = array[arr[0]][arr[1]].z;
			arr[1]++;
		}
		arr[0]++;
	}
	return (new_array);
}

void			ft_init_array(t_coordinats **array, int *arr,
								char **splited_line, void **ptrs)
{
	array[arr[0]][arr[1]].x = arr[1];
	array[arr[0]][arr[1]].y = arr[0];
	array[arr[0]][arr[1]].z = ft_atoi(splited_line[arr[2]]);
	array[arr[0]][arr[1]].colour = ft_gets_colour(array,
						splited_line[arr[2]], arr[0], arr[1]);
	array[arr[0]][arr[1]].mlx_ptr = ptrs[0];
	array[arr[0]][arr[1]].win_ptr = ptrs[1];
	array[arr[0]][arr[1]].angel_a = 0;
	array[arr[0]][arr[1]].angel_b = 0;
	array[arr[0]][arr[1]].angel_c = 0;
	array[arr[0]][arr[1]].zoom = 1;
}
