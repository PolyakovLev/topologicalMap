/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:06:03 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/18 16:23:27 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinats	**ft_zoom_in(t_coordinats **coords)
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
			coords[i][j].zoom += 2;
			j++;
		}
		i++;
	}
	return (coords);
}

t_coordinats	**ft_zoom_out(t_coordinats **coords)
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
			coords[i][j].zoom *= 0.5;
			j++;
		}
		i++;
	}
	return (coords);
}
