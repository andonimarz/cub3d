/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:02:05 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/16 12:48:39 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	map_player(t_control *ctr)
{
	char	**map;
	int		y;
	int		x;
	char	c;

	map = ctr->state->only_map;
	c = '\0';
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'W' \
				|| map[y][x] == 'S' || map[y][x] == 'E')
			{
				c = map[y][x];
				ctr->pos_x = x + 0.5;
				ctr->pos_y = y + 0.5;
			}
		}
	}
	return (c);
}
