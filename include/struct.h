/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:32:13 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/05 09:14:28 by amarzana         ###   ########.fr       */
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
	int					height;
	int					width;
	unsigned long		ceiling;
	unsigned long		floor;
	unsigned long		white;
	unsigned long		green;
	unsigned long		black;
	unsigned long		color;
	double				pos_x;			//Player start position
	double				pos_y;			//Player start position
	double				dir_x;			//Player direction
	double				dir_y;			//Player direction
	double				plane_x;		//Camera plane
	double				plane_y;		//Camera plane
	double				time;			//Actual time
	double				old_time;		//Previous time
	double				camera_x;		//x-coordinate in camera plane that the current x-coordinate of the screen represents
	double				raydir_x;		//Direction of the ray
	double				raydir_y;		//Direction of the ray
	double				sidedist_x;		//distance the ray has to travel from its start position to the first x-side
	double				sidedist_y;		//distance the ray has to travel from its start position to the first y-side
	double				deltadist_x;	//distance the ray has to travel to go from 1 x-side to the next x-side
	double				deltadist_y;	//distance the ray has to travel to go from 1 y-side to the next y-side
	double				perpwalldist;	//wall distance perspective
	int					step_x;			//what direction to step in x-direction (either +1 or -1)
	int					step_y;			//what direction to step in y-direction (either +1 or -1)
	int					map_x;			//which box of the map we're in
	int					map_y;			//which box of the map we're in
	int					hit;			//checks if a wall has been hit
	int					side;			//if 1 a NS wall was hit. If 0 a WE wall.
	int					lineheight;		//The height of line to draw
	int					drawstart;		//The lowest pixel to draw
	int					drawend;		//The highest pixel to draw
	double				frametime;
	double				movespeed;
	double				rotspeed;
	t_data				*data;

}					t_control;

#endif