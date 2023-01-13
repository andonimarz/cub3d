/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:32:44 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 10:37:54 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "free_error.h"
#include "str_tools.h"

static int	save_digits(char *line, int clrs[3])
{
	char	**digits;
	int		i;

	i = 0;
	digits = ft_split(line, ',');
	while (digits[i])
		i++;
	if (i != 3)
	{
		free_array(digits);
		return (0);
	}
	i = 0;
	while (digits[i])
	{
		clrs[i] = ft_atoi_reduced(digits[i]);
		if (clrs[i] == -1)
			return (free_array(digits), 0);
		i++;
	}
	free_array(digits);
	return (1);
}

int	assign_colors(t_color *color, t_file *file, char *line, int i)
{
	if (line && !ft_strncmp(line, "F", 1) && (color->floor[0] == -1
			|| color->floor[1] == -1 || color->floor[2] == -1)
		&& i < file->map_start)
	{
		color->floor_line = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		if (!save_digits(color->floor_line, color->floor))
			return (0);
	}
	else if (line && !ft_strncmp(line, "C", 1) && (color->ceiling[0] == -1
			|| color->ceiling[1] == -1 || color->ceiling[2] == -1)
		&& i < file->map_start)
	{
		color->ceiling_line = ft_substr(line, skip(line, find_space(line)),
				ft_strlen(line) - skip(line, find_space(line)) - 1);
		if (!save_digits(color->ceiling_line, color->ceiling))
			return (0);
	}
	return (1);
}
