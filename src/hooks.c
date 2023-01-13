/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:32:04 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/13 08:57:31 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

#include <stdio.h>

int	key_press(int key, t_control *ctr)
{
	if (key == ESC)
		exit_mlx(ctr);
	if (key == 13)
		ctr->key->w = 1;
	if (key == 0)
		ctr->key->a = 1;
	if (key == 1)
		ctr->key->s = 1;
	if (key == 2)
		ctr->key->d = 1;
	if (key == 123)
		ctr->key->l = 1;
	if (key == 124)
		ctr->key->r = 1;
	return (0);
}

int	key_release(int key, t_control *ctr)
{
	if (key == 13)
		ctr->key->w = 0;
	if (key == 0)
		ctr->key->a = 0;
	if (key == 1)
		ctr->key->s = 0;
	if (key == 2)
		ctr->key->d = 0;
	if (key == 123)
		ctr->key->l = 0;
	if (key == 124)
		ctr->key->r = 0;
	return (0);
}

int	exit_mlx(t_control *ctr)
{
	(void)ctr;
	printf("gg\n");
	destroy_textures(ctr);
	exit (0);
	return (0);
}
