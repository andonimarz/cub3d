/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:51:19 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/03 09:57:52 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

void	mlx_place_pixel(t_data *data, int x, int y, int color);
void	fill_background(t_control *control);
void	ft_mlx(t_control *ctr);

#endif