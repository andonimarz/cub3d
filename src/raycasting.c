/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:41:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/10 15:29:39 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

//mapa de prueba
int	worldMap[24][24]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,2,0,4,0,0,0,0,0,0,0,0,0,3,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,3,0,3,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,3,0,0,0,3,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_pos_calculate_ray(int x, t_control *ctr)
{
	ctr->map_x = ctr->pos_x;
	ctr->map_y = ctr->pos_y;
	ctr->hit = 0;
	ctr->camera_x = 2 * x / (double) ctr->width - 1;
	ctr->raydir_x = ctr->dir_x + ctr->plane_x * ctr->camera_x;
	ctr->raydir_y = ctr->dir_y + ctr->plane_y * ctr->camera_x;
}

void	get_deltadist(t_control *ctr)
{
	if (ctr->raydir_x == 0)
		ctr->deltadist_x = 1e30;
	else
		ctr->deltadist_x = fabs(1 / ctr->raydir_x);
	if (ctr->raydir_y == 0)
		ctr->deltadist_y = 1e30;
	else
		ctr->deltadist_y = fabs(1 / ctr->raydir_y);
}

void	get_step_sidedist(t_control *ctr)
{
	if (ctr->raydir_x < 0)
	{
		ctr->step_x = -1;
		ctr->sidedist_x = (ctr->pos_x - ctr->map_x) * ctr->deltadist_x;
	}
	else
	{
		ctr->step_x = 1;
		ctr->sidedist_x = (ctr->map_x + 1.0 - ctr->pos_x) * ctr->deltadist_x;
	}
	if (ctr->raydir_y < 0)
	{
		ctr->step_y = -1;
		ctr->sidedist_y = (ctr->pos_y - ctr->map_y) * ctr->deltadist_y;
	}
	else
	{
		ctr->step_y = 1;
		ctr->sidedist_y = (ctr->map_y + 1.0 - ctr->pos_y) * ctr->deltadist_y;
	}
}

void	dda_algorithm(t_control *ctr)
{
	while (ctr->hit == 0)
	{
		if (ctr->sidedist_x < ctr->sidedist_y)
		{
			ctr->sidedist_x += ctr->deltadist_x;
			ctr->map_x += ctr->step_x;
			ctr->side = 0;
		}
		else
		{
			ctr->sidedist_y += ctr->deltadist_y;
			ctr->map_y += ctr->step_y;
			ctr->side = 1;
		}
		if (worldMap[ctr->map_x][ctr->map_y] > 0)
			ctr->hit = 1;
	}
}

void	calculate_dist_draw(t_control *ctr)
{
	if (ctr->side == 0)
		ctr->perpwalldist = (ctr->sidedist_x - ctr->deltadist_x);
	else
		ctr->perpwalldist = (ctr->sidedist_y - ctr->deltadist_y);
	ctr->lineheight = ctr->height / ctr->perpwalldist;
	ctr->drawstart = -ctr->lineheight / 2 + ctr->height / 2;
	if (ctr->drawstart < 0)
		ctr->drawstart = 0;
	ctr->drawend = ctr->lineheight / 2 + ctr->height / 2;
	if (ctr->drawend >= ctr->height)
		ctr->drawend = ctr->height - 1;
}
