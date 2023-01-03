/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:50:50 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/03 09:57:31 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/mlx_tools.h"
#include "../minilibx/mlx.h"

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
	mlx_put_image_to_window(ctr->data->mlx_ptr, ctr->data->mlx_win, \
		ctr->data->img, 0, 0);
	mlx_loop(ctr->data->mlx_ptr);
}

/* unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
} */