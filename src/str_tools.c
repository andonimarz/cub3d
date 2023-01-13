/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:26:52 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/12 12:02:53 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"
#include"free_error.h"
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

int	find_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int	skip(char *str, int start)
{
	int	i;

	i = start;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

char	*check_last_line(char *str, char **my_map, t_state *state, t_file *file)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (str[0] != 'N' && str[0] != 'S' && str[0] != 'E'
		&& str[0] != 'W' && str[0] != '\n' && str[0] != '1'
		&& str[0] != 'F' && str[0] != 'C')
	{
		free(str);
		free_array(my_map);
		close(file->fd);
		exit_with_error(state, "INVALID LINE IN FILE");
		return (NULL);
	}
	return (str);
}
