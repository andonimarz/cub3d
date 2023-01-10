/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:19:33 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/10 15:39:30 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	get_tex_num(t_control *ctr)
{
	if (ctr->side == 0)
	{
		if (ctr->raydir_x >= 0)
			ctr->tex_num = 0;
		else
			ctr->tex_num = 1;
	}
	else
	{
		if (ctr->raydir_y >= 0)
			ctr->tex_num = 2;
		else
			ctr->tex_num = 3;
	}
}

void	get_tex_color(t_control *ctr)
{
	if (ctr->side == 0)
		ctr->wallx = ctr->pos_y + ctr->perpwalldist * ctr->raydir_y;
	else
		ctr->wallx = ctr->pos_x + ctr->perpwalldist * ctr->raydir_x;
	ctr->wallx -= floor(ctr->wallx);
	ctr->tex_x = (int)(ctr->wallx * (double)ctr->texw);
	if (ctr->side == 0 && ctr->raydir_x > 0)
		ctr->tex_x = ctr->texw - ctr->tex_x - 1;
	if (ctr->side == 1 && ctr->raydir_x < 0)
		ctr->tex_x = ctr->texw - ctr->tex_x - 1;
	ctr->step = 1.0 * ctr->texh / ctr->lineheight;
	ctr->tex_pos = (ctr->drawstart - ctr->height / 2 + ctr->lineheight / 2) \
		* ctr->step;
}

void	fill_buffer(t_control *ctr, int x)
{
	int	y;

	y = ctr->drawstart;
	while (y < ctr->drawend)
	{
		ctr->tex_y = (int)ctr->tex_pos & (ctr->texh - 1);
		ctr->tex_pos += ctr->step;
		ctr->tex_color = ctr->texture[ctr->tex_num][ctr->texh * ctr->tex_y + \
			ctr->tex_x];
		if (ctr->side == 1)
			ctr->tex_color = (ctr->tex_color >> 1) & 8355711;
		ctr->buffer[y][x] = ctr->tex_color;
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
