/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:02:05 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/13 12:13:31 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

extern char worldMap[24][24];

char	map_player(t_parse	*parse)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < 24)
	{
		x = 0;
		while (x < 24)
		{
			if (worldMap[y][x] == 'N' || worldMap[y][x] == 'W' \
				|| worldMap[y][x] == 'S' || worldMap[y][x] == 'E')
			{
				c = worldMap[y][x];
				printf("%c\n", c);
				parse->pos_x = 24 - x + 0.5;
				parse->pos_y = 24 - y - 0.5;
				break ;
			}
			x++;
		}
		y++;
	}
	return (c);
}
