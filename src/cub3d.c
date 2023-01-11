/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 12:49:27 by amarzana         ###   ########.fr       */
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

void	init_control(t_control *control)
{
	control->height = screenHeight;
	control->width = screenWidth;
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
	/* control->texh = 64;
	control->texw = 64; */
}

int	main(void)
{
	t_control	control;

	init_control(&control);
	ft_mlx(&control);
}
