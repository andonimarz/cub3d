/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:19:16 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/11/22 13:22:39 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int	ext_checker(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] == '.' && str[len - 2] == 'c'
		&& str[len - 1] == 'u' && str[len] == 'b')
		return (0);
	return (1);
}

int	arg_checker(int ac, char **av)
{
	if (ac != 2)
		return (printf("Invalid arg number\n"), 1);
	else
	{
		if (ext_checker(av[1]))
			return (printf("Wrong map format, expected: *.cub\n"), 1);
	}
	return (0);
}
