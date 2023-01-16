/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:19:33 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/16 12:44:00 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	get_tex_num(t_control *ctr)
{
	if (ctr->ray->side == 0)
	{
		if (ctr->ray->raydir_x >= 0)
			ctr->tex->tex_num = 0;
		else
			ctr->tex->tex_num = 3;
	}
	else
	{
		if (ctr->ray->raydir_y >= 0)
			ctr->tex->tex_num = 2;
		else
			ctr->tex->tex_num = 1;
	}
}

void	get_tex_color(t_control *ctr)
{
	t_tex	*tex;
	t_ray	*ray;

	ray = ctr->ray;
	tex = ctr->tex;
	if (ray->side == 0)
		tex->wallx = ctr->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		tex->wallx = ctr->pos_x + ray->perpwalldist * ray->raydir_x;
	tex->wallx -= floor(tex->wallx);
	tex->tex_x = (int)(tex->wallx * (double)ctr->tex->texw);
	tex->step = 1.0 * tex->texh / ray->lineheight;
	tex->tex_pos = (ray->drawstart - ctr->height / 2 + ray->lineheight / 2) \
		* tex->step;
}

void	fill_buffer(t_control *ctr, int x)
{
	int		y;
	t_tex	*tex;
	t_ray	*ray;

	ray = ctr->ray;
	tex = ctr->tex;
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		tex->tex_y = (int)tex->tex_pos & (ctr->tex->texh - 1);
		tex->tex_pos += tex->step;
		tex->tex_color = tex->texture[tex->tex_num][ctr->tex->texh * \
			tex->tex_y + tex->tex_x];
		if (ray->side == 0)
			tex->tex_color = (tex->tex_color >> 1) & 8355711;
		ctr->tex->buffer[y][x] = tex->tex_color;
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
			ctr->tex->buffer[x][y] = 0;
			y++;
		}
		x++;
	}
}
