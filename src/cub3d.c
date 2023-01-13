/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:14:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 12:24:34 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include "state.h"
#include "free_error.h"
#include "file.h"
#include <sys/time.h>


long	ft_get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int	main(int ac, char **av)
{
	t_control	control;
	t_parse		parse;
	t_state		state;

	if (!init_state(&state))
		return (exit_with_error(&state, "Error initializing"));
	if (arg_checker(ac, av))
		return (1);
	parse_file(av[1], &state);
	init_parse(&parse);
	control.parse = &parse;
	init_control(&control);
	mlx_main_loop(&control);
	exit_without_error(&state);
}
