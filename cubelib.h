/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubelib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:20:27 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/27 20:27:23 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBELIB_H
# define CUBELIB_H
# include "mlx.h"
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SPEED 0.1
# define ROTATION 0.1

typedef struct	s_data
{
	char		*linea;
	char		*arg1;
	char		*arg2;
	int			x;
	int			y;
	int			i;
	char		*north;
	char		*east;
	char		*west;
	char		*south;
	char		*sprite;
	int			floor[3];
	int			ceiling[3];
	int			col;
	int			comma;
	int			rgb_error;
	int			mapx;
	int			mapy;
	char		**map;
	int			mapwidth;
	int			coord_check;
	int			c;
	int			n_lines;
	int			rl;
	int			mapstart;
	int			playerx;
	int			playery;
	int			argc;
	int			fd;
	int			res;
	int			n_tex;
	int			s_tex;
	int			w_tex;
	int			e_tex;
	int			sp_tex;
	int			f_color;
	int			c_color;
}				t_data;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		cx;
	int		cy;
	double	distance;
	int		tmp;
}				t_sprite;

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct	s_vars
{

	t_img		norte;
	t_img		sur;
	t_img		este;
	t_img		oeste;
	t_img		suelo;
	t_img		columna;
	t_sprite	*sprite;
	t_img		imagen;
	void		*mlx;
	void		*win;
	int			key;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		px;
	double		py;
	int			texy;
	double		texpos;
	int			texx;
	int			side;
	int			*addr;
	int			text_width;
	int			text_height;
	double		step;
	int			*buffer;
	void		*img;
	void		*addr_img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			line_y;
	double		*zbuffer;
	double		invdet;
	double		t_x;
	double		t_y;
	int			screenx;
	int			sprite_y;
	int			starty;
	int			drawendy;
	int			s_width;
	int			startx;
	int			drawendx;
	double		camx;
	double		rayx;
	double		rayy;
	double		sidedx;
	double		sidedy;
	double		ddistx;
	double		ddisty;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	double		wallx;
	int			num_sprites;
	int			keycode;
	double		pwalldist;
	double		oldirx;
	double		oldplanex;
	int			hit;
	int			drawstart;
	int			drawend;
	int			c;
	int			i;
	int			a;
	int			d;
	int			w;
	int			s;
	int			left;
	int			right;
	int			screenheight;
	int			screenwidth;
	char		**worldmap;
	int			mapheight;
	int			mapwidth;
	int			sky;
	int			floor;
	int			localx;
	int			localy;
	int			tex_x;
	int			tex_y;
}				t_vars;

void			my_mlx_pixel_put(t_img *imagen, int x, int y, int color);
void			draw_walls(int x, int drawstart, int drawend, int color,
	t_img *img, t_vars *vars);
void			load_textures(t_vars *vars, t_data *data);
void			draw_sky_floor(int x, int drawstart, int drawend,
	t_img *img, t_vars *vars);
void			draw_sprite(int color, t_vars *vars);
double			ft_abs(double n);
void			calculate_sprites(t_vars *vars);
void			textures_to_struc(t_vars *vars);
int				render_frame(t_vars *vars);
void			move_up(t_vars *vars);
void			move_left(t_vars *vars);
void			move_down(t_vars *vars);
void			move_right(t_vars *vars);
void			move_camera(t_vars *vars);
void			calculate_sprite_dist(t_vars *vars);
void			sort_sprites(t_vars *vars);
int				move_player_press(int keycode, t_vars *vars);
int				move_player_release(int keycode, t_vars *vars);
void			sprite_dimensions(t_vars *vars);
void			texture_error(void);
void			resolution_error(void);
void			rgb_error(void);
void			map_error(void);
void			floor_color(t_data *data);
void			ceiling_color(t_data *data);
void			error_check(t_data *data);
int				valid_rgb(int c);
void			errors(t_data *data);
void			error_opening_map(void);
void			north_texture(t_data *data);
void			south_texture(t_data *data);
void			east_texture(t_data *data);
void			west_texture(t_data *data);
void			sprite_texture(t_data *data);
int				valid_resolution(int c);
void			resolution_format(t_data *data);
void			get_resolution(t_data *data);
void			opening1(t_data *data);
void			opening2(t_data *data, t_vars *vars);
void			opening3(t_data *data, t_vars *vars);
void			formatter(t_data *data);
void			file_reader(t_data *data);
void			map_name_validator(t_data data);
void			save_image_validator(t_data data);
int				invalid_map_chars(int c);
void			map_parser(t_data *data);
void			map_store(t_data *data, t_vars *vars);
int				check_map(char **map, int row, int col, t_data *data);
void			vars_init(t_data *data, t_vars *vars);
void			data_init(t_data *data, t_vars *vars);
int				main(int argc, char *argv[]);
int				main_raycaster(void);
void			print_all(t_data *data);
void			sprite_size(t_vars *vars);
void			sprites_coord(t_vars *vars);
void			render(t_vars *vars);
void			calculate_ray(t_vars *vars);
void			calculate_side_dist(t_vars *vars);
void			calculate_tex_walls(t_vars *vars);
void			compare_resolution(t_data *data, t_vars *vars);
void			player_position(t_data *data, t_vars *vars);
void			alloc_map(t_data *data, t_vars *vars);
void			texture_dimensions(t_vars *vars);
void			space_comma(t_data *data);
void			compare_textures(char *s1, char *s2);
void			element_validator(t_data *data);
void			element_innit(t_data *data);
#endif
