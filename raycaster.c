#include "mlx.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_textura
{
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	void 	*textura;
}t_textura;

typedef struct s_vars
{

	t_textura textura_norte;
	t_textura textura_sur;
	t_textura textura_este;
	t_textura textura_oeste;
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

	int *addr;
	int text_width;
	int text_height;
	double step;

	unsigned *buffer;

	void *img;
	void *addr_img;
	int         bits_per_pixel;
    int         line_length;
    int         endian;
	int *textureBuffer;

	int lineHeight;
} t_vars;

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int            my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
    char    *dst;
	// int offset = (y * vars->line_length + x *(vars->bits_per_pixel / 8));
    dst = vars->addr_img + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	return(0);
}


void draw_walls(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	vars->step = (double)(texHeight) / vars->lineHeight;
	vars->texPos = (drawStart - screenHeight / 2 + vars->lineHeight / 2 ) * vars->step;
	// vars->texX = (int)vars->texPos & (texHeight - 1);
	
	while (drawStart <= drawEnd)
	{
		vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
		vars->texY = (int)vars->texPos;
		vars->texPos += vars->step;
		color = (unsigned int)vars->buffer[texHeight * vars->texY + vars->texX];
		my_mlx_pixel_put(vars, x, drawStart, color);

		drawStart++;
	}
}

void draw_sky(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	int i = 0; 
	color = 0x19D9F0;
	// vars->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	while (i < drawStart)
	{
		vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
		my_mlx_pixel_put(vars, x, i, color);
		i++;
	}
}
void draw_floor(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	color = 0xED1010;
	// vars->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	while (drawEnd < screenHeight)
	{
		vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
		my_mlx_pixel_put(vars, x, drawEnd, color);
		drawEnd++;
	}
}



int move_player(int keycode, t_vars *vars) //
{
	printf("Casilla: %d\n", worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY]);
	if (keycode == 126) //up
	{
		if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
			vars->posY += vars->dirY * vars->moveSpeed;
	}

	if (keycode == 125) //down
	{
		if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
	if (keycode == 124) //right
	{
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
		vars->dirY = oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
		vars->planeY = oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);
	}
	if (keycode == 123) //left
	{
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
		vars->dirY = oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
		vars->planeY = oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	

	// printf("Pos X: %f\n", vars->posX);
	// printf("Pos Y: %f\n", vars->posY);

	return (0);
}

double ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int render_frame(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	int x = 0;
	double wallX;
	while (x < screenWidth)
	{
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = vars->dirX + vars->planeX * cameraX;
		double rayDirY = vars->dirY + vars->planeY * cameraX;
		int mapX = vars->posX;
		int mapY = vars->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = ft_abs(1 / rayDirX);
		double deltaDistY = ft_abs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;
		int hit = 0;
		int side;

		double texPos;
		int texX;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (vars->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - vars->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (vars->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - vars->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - vars->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - vars->posY + (1 - stepY) / 2) / rayDirY;

		vars->lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -vars->lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = vars->lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		
		if (worldMap[mapX][mapY] == 1)
		{
		vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_norte.textura, &vars->textura_norte.bits_per_pixel, &vars->textura_norte.line_length, &vars->textura_norte.endian);
		}
		else if (worldMap[mapX][mapY] == 2)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_sur.textura, &vars->textura_sur.bits_per_pixel, &vars->textura_sur.line_length, &vars->textura_sur.endian);

		else if (worldMap[mapX][mapY] == 3)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_este.textura, &vars->textura_este.bits_per_pixel, &vars->textura_este.line_length, &vars->textura_este.endian);

		else if (worldMap[mapX][mapY] == 4)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_oeste.textura, &vars->textura_oeste.bits_per_pixel, &vars->textura_oeste.line_length, &vars->textura_oeste.endian);

		// else
		// 	vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_este.textura, &vars->textura_este.bits_per_pixel, &vars->textura_este.line_length, &vars->textura_este.endian);


		// if (side == 1)
		// 	vars->textureBuffer /= 2; 
		if (side == 0)
			wallX = vars->posY + perpWallDist * rayDirY;
		else
			wallX = vars->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
	
		vars->texX = (int)(wallX * ((double)texWidth));
		if (side == 0 && rayDirX > 0)
			vars->texX = texWidth - vars->texX - 1;
		if(side == 1 && rayDirY < 0)
			vars->texX = texWidth - vars->texX - 1;
		
		
		// vars->texX = (int)vars->texPos & (texHeight - 1);
		// vars->step = 1.0 * (vars->text_height / lineHeight);
		// vars->texPos = (drawStart - screenHeight / 2 + lineHeight / 2 ) * vars->step;
		// j = drawStart;
		// while(j < drawEnd)
		// {
		// 	vars->texY = (int)vars->texPos & (vars->text_height - 1);
		// 	vars->texPos += vars->step;
		// 	j++;
		// // }
		draw_walls(x, drawStart, drawEnd, 0, vars);
		// draw_sky(x, drawStart, drawEnd, color, vars);
		// draw_floor(x, drawStart, drawEnd, color, vars);
		++x;
		// mlx_clear_window(vars->mlx, vars->win);
	}
	// mlx_sync(1, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	// mlx_sync(3, vars->win);
	// mlx_destroy_image(vars->mlx, vars->img);
	return (0);
}
int main()
{
	t_textura textura;
	t_vars vars;
	t_vars textura_norte;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Cube");
	vars.moveSpeed = 0.5;
	vars.rotSpeed = 0.1;
	vars.posX = 22;
	vars.posY = 12;
	vars.dirX = -1;
	vars.dirY = 0;
	vars.planeX = 0;
	vars.planeY = 0.66;
	int width;
	int height;
	int x = 0;

	//cambiar variables de texturas en la estructura

	vars.textura_norte.textura = mlx_xpm_file_to_image(vars.mlx, "./mossy.xpm", &vars.texX, &vars.texY);
	vars.textura_sur.textura = mlx_xpm_file_to_image(vars.mlx, "./redbrick.xpm", &vars.texX, &vars.texY);
	vars.textura_este.textura = mlx_xpm_file_to_image(vars.mlx, "./wood.xpm", &vars.texX, &vars.texY);
	vars.textura_oeste.textura = mlx_xpm_file_to_image(vars.mlx, "./greystone.xpm", &vars.texX, &vars.texY);
	// vars.texture.img = mlx_xpm_file_to_image(vars.mlx, "./mossy.xpm", &vars.text_width, &vars.text_height);
	// vars.texture.addr = mlx_get_data_addr(vars.texture.img, &vars.texture.bits_per_pixel, &vars.texture.line_length, &vars.texture.endian); 
	// vars.addr = (int*)vars.texture.addr;
	// vars.img.img = mlx_new_image(vars.mlx, screenWidth, screenHeight);
	// vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	// vars.img[1] = mlx_xpm_file_to_image(vars.mlx, "./redbrick.xpm", &width, &height);
	// vars.img[2] = mlx_xpm_file_to_image(vars.mlx, "./wood.xpm", &width, &height);
	// vars.img[3] = mlx_xpm_file_to_image(vars.mlx, "./greystone.xpm", &width, &height);



	// mlx_put_image_to_window(vars.mlx, vars.win, img[0], 0, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img[1], 0, 64);
	// mlx_put_image_to_window(vars.mlx, vars.win, img[2], 0, 128);
	// mlx_put_image_to_window(vars.mlx, vars.win, img[3], 0, 192);

	

	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
	mlx_loop(vars.mlx);
}
