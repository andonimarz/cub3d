/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/09 09:34:05 by amarzana         ###   ########.fr       */
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
	control->height = screenHeight;
	control->width = screenWidth;
	control->ceiling = 0x0000ff;
	control->floor = 0xff0000;
	control->black = 0x000000;
	control->white = 0xffffff;
	control->green = 0x00ff00;
	control->pos_x = 22;
	control->pos_y = 12;
	control->dir_x = -1;
	control->dir_y = 0;
	control->plane_x = 0;
	control->plane_y = 0.66;
	control->time = ft_get_time();
	control->old_time = 0;
	control->frametime = 0;
}

int	main(void)
{
	t_control control;
	
	/* if (arg_checker(ac, av))
		return (1); */
	fill_control(&control);
	ft_mlx(&control);
}
