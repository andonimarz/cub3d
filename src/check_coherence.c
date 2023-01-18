/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coherence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:39:21 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/18 10:31:20 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_error.h"
#include "checkers.h"
#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>

static int	check_duplicates(char **my_map, char *str, int line, t_coher *c)
{
	int		i;
	char	*tmp;

	i = -1;
	c->items = c->items + 1;
	while (my_map[++i])
	{
		tmp = ft_strtrim(my_map[i], " ");
		if (tmp && !ft_strncmp(tmp, str, ft_strlen(str)) && line != i)
			return (1);
		free(tmp);
	}
	return (0);
}

static int	check_num(char *tmp, t_coher *c, int i)
{
	if (tmp && !ft_strncmp(tmp, "1", 1))
	{
		if (c->items < 6)
			return (2);
		if (c->map_start == 0)
			c->map_start = i;
	}
	else if (tmp && tmp[0] != '\n')
		return (3);
	return (0);
}

static void	parse_lines(char **my_map, t_coher *c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (my_map[i] && my_map[i + 1] && !c->error)
	{
		tmp = ft_strtrim(my_map[i], " ");
		if (tmp && !ft_strncmp(tmp, "NO", 2))
			c->error = check_duplicates(my_map, "NO", i, c);
		else if (tmp && !ft_strncmp(tmp, "SO", 2))
			c->error = check_duplicates(my_map, "SO", i, c);
		else if (tmp && !ft_strncmp(tmp, "WE", 2))
			c->error = check_duplicates(my_map, "WE", i, c);
		else if (tmp && !ft_strncmp(tmp, "EA", 2))
			c->error = check_duplicates(my_map, "EA", i, c);
		else if (tmp && !ft_strncmp(tmp, "C", 1))
			c->error = check_duplicates(my_map, "C", i, c);
		else if (tmp && !ft_strncmp(tmp, "F", 1))
			c->error = check_duplicates(my_map, "F", i, c);
		else
			c->error = check_num(tmp, c, i);
		free(tmp);
		i++;
	}
}

void	check_coherence(t_state *state, char **my_map)
{
	t_coher	c;

	c.error = 0;
	c.items = 0;
	c.map_start = 0;
	c.prev_len = 0;
	c.player = 0;
	parse_lines(my_map, &c);
	if (!c.error)
		check_map_limit(my_map, &c);
	if (c.error)
		free_array(my_map);
	if (c.error == 1)
		exit_with_error(state, "ERROR: DUPLICATED PARAMETER");
	else if (c.error == 2)
		exit_with_error(state, "ERROR: MISSING PARAMETER BEFORE MAP");
	else if (c.error == 3)
		exit_with_error(state, "ERROR: WRONG PARAMETERS");
	else if (c.error == 4)
		exit_with_error(state, "ERROR: WRONG MAP FORMAT");
	else if (c.error == 5)
		exit_with_error(state, "ERROR: NO PLAYER IN MAP");
	else if (c.error == 6)
		exit_with_error(state, "ERROR: TOO MANY PLAYERS IN MAP");
}
