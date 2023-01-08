/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/08 12:23:38 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../include/struct.h"

int		arg_checker(int ac, char **av);
int		ft_checkfile(const char *file);

//cub3d.c

long	ft_get_time(void);

//raycasting.c

void	ray_loop(t_control *ctr);

//mlx_tools.c

void	mlx_place_pixel(t_data *data, int x, int y, int color);
void	fill_background(t_control *control);
void	ft_mlx(t_control *ctr);
void	draw_line(t_control *ctr, int x);

//moves.c

int		move_ws(t_control *ctr, int key);
int		move_ad(t_control *ctr, int key);
int		rotate_r(t_control *img);
int		rotate_l(t_control *img);

#endif