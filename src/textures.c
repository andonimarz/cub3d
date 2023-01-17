/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:11 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/17 10:13:57 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include"free_error.h"
#include <stdio.h>
#include <stdlib.h>

static void	check_tex(t_control *ctr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!ctr->tex->tex_ptr[i])
		{
			destroy_textures(ctr);
			exit_with_error(ctr->state, "ERROR: BAD TEXTURE FILE");
		}
		i++;
	}
}

static void	load_textures2(t_control *ctr)
{
	t_data	*data;
	t_tex	*tex;

	data = ctr->data;
	tex = ctr->tex;
	if (tex->tex_ptr[2])
		tex->texture[2] = (int *)mlx_get_data_addr(tex->tex_ptr[2], \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	tex->tex_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr, \
		ctr->state->txt.west, &tex->texw, &tex->texh);
	if (tex->tex_ptr[3])
		tex->texture[3] = (int *)mlx_get_data_addr(tex->tex_ptr[3], \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	check_tex(ctr);
}

void	load_textures(t_control *ctr)
{
	t_data	*data;
	t_tex	*tex;

	data = ctr->data;
	tex = ctr->tex;
	tex->tex_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr, \
		ctr->state->txt.east, &tex->texw, &tex->texh);
	if (tex->tex_ptr[0])
		tex->texture[0] = (int *)mlx_get_data_addr(tex->tex_ptr[0], \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	tex->tex_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr, \
		ctr->state->txt.north, &tex->texw, &tex->texh);
	if (tex->tex_ptr[1])
		tex->texture[1] = (int *)mlx_get_data_addr(tex->tex_ptr[1], \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	tex->tex_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr, \
		ctr->state->txt.south, &tex->texw, &tex->texh);
	load_textures2(ctr);
}

void	destroy_textures(t_control *ctr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ctr->tex->tex_ptr[i])
			mlx_destroy_image(ctr->data->mlx_ptr, ctr->tex->tex_ptr[i]);
		i++;
	}
	mlx_destroy_window(ctr->data->mlx_ptr, ctr->data->mlx_win);
}
