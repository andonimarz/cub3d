/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:41:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/10 12:06:28 by amarzana         ###   ########.fr       */
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

/* void	get_color(t_control *ctr)
{
	if (worldMap[ctr->map_x][ctr->map_y] == 1)
		ctr->color = ctr->white;
	if (worldMap[ctr->map_x][ctr->map_y] == 2)
		ctr->color = ctr->green;
	if (worldMap[ctr->map_x][ctr->map_y] == 3)
		ctr->color =  0xffd700;
	if (worldMap[ctr->map_x][ctr->map_y] == 4)
		ctr->color = 0x4b0082;
	if (ctr->side == 1)
		ctr->color = ctr->color / 2;
} */

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

//Texturing calculations

void	get_tex_color(t_control *ctr, int x)
{
	int	y;

	ctr->tex_num = worldMap[ctr->map_x][ctr->map_y] - 1;
	if (ctr->side == 0)		//calculate value of wallX
		ctr->wallx = ctr->pos_y + ctr->perpwalldist * ctr->raydir_y;
	else
		ctr->wallx = ctr->pos_x + ctr->perpwalldist * ctr->raydir_x;
	ctr->wallx -= floor(ctr->wallx);
	ctr->tex_x = (int)(ctr->wallx * 64);
	if (ctr->side == 0 && ctr->raydir_x > 0)	//x coordinate on the texture
		ctr->tex_x = 64 - ctr->tex_x - 1;
	if (ctr->side == 1 && ctr->raydir_x < 0)
		ctr->tex_x = 64 - ctr->tex_x - 1;
	ctr->step = 1.0 * 64 / ctr->lineheight;
	ctr->tex_pos = (ctr->drawstart - ctr->height / 2 + ctr->lineheight / 2 * ctr->step);
	y = ctr->drawstart;
	while (y < ctr->drawend)
	{
		ctr->tex_y = (int)ctr->tex_pos & (ctr->texh - 1);
		ctr->tex_pos += ctr->step;
		ctr->tex_color = ctr->texture[ctr->tex_num][ctr->texh * ctr->tex_y + ctr->tex_x];
		if (ctr->side == 1)
			ctr->tex_color = (ctr->tex_color >> 1) & 8355711;
		ctr->buffer[y][x] = ctr->tex_color;
		y++;
	}
}

void	draw_tex_line(t_control *ctr, int x)
{
	int	y;

	y = ctr->drawstart;
	while (y < ctr->drawend)
	{
		mlx_place_pixel(ctr->data, x, y, ctr->buffer[y][x]);
		y++;
	}
}

void	clear_buffer(t_control *ctr)
{
	int	x;
	int	y;

	x = 0;
	while (x < ctr->height)
	{
		y = 0;
		while (y < ctr->width)
		{
			ctr->buffer[x][y] = 0;
			y++;
		}
		x++;
	}
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
		get_tex_color(ctr, x);
		draw_tex_line(ctr, x);
		//get_color(ctr);
		//draw_line(ctr, x);
		x++;
	}
	calculate_frametime(ctr);
	clear_buffer(ctr);
}
