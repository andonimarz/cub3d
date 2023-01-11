/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:11 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/11 11:52:57 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	load_textures(t_control *ctr)
{
	t_data	*data;

	data = ctr->data;
	ctr->tex_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/EA.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->texture[0] = (int *)mlx_get_data_addr(ctr->tex_ptr[0], \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ctr->tex_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/NO.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->texture[1] = (int *)mlx_get_data_addr(ctr->tex_ptr[1], \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ctr->tex_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/SO.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->texture[2] = (int *)mlx_get_data_addr(ctr->tex_ptr[2], \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	ctr->tex_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/WE.xpm", \
		&ctr->texw, &ctr->texh);
	ctr->texture[3] = (int *)mlx_get_data_addr(ctr->tex_ptr[3], \
	&data->bits_per_pixel, &data->line_length, &data->endian);
}

/* void	destroy_textures(t_control *ctr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(ctr->data->mlx_ptr, ctr->tex_ptr[i]);
		i++;
	}
} */
