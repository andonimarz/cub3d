/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:29:59 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 10:05:42 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include"libft.h"
#include<stdlib.h>

void	init_txt_color(t_txt *txt, t_color *color)
{
	txt->north = NULL;
	txt->south = NULL;
	txt->east = NULL;
	txt->west = NULL;
	color->ceiling[0] = -1;
	color->ceiling[1] = -1;
	color->ceiling[2] = -1;
	color->floor[0] = -1;
	color->floor[1] = -1;
	color->floor[2] = -1;
	color->ceiling_line = NULL;
	color->floor_line = NULL;
}

int	free_color(t_color *color)
{
	if (!color)
		return (0);
	if (color->ceiling_line)
		free(color->ceiling_line);
	if (color->floor_line)
		free(color->floor_line);
	ft_memset(color, 0, sizeof(t_color));
	return (1);
}

int	free_txt(t_txt *txt)
{
	if (!txt)
		return (0);
	if (txt->north)
		free(txt->north);
	if (txt->south)
		free(txt->south);
	if (txt->east)
		free(txt->east);
	if (txt->west)
		free(txt->west);
	ft_memset(txt, 0, sizeof(t_txt));
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	i = 0;
	if (array)
		free(array);
}
