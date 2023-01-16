/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/16 13:19:30 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 			53
# define KEY_PRESS		2
# define KEY_RELEASE	3
# define EXIT			17
# define SCREENWIDTH	640
# define SCREENHEIGHT	480

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

typedef struct s_tex
{
	int					texw;				//Width of textures
	int					texh;				//Height of textures
	int					buffer[480][640];	//Screen buffer[height][width]
	int					*texture[4];		//Addr of the 4 textures
	void				*tex_ptr[4];		//Ptr of the 4 textures
	int					tex_num;			//value of the current map square minus 1
	double				wallx;				//exact value where the wall was hit
	int					tex_x;				//x coordinate on the texture 
	double				step;				//How much to increase the texture coordinate per screen pixel
	double				tex_pos;			//Starting texture coordinate
	int					tex_y;				//y coordinate on the texture
	int					tex_color;
}				t_tex;

typedef struct s_ray
{
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
}				t_ray;

typedef struct s_parse
{
	int					cei[3];
	int					flo[3];
	char				player;
	double				pos_x;
	double				pos_y;
	char				**map;
}				t_parse;

typedef struct s_txt
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_txt;

typedef struct s_color
{
	int		floor[3];
	int		ceiling[3];
	char	*ceiling_line;
	char	*floor_line;
}	t_color;
typedef struct s_file
{
	int	fd;
	int	size;
	int	map_start;
	int	map_end;	
}	t_file;

typedef struct s_state
{
	t_txt	txt;
	t_color	color;
	char	**only_map;

}	t_state;

typedef struct s_control
{
	int					height;
	int					width;
	unsigned long		ceiling;
	unsigned long		floor;
	char				player;
	double				pos_x;			//Player start position
	double				pos_y;			//Player start position
	double				dir_x;			//Player direction
	double				dir_y;			//Player direction
	double				plane_x;		//Camera plane
	double				plane_y;		//Camera plane
	double				time;			//Actual time
	double				old_time;		//Previous time
	double				frametime;		//Time between frames
	double				movespeed;		//Movespeed proportional to frametime
	double				rotspeed;		//Rotspeed proportional to frametime
	t_data				*data;			//Struct for mlx parameters
	t_key				*key;			//Struct for input status
	t_tex				*tex;			//Struct for textures
	t_ray				*ray;			//Struct for raycasting
	t_state				*state;			//Mikel
}					t_control;

int				arg_checker(int ac, char **av);
char			*get_next_line(int fd);
void			init_txt_color(t_txt *txt, t_color *color);
int				assign_colors(t_color *color, t_file *file, char *line, int i);
int				parse_map(t_state *state, t_file *file, char **my_map);

//cub3d.c
long			ft_get_time(void);
void			print_map(char **map);

//hooks.c
int				key_press(int key, t_control *ctr);
int				key_release(int key, t_control *ctr);
int				exit_mlx(t_control *ctr);

//map_tools.c
char			map_player(t_control *ctr);

//loops.c
void			calculate_frametime(t_control *ctr);
void			ray_loop(t_control *ctr);
int				hook_loop(t_control *ctr);
void			mlx_main_loop(t_control *ctr);

//mlx_utils.c
void			mlx_place_pixel(t_data *data, int x, int y, int color);
void			draw_tex_line(t_control *ctr, int x);
void			fill_background(t_control *control);
void			init_screen(t_control *ctr);

//moves.c
int				move_ws(t_control *ctr, int key);
int				move_ad(t_control *ctr, int key);
int				rotate_r(t_control *img);
int				rotate_l(t_control *img);

//raycasting_tex.c
void			get_tex_num(t_control *ctr);
void			get_tex_color(t_control *ctr);
void			fill_buffer(t_control *ctr, int x);
void			clear_buffer(t_control *ctr);

//raycasting.c
void			init_pos_calculate_ray(int x, t_control *ctr);
void			get_deltadist(t_control *ctr);
void			get_step_sidedist(t_control *ctr);
void			dda_algorithm(t_control *ctr);
void			calculate_dist_draw(t_control *ctr);

//textures.c
void			load_textures(t_control *ctr);
void			destroy_textures(t_control *ctr);

//utils.c
void			get_orientation(t_control *ctr);
void			init_parse(t_parse *parse);
unsigned long	rgb_to_hex(int red, int green, int blue);
void			init_control(t_control *control);
void			init_key(t_key *key);

#endif