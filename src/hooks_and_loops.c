/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:32:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/11 13:22:40 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

int	key_press(int key, t_control *ctr)
{
	if (key == ESC)
		exit(0);	//FALTA FT_EXIT CON FREES Y DESTROY TEXTURES
	if (key == 13)
		ctr->key->w = 1;
	if (key == 0)
		ctr->key->a = 1;
	if (key == 1)
		ctr->key->s = 1;
	if (key == 2)
		ctr->key->d = 1;
	if (key == 123)
		ctr->key->l = 1;
	if (key == 124)
		ctr->key->r = 1;
	return (0);
}

int	key_release(int key, t_control *ctr)
{
	if (key == ESC)
		exit(0);	//FALTA FT_EXIT CON FREES Y DESTROY TEXTURES
	if (key == 13)
		ctr->key->w = 0;
	if (key == 0)
		ctr->key->a = 0;
	if (key == 1)
		ctr->key->s = 0;
	if (key == 2)
		ctr->key->d = 0;
	if (key == 123)
		ctr->key->l = 0;
	if (key == 124)
		ctr->key->r = 0;
	return (0);
}

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
