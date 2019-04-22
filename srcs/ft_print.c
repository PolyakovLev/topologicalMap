/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:42 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 16:26:01 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_print_line(void *mlx_ptr, void *win_ptr,
					t_coordinats point1, t_coordinats point2)
{
	int arr[3][2];

	arr[0][0] = abs(point2.x - point1.x);
	arr[0][1] = abs(point2.y - point1.y);
	arr[1][0] = point1.x < point2.x ? 1 : -1;
	arr[1][1] = point1.y < point2.y ? 1 : -1;
	arr[2][0] = arr[0][0] - arr[0][1];
	mlx_pixel_put(mlx_ptr, win_ptr, point2.x, point2.y, point2.colour);
	while (point1.x != point2.x || point1.y != point2.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,
			point1.x, point1.y, point2.colour *
						ft_get_color(point1, point2, arr[0][0]));
		arr[2][1] = arr[2][0] * 2;
		if (arr[2][1] > -arr[0][1])
		{
			arr[2][0] -= arr[0][1];
			point1.x += arr[1][0];
		}
		if (arr[2][1] < arr[0][0])
		{
			arr[2][0] += arr[0][0];
			point1.y += arr[1][1];
		}
	}
}

void			ft_rotate(t_coordinats **arr, int *stat_arr)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (k < stat_arr[0])
	{
		l = 0;
		while (l < stat_arr[1])
		{
			arr[k][l] = ft_rotation(arr[k][l], arr[0][0].main_arr[k][l]);
			l++;
		}
		k++;
	}
}

t_coordinats	**ft_center_place(t_coordinats **arr, int *stat_arr)
{
	int delta[2];
	int k;
	int l;

	k = 0;
	l = 0;
	delta[1] = 500 - arr[stat_arr[0] / 2][stat_arr[1] / 2].y;
	delta[0] = 500 - arr[stat_arr[0] / 2][stat_arr[1] / 2].x;
	while (k < stat_arr[0])
	{
		l = 0;
		while (l != stat_arr[1])
		{
			arr[k][l].x += delta[0];
			arr[k][l].y += delta[1];
			l++;
		}
		k++;
	}
	return (arr);
}

void			ft_print_menu(void *mlx_ptr, void *win_ptr)
{
	int i;

	i = 0;
	while (i < 1000)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 50, 0xFF0000);
		i++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 30, 15, 0xFF0000, "KEY PRESS ");
	mlx_string_put(mlx_ptr, win_ptr, 140, 15, 0xFF0000, "rotation:");
	mlx_string_put(mlx_ptr, win_ptr, 240, 15, 0xBBFFFF, "X: Q W, Y: A S, \
							Z: Z X");
	mlx_string_put(mlx_ptr, win_ptr, 500, 15, 0xFF0000, "zoom:");
	mlx_string_put(mlx_ptr, win_ptr, 550, 15, 0xBBFFFF, " + - ");
}

void			ft_print(void *mlx_ptr, void *win_ptr,
					t_coordinats **ar, int *stat_arr)
{
	int a[4];

	ft_bzero(a, sizeof(a));
	while (a[0] < stat_arr[0] - 1)
	{
		a[1] = 0;
		while (a[1] < stat_arr[1] - 1)
		{
			ft_print_line(mlx_ptr, win_ptr, ar[a[0]][a[1]], ar[a[0]][a[1] + 1]);
			ft_print_line(mlx_ptr, win_ptr, ar[a[0]][a[1]], ar[a[0] + 1][a[1]]);
			a[1]++;
		}
		a[0]++;
	}
	while (a[2] < stat_arr[0] - 1)
	{
		ft_print_line(mlx_ptr, win_ptr, ar[a[2]][a[1]], ar[a[2] + 1][a[1]]);
		a[2]++;
	}
	while (a[3] < stat_arr[1] - 1)
	{
		ft_print_line(mlx_ptr, win_ptr, ar[a[0]][a[3]], ar[a[0]][a[3] + 1]);
		a[3]++;
	}
	ft_print_menu(mlx_ptr, win_ptr);
}
