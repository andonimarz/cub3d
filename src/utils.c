/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:24:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/11 13:43:15 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_control(t_control *control)
{
	control->height = SCREENHEIGHT;
	control->width = SCREENWIDTH;
	control->ceiling = 0x00ffff;
	control->floor = 0x7a7a7a;
	control->pos_x = 22;
	control->pos_y = 11.5;
	control->dir_x = -1;
	control->dir_y = 0;
	control->plane_x = 0;
	control->plane_y = 0.66;
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
