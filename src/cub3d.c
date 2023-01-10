/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/10 13:17:55 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <sys/time.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

long	ft_get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	fill_control(t_control *control)
{
	int	i;

	i = -1;
	control->height = screenHeight;
	control->width = screenWidth;
	control->ceiling = 0x000000;
	control->floor = 0x000000;
	control->black = 0x000000;
	control->white = 0xffffff;
	control->green = 0x00ff00;
	control->pos_x = 22;
	control->pos_y = 11.5;
	control->dir_x = -1;
	control->dir_y = 0;
	control->plane_x = 0;
	control->plane_y = 0.66;
	control->time = ft_get_time();
	control->old_time = 0;
	control->frametime = 0;
	control->texh = 64;
	control->texw = 64;
	while (++i < 4)
		control->texture[i] = malloc(sizeof(int) * 64 * 64);
}

void	generate_textures(t_control *ctr)
{
	int	x;
	int	y;
	int	xorcolor;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			xorcolor = (x * 256 / 64) ^ (y * 256 / 64);
			ctr->texture[0][64 * y + x] = 65536 * 192 * (x % 16 && y % 16);
			ctr->texture[1][64 * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
			ctr->texture[2][64 * y + x] = 256 * xorcolor;
			ctr->texture[3][64 * y + x] = 65536 * 254 * (x != y && x != 64 - y);
		}
	}
}

int	main(void)
{
	t_control	control;

	fill_control(&control);
	generate_textures(&control);
	ft_mlx(&control);
}
