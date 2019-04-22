/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_y_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:06:42 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/18 16:07:46 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinats	**x_rot(t_coordinats **coords)
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
			coords[i][j].angel_a += 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}

t_coordinats	**x_mrot(t_coordinats **coords)
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
			coords[i][j].angel_a -= 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}

t_coordinats	**y_rot(t_coordinats **coords)
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
			coords[i][j].angel_b += 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}

t_coordinats	**y_mrot(t_coordinats **coords)
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
			coords[i][j].angel_b -= 0.05;
			j++;
		}
		i++;
	}
	return (coords);
}
