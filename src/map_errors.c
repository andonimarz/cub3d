/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:37:24 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/17 10:24:57 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include"libft.h"
#include"str_tools.h"
#include"free_error.h"

static int	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\0' && !ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_sides(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (0);
	while (str[i])
	{
		if (ft_strlen(str) == 1 && str[0] == '1')
			return (1);
		if (str[ft_strlen(str) - 1] == '\n')
		{
			if (str[ft_strlen(str) - 2] != '1')
				return (0);
		}
		else
		{
			if (str[ft_strlen(str) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_zero(char **map, int i, int j)
{
	if (map[i][j] == '0')
	{
		if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i - 1][j] != 'N'
			&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E'
			&& map[i - 1][j] != 'W')
			return (0);
		if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && map[i + 1][j] != 'N'
			&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E'
			&& map[i + 1][j] != 'W')
			return (0);
		if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && map[i][j + 1] != 'N'
			&& map[i][j + 1] != 'S' && map[i][j + 1] != 'E'
			&& map[i][j + 1] != 'W')
			return (0);
		if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != 'N'
			&& map[i][j - 1] != 'S' && map[i][j - 1] != 'E'
			&& map[i][j - 1] != 'W')
			return (0);
	}
	return (1);
}

static int	check_player(char **only_map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (only_map[++i])
	{
		j = -1;
		while (only_map[i][++j])
		{
			if ((only_map[i][j] == 'N' || only_map[i][j] == 'S'
				|| only_map[i][j] == 'W' || only_map[i][j] == 'E')
				&& i != x && j != y)
				return (0);
		}
	}
	return (1);
}

static int	char_checker(char **only_map)
{
	int	i;
	int	j;

	i = -1;
	while (only_map[++i])
	{
		j = -1;
		while (only_map[i][++j])
		{
			if (only_map[i][j] != '1' && only_map[i][j] != '0'
				&& only_map[i][j] != 'N' && only_map[i][j] != 'S'
				&& only_map[i][j] != 'W' && only_map[i][j] != 'E'
				&& only_map[i][j] != '\0' && !ft_is_space(only_map[i][j]))
				return (0);
			if (only_map[i][j] == '0')
				if (!check_zero(only_map, i, j))
					return (0);
			if (only_map[i][j] == 'N' || only_map[i][j] == 'S'
				|| only_map[i][j] == 'W' || only_map[i][j] == 'E')
				if (!check_player(only_map, i, j))
					return (0);
		}
	}
	return (1);
}

int	map_errors(t_state *state)
{
	int	i;

	i = 1;
	if (!check_walls(state->only_map[0])
		|| !check_walls(state->only_map[get_array_size(state->only_map) - 1]))
		exit_with_error(state, "ERROR: WRONG MAP FORMAT");
	while (i < get_array_size(state->only_map) - 1)
	{
		if (!check_sides(state->only_map[i]))
			exit_with_error(state, "ERROR: WRONG MAP FORMAT");
		i++;
	}
	if (!char_checker(state->only_map))
		exit_with_error(state, "ERROR: WRONG MAP FORMAT");
	return (1);
}
