/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:03:42 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 11:59:59 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "free_error.h"
#include <stdlib.h>

int	init_state(t_state *state)
{
	ft_memset(state, 0, sizeof(t_state));
	return (1);
}

int	free_state(t_state *state)
{
	if (!state)
		return (0);
	free_color(&state->color);
	free_txt(&state->txt);
	free_array(state->only_map);
	ft_memset(state, 0, sizeof(t_state));
	return (1);
}
