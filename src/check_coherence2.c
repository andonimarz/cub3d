/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coherence2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:36:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/18 10:31:08 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "checkers.h"

void	check_map_limit_rev(char **my_map, t_coher *c, int i)
{
	int	j;

	j = 0;
	i--;
	while (my_map[i] && i >= c->map_start)
	{
		j = 0;
		while (my_map[i][j])
		{
			if (my_map[i][j] != '1' && my_map[i][j] != ' '
			&& my_map[i][j] != '\n' && my_map[i][j] != '\t' && j >= c->prev_len)
				c->error = 4;
			j++;
		}
		c->prev_len = j;
		i--;
	}
	if (c->player == 0)
		c->error = 5;
	if (c->player > 1)
		c->error = 6;
}

void	check_map_limit(char **my_map, t_coher *c)
{
	int	i;
	int	j;

	i = c->map_start;
	while (my_map[i])
	{
		j = -1;
		while (my_map[i][++j])
		{
			if (my_map[i][j] != '1' && my_map[i][j] != ' '
			&& my_map[i][j] != '\n' && my_map[i][j] != '\t' && j >= c->prev_len)
				c->error = 4;
			if (my_map[i][j] == 'W' || my_map[i][j] == 'N'
			|| my_map[i][j] == 'E' || my_map[i][j] == 'S')
				c->player++;
		}
		c->prev_len = j;
		if (my_map[i][j - 1] == '\n')
		c->prev_len -= 1;
		i++;
	}
	check_map_limit_rev(my_map, c, i);
}
