/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:50:50 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/12 11:51:57 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

extern char worldMap[24][24];

void	draw_tex_line(t_control *ctr, int x)
{
	int	y;

	y = ctr->ray->drawstart;
	while (y < ctr->ray->drawend)
	{
		mlx_place_pixel(ctr->data, x, y, ctr->tex->buffer[y][x]);
		y++;
	}
}

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

void	init_screen(t_control *ctr)
{
	ctr->data->mlx_win = mlx_new_window(ctr->data->mlx_ptr, \
		ctr->width, ctr->height, "cub3d");
	load_textures(ctr);
	ctr->data->img = mlx_new_image(ctr->data->mlx_ptr, ctr->width, \
		ctr->height);
	ctr->data->img_addr = mlx_get_data_addr(ctr->data->img, \
		&ctr->data->bits_per_pixel, &ctr->data->line_length, \
		&ctr->data->endian);
	fill_background(ctr);
	ray_loop(ctr);
	mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
		ctr->data->img, 0, 0);
}

void	ft_mlx(t_control *ctr)
{
	t_data	data;
	t_key	key;
	t_tex	tex;
	t_ray	ray;

	ctr->key = &key;
	init_key(&key);
	ctr->data = &data;
	ctr->tex = &tex;
	ctr->ray = &ray;
	ctr->data->mlx_ptr = mlx_init();
	init_screen(ctr);
	mlx_hook(ctr->data->mlx_win, KEY_PRESS, 0, &key_press, ctr);
	mlx_hook(ctr->data->mlx_win, KEY_RELEASE, 0, &key_release, ctr);
	mlx_hook(ctr->data->mlx_win, EXIT, 0, (void *)exit, 0);
	mlx_loop_hook(ctr->data->mlx_ptr, &hook_loop, ctr);
	mlx_loop(ctr->data->mlx_ptr);
}
