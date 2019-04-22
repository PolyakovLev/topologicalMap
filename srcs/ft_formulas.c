/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:58:19 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 17:52:22 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinats	ft_rotation(t_coordinats coords, t_coordinats co)
{
	coords.x = (co.x * cos(coords.angel_b) * cos(coords.angel_c) -
				co.y * cos(coords.angel_b) * sin(coords.angel_c) +
				co.z * sin(coords.angel_b)) * coords.zoom;
	coords.y = ((co.x * sin(coords.angel_a) * sin(coords.angel_b) *
				cos(coords.angel_c) + cos(coords.angel_a) *
				sin(coords.angel_c)) + co.y * (cos(coords.angel_a) *
				cos(coords.angel_c) - sin(coords.angel_a) * sin(coords.angel_b)
				* sin(coords.angel_c)) - co.z * cos(coords.angel_b) *
				sin(coords.angel_a)) * coords.zoom;
	return (coords);
}

t_coordinats	**z_rot(t_coordinats **coords)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < coords[0][0].stat_arr[0])
	{
		j = 0;
		while (j < coords[0][0].stat_arr[1])
		{
			coords[i][j].angel_c += 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}

t_coordinats	**z_mrot(t_coordinats **coords)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < coords[0][0].stat_arr[0])
	{
		j = 0;
		while (j < coords[0][0].stat_arr[1])
		{
			coords[i][j].angel_c -= 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}
