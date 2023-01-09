/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/09 09:30:58 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 			53
# define KEY_PRESS		2
# define KEY_RELEASE	3
# define EXIT			17

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

typedef struct s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
}				t_key;

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
	t_key				*key;

}					t_control;

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

//hooks.c

int		ft_inputs(t_control *ctr);
int		key_press(int key, t_control *ctr);
int		key_release(int key, t_control *ctr);

#endif