/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:32:00 by ramory-l          #+#    #+#             */
/*   Updated: 2019/01/18 16:47:58 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>

typedef struct			s_coordinats
{
	int					x;
	int					y;
	int					z;
	double				angel_a;
	double				angel_b;
	double				angel_c;
	double				zoom;
	void				*mlx_ptr;
	void				*win_ptr;
	int					colour;
	int					*stat_arr;
	struct s_coordinats	**main_arr;
}						t_coordinats;

double					ft_get_color(t_coordinats point1,
									t_coordinats point2, int d);
void					ft_init_array(t_coordinats **array, int *arr,
									char **splited_line, void **ptrs);
void					ft_keys(t_coordinats **param,
									t_coordinats **(*f)(t_coordinats **));
void					ft_proection_base(t_coordinats **param);
void					ft_proection_iso(t_coordinats **param);
void					ft_clean_exit(t_coordinats **param);
void					ft_rotate(t_coordinats **arr, int *stat_arr);
void					ft_print(void *mlx_ptr, void *win_ptr,
									t_coordinats **arr, int *stat_arr);
void					ft_print_line(void *mlx_ptr, void *win_ptr,
									t_coordinats point1, t_coordinats point2);
int						ft_exit(int keycode, t_coordinats **param);
int						ft_zoom(int keycode, t_coordinats **param);
int						ft_gets_colour(t_coordinats **arr,
									char *line, int i, int j);
t_coordinats			**ft_read(char *argv, int *stat_arr);
t_coordinats			x_rotation(t_coordinats coords, int angel);
t_coordinats			y_rotation(t_coordinats coords, int angel);
t_coordinats			z_rotation(t_coordinats coords, int angel);
t_coordinats			**ft_center_place(t_coordinats **arr, int *stat_arr);
t_coordinats			ft_rotation(t_coordinats coords, t_coordinats co);
t_coordinats			**ft_zoom_in(t_coordinats **coords);
t_coordinats			**ft_zoom_out(t_coordinats **coords);
t_coordinats			**x_rot(t_coordinats **coords);
t_coordinats			**y_rot(t_coordinats **coords);
t_coordinats			**z_rot(t_coordinats **coords);
t_coordinats			**z_mrot(t_coordinats **coords);
t_coordinats			**x_mrot(t_coordinats **coords);
t_coordinats			**y_mrot(t_coordinats **coords);
t_coordinats			**ft_copy_array(t_coordinats **array,
									int linesize, int columnsize);

#endif
