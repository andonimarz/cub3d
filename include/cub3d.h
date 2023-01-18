/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:05 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/18 10:30:43 by amarzana         ###   ########.fr       */
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
	int					texw;
	int					texh;
	int					buffer[480][640];
	int					*texture[4];
	void				*tex_ptr[4];
	int					tex_num;
	double				wallx;
	int					tex_x;
	double				step;
	double				tex_pos;
	int					tex_y;
	int					tex_color;
}				t_tex;

typedef struct s_ray
{
	double				camera_x;
	double				raydir_x;
	double				raydir_y;
	double				sidedist_x;
	double				sidedist_y;
	double				deltadist_x;
	double				deltadist_y;
	double				perpwalldist;
	int					step_x;
	int					step_y;
	int					map_x;
	int					map_y;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
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
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				time;
	double				old_time;
	double				frametime;
	double				movespeed;
	double				rotspeed;
	t_data				*data;
	t_key				*key;
	t_tex				*tex;
	t_ray				*ray;
	t_state				*state;
}					t_control;

typedef struct s_coher
{
	int					error;
	int					map_start;
	int					prev_len;
	int					items;
	int					player;
}					t_coher;

//get_next_line.c
char			*get_next_line(int fd);

//init_free.c
void			init_txt_color(t_txt *txt, t_color *color);

//color_errors.c
int				assign_colors(t_color *color, t_file *file, char *line, int i);

//cub3d.c
long			ft_get_time(void);

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
unsigned long	rgb_to_hex(int red, int green, int blue);
void			init_control(t_control *control);
void			init_key(t_key *key);

#endif