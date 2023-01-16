/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:24:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/16 11:18:42 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_orientation(t_control *ctr)
{
	ctr->dir_x = 0;
	ctr->dir_y = 0;
	ctr->plane_x = 0;
	ctr->plane_y = 0;
	if (ctr->player == 'S')
	{
		ctr->dir_y = 1;
		ctr->plane_x = -0.66;
	}
	if (ctr->player == 'N')
	{
		ctr->dir_y = -1;
		ctr->plane_x = 0.66;
	}
	if (ctr->player == 'W')
	{
		ctr->dir_x = -1;
		ctr->plane_y = -0.66;
	}
	if (ctr->player == 'E')
	{
		ctr->dir_x = 1;
		ctr->plane_y = 0.66;
	}
}

unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

void	init_control(t_control *control)
{
	t_color	*c;

	c = &control->state->color;
	control->height = SCREENHEIGHT;
	control->width = SCREENWIDTH;
	control->ceiling = rgb_to_hex(c->ceiling[0], c->ceiling[1], c->ceiling[2]);
	control->floor = rgb_to_hex(c->floor[0], c->floor[1], c->floor[2]);
	control->player = map_player(control);
	get_orientation(control);
	control->time = ft_get_time();
	control->old_time = 0;
	control->frametime = 0;
}

void	init_key(t_key *key)
{
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	key->l = 0;
	key->r = 0;
}
