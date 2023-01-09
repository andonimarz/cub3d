/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:41:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/09 10:41:42 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>
#include <stdio.h>

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
{1,4,0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

//First calculates the distance projected on camera direction
//Second the height of line to draw on screen
//Third the lowest and highest pixel to draw

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

void	get_color(t_control *ctr)
{
	if (worldMap[ctr->map_x][ctr->map_y] == 1)
		ctr->color = ctr->white;
	if (worldMap[ctr->map_x][ctr->map_y] == 2)
		ctr->color = ctr->green;
	if (worldMap[ctr->map_x][ctr->map_y] == 3)
		ctr->color = ctr->black;
	if (worldMap[ctr->map_x][ctr->map_y] == 4)
		ctr->color = 0x00ffff;
	if (ctr->side == 1)
		ctr->color = ctr->color / 2;
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
	//printf("FRAMETIME: %f\n", ctr->frametime);
	//printf("FPS COUNTER: %f\n", 1.0 / ctr->frametime);
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
		get_color(ctr);
		draw_line(ctr, x);
		x++;
	}
	calculate_frametime(ctr);
}
