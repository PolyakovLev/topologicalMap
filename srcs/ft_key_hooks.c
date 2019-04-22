/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:13:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 15:31:39 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(int keycode, t_coordinats **param)
{
	if (keycode == 53)
		ft_clean_exit(param);
	if (keycode == 24)
		ft_keys(param, ft_zoom_in);
	if (keycode == 27)
		ft_keys(param, ft_zoom_out);
	if (keycode == 12)
		ft_keys(param, x_rot);
	if (keycode == 13)
		ft_keys(param, x_mrot);
	if (keycode == 0)
		ft_keys(param, y_rot);
	if (keycode == 1)
		ft_keys(param, y_mrot);
	if (keycode == 6)
		ft_keys(param, z_rot);
	if (keycode == 7)
		ft_keys(param, z_mrot);
	if (keycode == 34)
		ft_proection_iso(param);
	if (keycode == 15)
		ft_proection_base(param);
	return (0);
}

void	ft_keys(t_coordinats **param, t_coordinats **(*f)(t_coordinats **a))
{
	mlx_clear_window(param[0][0].mlx_ptr, param[0][0].win_ptr);
	param = (*f)(param);
	ft_rotate(param, param[0][0].stat_arr);
	ft_center_place(param, param[0][0].stat_arr);
	ft_print(param[0][0].mlx_ptr, param[0][0].win_ptr, param,
			param[0][0].stat_arr);
}

void	ft_proection_base(t_coordinats **param)
{
	int i;
	int j;

	mlx_clear_window(param[0][0].mlx_ptr, param[0][0].win_ptr);
	i = 0;
	j = 0;
	while (i < param[0][0].stat_arr[0])
	{
		j = 0;
		while (j < param[0][0].stat_arr[1])
		{
			param[i][j].angel_a = 0;
			param[i][j].angel_b = 0;
			param[i][j].angel_c = 0;
			param[i][j].zoom = 1;
			j++;
		}
		i++;
	}
	ft_rotate(param, param[0][0].stat_arr);
	ft_center_place(param, param[0][0].stat_arr);
	ft_print(param[0][0].mlx_ptr, param[0][0].win_ptr,
			param, param[0][0].stat_arr);
}

void	ft_proection_iso(t_coordinats **param)
{
	int i;
	int j;

	mlx_clear_window(param[0][0].mlx_ptr, param[0][0].win_ptr);
	i = 0;
	j = 0;
	while (i < param[0][0].stat_arr[0])
	{
		j = 0;
		while (j < param[0][0].stat_arr[1])
		{
			param[i][j].angel_a = 0.685398;
			param[i][j].angel_b = -0.485398;
			param[i][j].angel_c = 0.523;
			param[i][j].zoom = 12;
			j++;
		}
		i++;
	}
	ft_rotate(param, param[0][0].stat_arr);
	ft_center_place(param, param[0][0].stat_arr);
	ft_print(param[0][0].mlx_ptr, param[0][0].win_ptr,
			param, param[0][0].stat_arr);
}

void	ft_clean_exit(t_coordinats **param)
{
	int i;
	int j;
	int array;

	i = 0;
	j = 0;
	array = param[0][0].stat_arr[0];
	while (i < array)
	{
		if (i == 0)
		{
			while (j < array)
			{
				free(param[0][0].main_arr[j]);
				j++;
			}
			free(param[0][0].main_arr);
		}
		free(param[i]);
		i++;
	}
	free(param);
	exit(0);
}
