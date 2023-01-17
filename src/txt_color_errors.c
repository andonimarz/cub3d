/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_color_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:58:11 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/17 10:32:36 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "file.h"
#include "free_error.h"
#include "str_tools.h"

static int	assign_route(t_txt *txt, t_file *file, char *line, int i)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp && !ft_strncmp(tmp, "NO", 2) && !txt->north
		&& i < file->map_start)
		txt->north = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
	else if (tmp && !ft_strncmp(tmp, "SO", 2) && !txt->south
		&& i < file->map_start)
		txt->south = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
	else if (tmp && !ft_strncmp(tmp, "WE", 2) && !txt->west
		&& i < file->map_start)
		txt->west = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
	else if (tmp && !ft_strncmp(tmp, "EA", 2) && !txt->east
		&& i < file->map_start)
		txt->east = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
	free(tmp);
	return (1);
}

static int	check_paths(t_txt *txt)
{
	if (!ext_checker(txt->north, ".xpm")
		|| !ext_checker(txt->south, ".xpm")
		|| !ext_checker(txt->east, ".xpm")
		|| !ext_checker(txt->west, ".xpm")
		|| !txt_file_check(txt->north)
		|| !txt_file_check(txt->south)
		|| !txt_file_check(txt->east)
		|| !txt_file_check(txt->west))
		return (0);
	return (1);
}

int	check_and_free(t_state *state, t_txt *txt, t_color *color, char **my_map)
{
	if (!txt->north || !txt->south || !txt->west || !txt->east)
	{
		free_array(my_map);
		exit_with_error(state, "ERROR: MISSING TEXTURE");
	}
	else if (!check_paths(txt))
	{
		free_array(my_map);
		exit_with_error(state, "ERROR: INVALID TEXTURE FILE");
	}
	else if (!color->ceiling_line || !color->floor_line)
	{
		free_array(my_map);
		exit_with_error(state, "ERROR: MISSING COLOUR");
	}
	return (1);
}

int	txt_color_errors(t_state *state, t_file *file, char **my_map)
{
	int		i;

	i = 0;
	init_txt_color(&state->txt, &state->color);
	while (my_map[i])
	{
		if (my_map[i][0] == '\n')
			i++;
		else
		{
			assign_route(&state->txt, file, my_map[i], i);
			if (!assign_colors(&state->color, file, my_map[i], i))
			{
				free_array(my_map);
				exit_with_error(state, "ERROR: COLOUR ERROR");
			}
			i++;
		}
	}
	check_and_free(state, &state->txt, &state->color, my_map);
	return (1);
}
