/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:23:08 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 12:36:21 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "free_error.h"
#include "file.h"
#include "str_tools.h"
#include <fcntl.h>

static void	get_size(char *av, t_file *file)
{
	file->fd = open(av, O_RDONLY);
	if (file->fd == -1)
		file_error(av);
	file->size = file_size(file->fd) + 1;
	close(file->fd);
}

static int	invalid_lines(char **my_map, t_file *file)
{
	int		i;
	char	*tmp;

	i = -1;
	file->map_start = 0;
	file->map_end = 0;
	while (my_map[++i])
	{
		tmp = ft_strtrim(my_map[i], " ");
		if (tmp[0] == '1' && file->map_start == 0)
			file->map_start = i;
		if (tmp[0] != 'N' && tmp[0] != 'S' && tmp[0] != 'E'
			&& tmp[0] != 'W' && tmp[0] != '\n' && tmp[0] != '1'
			&& tmp[0] != 'F' && tmp[0] != 'C')
			return (free_array(my_map), free(tmp), 1);
		free(tmp);
	}
	return (0);
}

static char	**copy_map(t_state *state, t_file *file, char *av)
{
	char	**my_map;
	int		i;

	i = -1;
	get_size(av, file);
	file->fd = open(av, O_RDONLY);
	my_map = (char **)ft_calloc(file->size + 2, sizeof(char *));
	if (!my_map)
		return (NULL);
	while (++i < file->size)
		my_map[i] = get_next_line(file->fd);
	my_map[i] = 0;
	if (invalid_lines(my_map, file))
		exit_with_error(state, "INVALID LINE IN FILE");
	my_map[i] = check_last_line(get_next_line(file->fd), my_map, state, file);
	if (my_map[i] != NULL)
		my_map[i + 1] = NULL;
	close(file->fd);
	return (my_map);
}

int	parse_file(char *av, t_state *state)
{
	t_file	file;
	char	**my_map;

	my_map = copy_map(state, &file, av);
	txt_color_errors(state, &file, my_map);
	parse_map(state, &file, my_map);
	map_errors(state);
	free_array(my_map);
	return (0);
}
