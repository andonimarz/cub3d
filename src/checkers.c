/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:19:16 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 11:10:11 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ext_checker(char *str, char *ext)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] == ext[0] && str[len - 2] == ext[1]
		&& str[len - 1] == ext[2] && str[len] == ext[3])
		return (1);
	return (0);
}

int	arg_checker(int ac, char **av)
{
	if (ac != 2)
		return (printf("Invalid arguments\n"), 1);
	else
	{
		if (!ext_checker(av[1], ".cub"))
			return (printf("Wrong map format, expected: *.cub\n"), 1);
	}
	return (0);
}
