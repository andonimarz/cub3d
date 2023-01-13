/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:32:43 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 11:12:19 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	file_size(int fd)
{
	char	c;
	int		size;

	size = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			size++;
	}
	return (size);
}

int	txt_file_check(char *route)
{
	int	fd;

	fd = open(route, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
