/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 08:52:01 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/13 08:58:52 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

void	calculate_frametime(t_control *ctr)
{
	ctr->old_time = ctr->time;
	ctr->time = ft_get_time();
	ctr->frametime = (ctr->time - ctr->old_time) / 1000.0;
	if (ctr->frametime > 0.05)
		ctr->frametime = 0.017;
	ctr->movespeed = ctr->frametime * 5.0;
	ctr->rotspeed = ctr->frametime * 3.0;
}

void	ray_loop(t_control *ctr)
{
	int	x;

	x = 0;
	while (x < ctr->width)
	{
		init_pos_calculate_ray(x, ctr);
		get_deltadist(ctr);
		get_step_sidedist(ctr);
		dda_algorithm(ctr);
		calculate_dist_draw(ctr);
		get_tex_num(ctr);
		get_tex_color(ctr);
		fill_buffer(ctr, x);
		draw_tex_line(ctr, x);
		x++;
	}
	calculate_frametime(ctr);
	clear_buffer(ctr);
}

int	hook_loop(t_control *ctr)
{
	int	move;

	move = 0;
	if (ctr->key->w == 1)
		move = move_ws(ctr, 13);
	if (ctr->key->s == 1)
		move = move_ws(ctr, 1);
	if (ctr->key->a == 1)
		move = move_ad(ctr, 0);
	if (ctr->key->d == 1)
		move = move_ad(ctr, 2);
	if (ctr->key->l == 1)
		move = rotate_l(ctr);
	if (ctr->key->r == 1)
		move = rotate_r(ctr);
	if (move)
	{
		fill_background(ctr);
		ray_loop(ctr);
		mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
			ctr->data->img, 0, 0);
	}
	return (0);
}

void	mlx_main_loop(t_control *ctr)
{
	t_data	data;
	t_key	key;
	t_tex	tex;
	t_ray	ray;

	ctr->key = &key;
	init_key(&key);
	ctr->data = &data;
	ctr->tex = &tex;
	ctr->ray = &ray;
	ctr->data->mlx_ptr = mlx_init();
	init_screen(ctr);
	mlx_hook(ctr->data->mlx_win, KEY_PRESS, 0, &key_press, ctr);
	mlx_hook(ctr->data->mlx_win, KEY_RELEASE, 0, &key_release, ctr);
	mlx_hook(ctr->data->mlx_win, EXIT, 0, &exit_mlx, ctr);
	mlx_loop_hook(ctr->data->mlx_ptr, &hook_loop, ctr);
	mlx_loop(ctr->data->mlx_ptr);
}
