/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubelib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:20:27 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/12 14:17:39 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBELIB_H_   
#define CUBELIB_H_

#include "mlx.h"

// #define screenWidth 640
// #define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_sprite
{
  double x;
  double y;
  int coordX;
  int coordY;
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
	double planeX;
	double planeY;
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
	double ZBuffer[640];
	double invDet;
	double transformX;
	double transformY;

	int spriteScreenX;
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
	int counter;
	int i;

	int a;
	int d;
	int w;
	int s;
	int left;
	int right;

	int screenheight;
	int screenwidth;
} t_vars;

int worldMap[mapWidth][mapHeight];
// int move_player(int keycode, t_vars *vars);
void my_mlx_pixel_put(t_img *imagen, int x, int y, int color);
void draw_walls(int x, int drawStart, int drawEnd, int color, t_img *img, t_vars *vars);
void load_textures(t_vars *vars);
void draw_sky_floor(int x, int drawStart, int drawEnd, t_img *img, t_vars *vars);
// void draw_floor(int x, int drawStart, int drawEnd, t_vars *vars);
void draw_sprite(int color, t_vars *vars);
double ft_abs(double n);
void calculate_sprites(t_vars *vars);
void textures_to_struc(t_vars *vars);
int render_frame(t_vars *vars);

int main(int argc, char *argv[] );
void move_up(t_vars *vars);
void move_down(t_vars *vars);
// int on_keypress(t_vars *vars);
void move_left(t_vars *vars);
void move_right(t_vars *vars);
void move_camera(t_vars *vars);
void calculate_sprite_dist(t_vars *vars);
void sort_sprites(t_vars *vars);
void calculate_sprites(t_vars *vars);
int move_player_press(int keycode, t_vars *vars);
int move_player_release(int keycode, t_vars *vars);
void sprite_dimensions(t_vars *vars);






#endif