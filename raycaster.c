#include "mlx.h"

#define screenWidth 200//640
#define screenHeight 150//480
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
  int texture;
  double sprite_distance;
}				t_sprite;
typedef struct s_textura
{
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	void 	*textura;
	int		tex_height;
	int		tex_width;
}t_textura;

typedef struct s_vars
{

	t_textura textura_norte;
	t_textura textura_sur;
	t_textura textura_este;
	t_textura textura_oeste;
	t_textura textura_suelo;
	t_textura textura_columna;
	t_sprite sprite;


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

void draw_sprite(int color, t_vars *vars )
{
	int sprite;
	sprite = vars->drawStartX;
	while (sprite < vars->drawEndX)
	{
		vars->texX = (int)(256 * (sprite - (-vars->spriteWidth / 2 + vars->spriteScreenX)) * texWidth / vars->spriteWidth) / 256;
		if (vars->transformY > 0 && sprite > 0 && sprite < screenWidth && vars->transformY < vars->ZBuffer[sprite])
			{
				int i;
				i = vars->drawStartY;

				while( i < vars->drawEndY)
				{
					int d;

					vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
					d = (i) * 256 - screenHeight * 128 + vars->spriteHeight * 128;
					vars->texY = ((d * 64) / vars->spriteHeight) / 256;
					color = (unsigned int)vars->buffer[64 * vars->texY + vars->texX];
					my_mlx_pixel_put(vars, sprite, i, color);
					i++;
					
				}
			}
		sprite++;
	}
}


int move_player(int keycode, t_vars *vars) //
{
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
		

		//meter variables en estructura
		if (side == 0 && stepX == -1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_norte.textura, &vars->textura_norte.bits_per_pixel, &vars->textura_norte.line_length, &vars->textura_norte.endian);
		
		else if (side == 0 && stepX == 1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_sur.textura, &vars->textura_sur.bits_per_pixel, &vars->textura_sur.line_length, &vars->textura_sur.endian);

		else if (side == 1 && stepY == 1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_este.textura, &vars->textura_este.bits_per_pixel, &vars->textura_este.line_length, &vars->textura_este.endian);

		else if (side == 1 && stepY == -1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_oeste.textura, &vars->textura_oeste.bits_per_pixel, &vars->textura_oeste.line_length, &vars->textura_oeste.endian);
		
		// else
		// 	vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_este.textura, &vars->textura_este.bits_per_pixel, &vars->textura_este.line_length, &vars->textura_este.endian);

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
		draw_sky(x, drawStart, drawEnd, 0, vars);
		draw_floor(x, drawStart, drawEnd, 0, vars);
		vars->ZBuffer[x] = perpWallDist;
		vars->buffer = (unsigned int *)mlx_get_data_addr(vars->textura_columna.textura, &vars->textura_columna.bits_per_pixel, &vars->textura_columna.line_length, &vars->textura_columna.endian);

		// printf("%f\n", vars->ZBuffer[100]);
		++x;
		// mlx_clear_window(vars->mlx, vars->win);
	}
	int i = 0;
	while ( i < 1 )
	{
			
		vars->sprite.x = 20 - vars->posX;
		vars->sprite.y = 10 - vars->posY;
		vars->invDet = 1.0 / (vars->planeX * vars->dirY - vars->dirX * vars->planeY);
		vars->transformX = vars->invDet * (vars->dirY * vars->sprite.x - vars->dirX * vars->sprite.y);
		vars->transformY = vars->invDet * (-vars->planeY * vars->sprite.x + vars->planeX * vars->sprite.y);
		vars->spriteScreenX = (int)((screenWidth / 2) * (1 + vars->transformX / vars->transformY));

		//calcular altura sprites en pantalla
		vars->spriteHeight = ft_abs((int)(screenHeight / (vars->transformY)));
		//calcular lineas
		vars->drawStartY = -vars->spriteHeight / 2 + screenHeight / 2;
		if (vars->drawStartY < 0)
			vars->drawStartY = 0;
		vars->drawEndY = vars->spriteHeight / 2 + screenHeight / 2;
		if (vars->drawEndY >= screenHeight)
			vars->drawEndY = screenHeight -1;
		//calcular anchura sprite
		vars->spriteWidth = ft_abs((int)(screenHeight / (vars->transformY)));
		vars->drawStartX = -vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawStartX < 0)
			vars->drawStartX = 0;
		vars->drawEndX = vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawEndX >= screenWidth)
			vars->drawEndX = screenWidth -1;
		
		draw_sprite(0, vars);
		i++;
		

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
	int x = 0;

	//cambiar variables de texturas en la estructura

	vars.textura_norte.textura = mlx_xpm_file_to_image(vars.mlx, "./mossy.xpm", &vars.textura_norte.tex_height, &vars.textura_norte.tex_width);
	vars.textura_sur.textura = mlx_xpm_file_to_image(vars.mlx, "./redbrick.xpm", &vars.textura_sur.tex_height, &vars.textura_sur.tex_width);
	vars.textura_este.textura = mlx_xpm_file_to_image(vars.mlx, "./wood.xpm", &vars.textura_este.tex_height, &vars.textura_este.tex_width);
	vars.textura_oeste.textura = mlx_xpm_file_to_image(vars.mlx, "./greystone.xpm", &vars.textura_oeste.tex_height, &vars.textura_oeste.tex_width);
	vars.textura_suelo.textura = mlx_xpm_file_to_image(vars.mlx, "./colorstone.xpm", &vars.textura_suelo.tex_height, &vars.textura_suelo.tex_width);
	vars.textura_columna.textura = mlx_xpm_file_to_image(vars.mlx, "./pillar.xpm", &vars.textura_columna.tex_height, &vars.textura_columna.tex_width);
	
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
	mlx_loop(vars.mlx);
}
