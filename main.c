/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:16:28 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 18:01:24 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	static int		stat_arr[2];
	t_coordinats	**arr;
	t_coordinats	**base;

	if (argc == 2)
	{
		arr = ft_read(argv[1], stat_arr);
		if (!arr)
		{
			ft_putstr("error\n");
			return (1);
		}
		arr = ft_center_place(arr, stat_arr);
		ft_print(arr[0][0].mlx_ptr, arr[0][0].win_ptr, arr, stat_arr);
		mlx_key_hook(arr[0][0].win_ptr, ft_exit, arr);
		mlx_loop(arr[0][0].mlx_ptr);
	}
	else
		ft_putstr("error\n");
	return (0);
}
