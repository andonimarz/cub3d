/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/03 09:47:31 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "../include/struct.h"
#include "../minilibx/mlx.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int	f_rgb[3] = {200, 100, 0};

int	c_rgb[3] = {225, 30, 0};

//mapa de prueba en cub3d.c
int	worldMap[mapWidth][mapHeight]=
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
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	mlx_place_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_floor(t_control *control)
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
}

void	fill_ceiling(t_control *control)
{
	int	x;
	int	y;

	x = 0;
	while (x < control->width)
	{
		y = -1;
		while (++y < control->height / 2)
			mlx_place_pixel(control->data, x, y, control->ceiling);
		x++;
	}
}

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
	fill_floor(ctr);
	fill_ceiling(ctr);
	mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
		ctr->data->img, 0, 0);
	mlx_loop(ctr->data->mlx_ptr);
}

/* unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
} */

void	fill_control(t_control *control)
{
	control->height = screenHeight;
	control->width = screenWidth;
	control->ceiling = 0x0000ff;
	control->floor = 0xff0000;
}

int	main(void)
{
	t_control control;
	
	/* if (arg_checker(ac, av))
		return (1); */
	fill_control(&control);
	ft_mlx(&control);
}
