/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:32:44 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/17 13:49:49 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "free_error.h"
#include "str_tools.h"

static int	check_nbrs(char **digits)
{
	int	i;
	int	j;

	i = 0;
	while (digits[i])
	{
		j = 0;
		while (digits[i][j])
		{
			if (!((digits[i][j] >= '0' && digits[i][j] <= '9') ||
			digits[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	save_digits(char *line, int clrs[3])
{
	char	**digits;
	int		i;

	i = 0;
	digits = ft_split(line, ',');
	while (digits[i])
		i++;
	if (i != 3 || !check_nbrs(digits))
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

static int	check_digits(t_color *color, char *tmp, char c)
{
	if (c == 'F')
	{
		if (!save_digits(color->floor_line, color->floor))
		{
			free(tmp);
			return (0);
		}
		return (1);
	}
	else if (c == 'C')
	{
		if (!save_digits(color->ceiling_line, color->ceiling))
		{
			free(tmp);
			return (0);
		}
		return (1);
	}
	return (0);
}

int	assign_colors(t_color *color, t_file *file, char *line, int i)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp && !ft_strncmp(tmp, "F", 1) && (color->floor[0] == -1
			|| color->floor[1] == -1 || color->floor[2] == -1)
		&& i < file->map_start)
	{
		color->floor_line = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
		if (!check_digits(color, tmp, 'F'))
			return (0);
	}
	else if (tmp && !ft_strncmp(tmp, "C", 1) && (color->ceiling[0] == -1
			|| color->ceiling[1] == -1 || color->ceiling[2] == -1)
		&& i < file->map_start)
	{
		color->ceiling_line = ft_substr(tmp, skip(tmp, find_space(tmp)),
				ft_strlen(tmp) - skip(tmp, find_space(tmp))
				- skip_last_spaces(tmp) - 1);
		if (!check_digits(color, tmp, 'C'))
			return (0);
	}
	free(tmp);
	return (1);
}
