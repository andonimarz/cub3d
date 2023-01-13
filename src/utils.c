/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:24:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/13 12:01:12 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

extern char **worldMap;

void	get_orientation(t_control *ctr)
{
	ctr->dir_x = 0;
	ctr->dir_y = 0;
	ctr->plane_x = 0;
	ctr->plane_y = 0;
	if (ctr->parse->player == 'E')
	{
		ctr->dir_y = 1;
		ctr->plane_x = 0.66;
	}
	if (ctr->parse->player == 'W')
	{
		ctr->dir_y = -1;
		ctr->plane_x = -0.66;
	}
	if (ctr->parse->player == 'S')
	{
		ctr->dir_x = 1;
		ctr->plane_y = -0.66;
	}
	if (ctr->parse->player == 'N')
	{
		ctr->dir_x = -1;
		ctr->plane_y = 0.66;
	}
}

void	init_parse(t_parse *parse)
{
	parse->cei[0] = 0;
	parse->cei[1] = 153;
	parse->cei[2] = 153;
	parse->flo[0] = 96;
	parse->flo[1] = 96;
	parse->flo[2] = 96;
	parse->player = map_player(parse);
}

unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

void	init_control(t_control *control)
{
	t_parse	*p;

	p = control->parse;
	control->height = SCREENHEIGHT;
	control->width = SCREENWIDTH;
	control->ceiling = rgb_to_hex(p->cei[0], p->cei[1], p->cei[2]);
	control->floor = rgb_to_hex(p->flo[0], p->flo[1], p->flo[2]);
	control->pos_x = control->parse->pos_x;
	control->pos_y = control->parse->pos_y;
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
