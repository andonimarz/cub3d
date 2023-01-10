/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:11 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/10 13:17:47 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	load_textures(t_control *ctr)
{
	int		i;
	void	*ptr;
	t_data	*data;

	data = ctr->data;
	i = -1;
	while (++i < 4)
		ctr->tex[i] = malloc(sizeof(int) * 64 * 64);
	ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/EA.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->tex[0] = (int *)mlx_get_data_addr(ptr, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/NO.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->tex[1] = (int *)mlx_get_data_addr(ptr, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/SO.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->tex[2] = (int *)mlx_get_data_addr(ptr, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./img/WE.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->tex[3] = (int *)mlx_get_data_addr(ptr, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
}
