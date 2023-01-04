/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:41:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/04 12:09:22 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"

void	calculate_ray(int x, t_control *ctr)
{
	ctr->camera_x = 2 * x / (double) ctr->width - 1;
	ctr->raydir_x = ctr->dir_x + ctr->plane_x * ctr->camera_x;
	ctr->raydir_y = ctr->dir_y + ctr->plane_y * ctr->camera_x;
}

void	init_position(t_control *ctr)
{
	ctr->map_x = ctr->pos_x;
	ctr->map_y = ctr->pos_y;
	ctr->hit = 0;
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
		if (ctr->map[ctr->map_x][ctr->map_y] > 0)
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

void	ray_loop(t_control *ctr)
{
	int	x;

	x = 0;
	while (x < ctr->width)
	{
		calculate_ray(x, ctr);
		init_position(ctr);
		get_deltadist(ctr);
		get_step_sidedist(ctr);
		dda_algorithm(ctr);
		calculate_dist_draw(ctr);
		x++;
	}
}

/* while (x < SCREEN_WIDTH)
{
	calculate_ray_position_and_direction(x);
	set_box_position();
	calculate_delta_distance();
	calculate_step_and_side_distance_x();
	calculate_step_and_side_distance_y();
	dda();
	calculate_distance_perspective();
	calculate_vertical_line_height();
	calculate_draw_start_and_draw_end();
	calculate_texture_x();
	draw_vertical_texture_stripe(x);
	x++;
} */