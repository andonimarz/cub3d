/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:50:50 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/05 10:41:33 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/mlx_tools.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

//mapa de prueba
/* int	worldMap[24][24]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
}; */

void	mlx_place_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_background(t_control *control)
{
	int	x;
	int	y;

	x = 0;
	while (x < control->width)
	{
		y = control->height / 2 - 1;
		while (++y < control->height)
			mlx_place_pixel(control->data, x, y, control->floor);
		x++;
	}
	x = 0;
	while (x < control->width)
	{
		y = -1;
		while (++y < control->height / 2)
			mlx_place_pixel(control->data, x, y, control->ceiling);
		x++;
	}
}

void	draw_line(t_control *ctr, int x)
{
	int	y;

	y = ctr->drawstart;
	//printf("Color: %lu, Draw start:%d, draw end: %d\n", ctr->color, ctr->drawstart, ctr->drawend);
	while (y < ctr->drawend)
	{
		mlx_place_pixel(ctr->data, x, y, ctr->color);
		y++;
	}
}

//WORK IN PROGRESS
/* void	ft_inputs(int key, t_control *ctr)
{
	int		move;

	move = 0;
	if (key == 53)
		ft_exit(ctr);
	if (key == 0)
		if (worldMap[(int)(ctr->pos_x + ctr->dir_x * ctr->movespeed)]\
		[(int)(ctr->pos_y)] == false)
			ctr->pos_x += ctr->dir_x * ctr->movespeed;
    	if (worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
			posY += dirY * moveSpeed;
	if (key == 2)
		move = ft_updown(ctr, key);
	if (key == 13)
		move = ft_leftright(ctr, key);
	if (key == 1)
		move = ft_leftright(ctr, key);
	if (move)
	{
		ft_fill_map(ctr);
		ft_putstr_fd("Steps: ", 1);
		ft_putstr_fd(ft_itoa(ctr->data->moves_count), 1);
		ft_putchar_fd('\n', 1);
	}
	return (1);
} */

void	ft_mlx(t_control *ctr)
{
	t_data	data;

	ctr->data = &data;
	ctr->data->mlx_ptr = mlx_init();
	ctr->data->mlx_win = mlx_new_window(ctr->data->mlx_ptr, \
		ctr->width, ctr->height, "cub3d");
	ctr->data->img = mlx_new_image(ctr->data->mlx_ptr, ctr->width, \
		ctr->height);
	ctr->data->img_addr = mlx_get_data_addr(ctr->data->img, \
	&ctr->data->bits_per_pixel, &ctr->data->line_length, &ctr->data->endian);
	fill_background(ctr);
	ray_loop(ctr);
	mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
		ctr->data->img, 0, 0);
	//mlx_key_hook(ctr->data->mlx_win, &ft_inputs, ctr);
	mlx_hook(ctr->data->mlx_win, 17, 0, (void *)exit, 0);
	mlx_loop(ctr->data->mlx_ptr);
}

/* unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
} */