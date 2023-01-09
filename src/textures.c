/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:11 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/09 13:44:40 by amarzana         ###   ########.fr       */
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

	i = 0;
	while (i < 4)
	{
		ctr->textures[i] = malloc(sizeof(int) * ctr->texheight * ctr->texwidth);
		i++;
	}
	ptr = mlx_xpm_file_to_image(ctr->data->mlx_ptr, "./img/EA.xpm", \
		&ctr->texheight, &ctr->texwidth);
	//printf("HERE\n");
	if (!ptr)
		printf("Error, one or more files are not xpm\n");
	ctr->textures[0] = (int *)mlx_get_data_addr(ptr, &ctr->data->bits_per_pixel, \
		&ctr->data->line_length, &ctr->data->endian);
	ptr = mlx_xpm_file_to_image(ctr->data->mlx_ptr, "./img/NO.xpm", \
		&ctr->texheight, &ctr->texwidth);
	if (!ptr)
		printf("Error, one or more files are not xpm\n");
	ctr->textures[1] = (int *)mlx_get_data_addr(ptr, &ctr->data->bits_per_pixel, \
		&ctr->data->line_length, &ctr->data->endian);
	ptr = mlx_xpm_file_to_image(ctr->data->mlx_ptr, "./img/SO.xpm", \
		&ctr->texheight, &ctr->texwidth);
	if (!ptr)
		printf("Error, one or more files are not xpm\n");
	ctr->textures[2] = (int *)mlx_get_data_addr(ptr, &ctr->data->bits_per_pixel, \
		&ctr->data->line_length, &ctr->data->endian);
	ptr = mlx_xpm_file_to_image(ctr->data->mlx_ptr, "./img/WE.xpm", \
		&ctr->texheight, &ctr->texwidth);
	if (!ptr)
		printf("Error, one or more files are not xpm\n");
	ctr->textures[3] = (int *)mlx_get_data_addr(ptr, &ctr->data->bits_per_pixel, \
		&ctr->data->line_length, &ctr->data->endian);
}
