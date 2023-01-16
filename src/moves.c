/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:06:11 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/16 12:50:13 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

int	move_ws(t_control *ctr, int key)
{
	if (key == 13)
	{
		if (ctr->state->only_map[(int)(ctr->pos_y)][(int)(ctr->pos_x + \
		ctr->dir_x * ctr->movespeed)] != '1')
			ctr->pos_x += ctr->dir_x * ctr->movespeed;
		if (ctr->state->only_map[(int)(ctr->pos_y + ctr->dir_y * \
		ctr->movespeed)][(int)(ctr->pos_x)] != '1')
			ctr->pos_y += ctr->dir_y * ctr->movespeed;
	}
	else if (key == 1)
	{
		if (ctr->state->only_map[(int)(ctr->pos_y)][(int)(ctr->pos_x - \
		ctr->dir_x * ctr->movespeed)] != '1')
			ctr->pos_x -= ctr->dir_x * ctr->movespeed;
		if (ctr->state->only_map[(int)(ctr->pos_y - ctr->dir_y * \
		ctr->movespeed)][(int)(ctr->pos_x)] != '1')
			ctr->pos_y -= ctr->dir_y * ctr->movespeed;
	}
	return (1);
}

int	move_ad(t_control *ctr, int key)
{
	if (key == 2)
	{
		if (ctr->state->only_map[(int)(ctr->pos_y)][(int)(ctr->pos_x + \
		ctr->plane_x * ctr->movespeed)] != '1')
			ctr->pos_x += ctr->plane_x * ctr->movespeed;
		if (ctr->state->only_map[(int)(ctr->pos_y + ctr->plane_y * \
		ctr->movespeed)][(int)(ctr->pos_x)] != '1')
			ctr->pos_y += ctr->plane_y * ctr->movespeed;
	}
	else if (key == 0)
	{
		if (ctr->state->only_map[(int)(ctr->pos_y)][(int)(ctr->pos_x - \
		ctr->plane_x * ctr->movespeed)] != '1')
			ctr->pos_x -= ctr->plane_x * ctr->movespeed;
		if (ctr->state->only_map[(int)(ctr->pos_y - ctr->plane_y * \
		ctr->movespeed)][(int)(ctr->pos_x)] != '1')
			ctr->pos_y -= ctr->plane_y * ctr->movespeed;
	}
	return (1);
}

int	rotate_r(t_control *img)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = img->dir_x;
	img->dir_x = img->dir_x * cos(img->rotspeed) - img->dir_y * \
		sin(img->rotspeed);
	img->dir_y = old_dirx * sin(img->rotspeed) + img->dir_y * \
		cos(img->rotspeed);
	old_planex = img->plane_x;
	img->plane_x = img->plane_x * cos(img->rotspeed) - img->plane_y
		* sin(img->rotspeed);
	img->plane_y = old_planex * sin(img->rotspeed) + img->plane_y
		* cos(img->rotspeed);
	return (1);
}

int	rotate_l(t_control *img)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = img->dir_x;
	img->dir_x = img->dir_x * cos(-img->rotspeed) - img->dir_y * \
		sin(-img->rotspeed);
	img->dir_y = old_dirx * sin(-img->rotspeed) + img->dir_y * \
		cos(-img->rotspeed);
	old_planex = img->plane_x;
	img->plane_x = img->plane_x * cos(-img->rotspeed) - img->plane_y
		* sin(-img->rotspeed);
	img->plane_y = old_planex * sin(-img->rotspeed) + img->plane_y
		* cos(-img->rotspeed);
	return (1);
}
