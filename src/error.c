/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:43:14 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/18 10:20:38 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "state.h"
#include "free_error.h"
#include<stdio.h>
#include<stdlib.h>

void	file_error(char *av)
{
	printf("FILE NOT FOUND: %s\n", av);
	exit(0);
}

int	exit_with_error(t_state *state, char *str)
{
	printf("%s\n", str);
	free_state(state);
	exit(0);
	return (0);
}

int	exit_without_error(t_state *state)
{
	free_state(state);
	exit(0);
	return (0);
}
