/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:32:13 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/03 09:07:23 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	char		*img_addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;

}				t_data;

typedef struct s_control
{
	char	**map;
	char	*str;
	int		error;
	int		fd;
	int		height;
	int		width;
	unsigned long		ceiling;
	unsigned long		floor;
	t_data	*data;

}					t_control;

#endif