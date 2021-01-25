/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubelib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:20:27 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 16:48:35 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBELIB_H_   
#define CUBELIB_H_

#include "mlx.h"
#include "libft/libft.h"
#include "getnextline/get_next_line.h"

// #define screenWidth 640
// #define screenHeight 480
#define texWidth 64
#define texHeight 64

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
}				t_data;

typedef struct s_sprite
{
  double x;
  double y;
  int cx;
  int cy;
  double distance;
  int tmp;
}				t_sprite;
typedef struct s_img
{
	void 	*img;
	void 	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_vars
{

	t_img norte;
	t_img sur;
	t_img este;
	t_img oeste;
	t_img suelo;
	t_img columna;
	t_sprite *sprite;
	t_img imagen;


	void *mlx;
	void *win;
	double moveSpeed;
	int key;
	double rotSpeed;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double px;
	double py;
	int texY;
	double texPos;
	int texX;

	int side;

	int *addr;
	int text_width;
	int text_height;
	double step;
	int *buffer;
	void *img;
	void *addr_img;
	int         bits_per_pixel;
    int         line_length;
    int         endian;
	int *textureBuffer;

	int lineHeight;
	double *ZBuffer;
	double invDet;
	double t_x;
	double t_y;

	int screenx;
	int spriteHeight;
	int drawStartY;
	int drawEndY;

	int spriteScreenY;
	int spriteWidth;
	int drawStartX;
	int drawEndX;
	double cameraX;
	double rayDirX;
	double rayDirY;

	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;

	int mapX;
	int mapY;
	int stepX;
	int stepY;

	double wallX;

  	int num_sprites;
    int keycode;
	double perpWallDist;
	double oldDirX;
	double oldPlaneX;

	int hit;
	int drawStart;
	int drawEnd;
	int c;
	int i;

	int a;
	int d;
	int w;
	int s;
	int left;
	int right;

	int screenheight;
	int screenwidth;
	char **worldmap;
	int mapheight;
	int mapwidth;

	int sky;
	int floor;
} t_vars;


void	my_mlx_pixel_put(t_img *imagen, int x, int y, int color);
void	draw_walls(int x, int drawStart, int drawEnd, int color, t_img *img, t_vars *vars);
void	load_textures(t_vars *vars, t_data *data);
void	draw_sky_floor(int x, int drawStart, int drawEnd, t_img *img, t_vars *vars);
void	draw_sprite(int color, t_vars *vars);
double	ft_abs(double n);
void	calculate_sprites(t_vars *vars);
void	textures_to_struc(t_vars *vars);
int		render_frame(t_vars *vars);

// int		main(int argc, char *argv[] );
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_camera(t_vars *vars);
void	calculate_sprite_dist(t_vars *vars);
void	sort_sprites(t_vars *vars);
int		move_player_press(int keycode, t_vars *vars);
int		move_player_release(int keycode, t_vars *vars);
void	sprite_dimensions(t_vars *vars);

void	texture_error(void);
void	resolution_error(void);
void	rgb_error(void);
void	map_error(void);
void	floor_color(t_data *data);
void	ceiling_color(t_data *data);
void	error_check(t_data *data);
int		valid_rgb(int c);
void	errors(t_data *data);
void	error_opening_map(void);

void	north_texture(t_data *data);
void	south_texture(t_data *data);
void	east_texture(t_data *data);
void	west_texture(t_data *data);
void	sprite_texture(t_data *data);

int		valid_resolution(int c);
void	resolution_format(t_data *data);
void	get_resolution(t_data *data);

void	opening1(t_data *data);
void	opening2(t_data *data, t_vars *vars);
void	opening3(t_data *data, t_vars *vars);
void	formatter(t_data *data);
void	file_reader(t_data *data);

void	map_name_validator(t_data data);
void	save_image_validator(t_data data);
int		invalid_map_chars(int c);
void	map_parser(t_data *data);
void	map_store(t_data *data, t_vars *vars);
int		check_map(char **map, int row, int col, t_data *data);
void	vars_init(t_data *data, t_vars *vars);
void	data_init(t_data *data, t_vars *vars);
int		main(int argc, char *argv[]);
int		main_raycaster(void);
void	print_all(t_data *data);
void	sprite_size(t_vars *vars);
void	sprites_coord(t_vars *vars);
void	render(t_vars *vars);
void	calculate_ray(t_vars *vars);
void	calculate_side_dist(t_vars *vars);
void	calculate_tex_walls(t_vars *vars);

#endif
