/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:32:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/10 09:00:32 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

int	key_press(int key, t_control *ctr)
{
	if (key == ESC)
		exit(0);
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
		exit(0);
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

int	ft_inputs(t_control *ctr)
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
