#include "cubelib.h"

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
    char    *dst;
	// int offset = (y * vars->line_length + x *(vars->bits_per_pixel / 8));
    dst = vars->addr_img + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void draw_walls(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	vars->step = 1 *(double)(texHeight) / vars->lineHeight;
	vars->texPos = (drawStart - screenHeight / 2 + vars->lineHeight / 2 ) * vars->step;
	while (drawStart <= drawEnd)
	{
		vars->texY = (int)vars->texPos;
		vars->texPos += vars->step;
		color = (unsigned int)vars->buffer[texHeight * vars->texY + vars->texX];
		my_mlx_pixel_put(vars, x, drawStart, color);

		++drawStart;
	}
}
void load_textures(t_vars *vars)
{
	vars->textura_norte.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/mossy.xpm", &vars->textura_norte.tex_height, &vars->textura_norte.tex_width);
	vars->textura_sur.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/redbrick.xpm", &vars->textura_sur.tex_height, &vars->textura_sur.tex_width);
	vars->textura_este.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/wood.xpm", &vars->textura_este.tex_height, &vars->textura_este.tex_width);
	vars->textura_oeste.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/greystone.xpm", &vars->textura_oeste.tex_height, &vars->textura_oeste.tex_width);
	vars->textura_suelo.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/colorstone.xpm", &vars->textura_suelo.tex_height, &vars->textura_suelo.tex_width);
	vars->textura_columna.textura = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/pillar.xpm", &vars->textura_columna.tex_height, &vars->textura_columna.tex_width);
}

void draw_sky(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	int i = 0;
	color = 0x19D9F0;


	while (i < drawStart)
	{
		my_mlx_pixel_put(vars, x, i, color);
		i++;
	}
}
void draw_floor(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	color = 0xED1010;

	while (drawEnd < screenHeight)
	{
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

					// vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
					d = (i) * 256 - screenHeight * 128 + vars->spriteHeight * 128;
					vars->texY = ((d * 64) / vars->spriteHeight) / 256;
					color = (unsigned int)vars->buffer[64 * vars->texY + vars->texX];
					if((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(vars, sprite, i, color);
					i++;
				}
			}
		sprite++;
	}
}


int move_player(int keycode, t_vars *vars)
{
	// if (keycode == 126) //up
	// {
	// 	if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
	// 		vars->posX += vars->dirX * vars->moveSpeed;
	// 	if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
	// 		vars->posY += vars->dirY * vars->moveSpeed;
	// }

	// if (keycode == 125) //down
	// {
	// 	if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
	// 		vars->posX -= vars->dirX * vars->moveSpeed;
	// 	if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
	// 		vars->posY -= vars->dirY * vars->moveSpeed;
	// }
	if (keycode == 124) // look right
	{
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
		vars->dirY = oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
		vars->planeY = oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);
	}
	if (keycode == 123) // look left
	{
		double oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
		vars->dirY = oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
		double oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
		vars->planeY = oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
	}

	if (keycode == 0) // A
	{
		if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirY * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY += vars->dirX * vars->moveSpeed;
	}
	if (keycode == 2) // D
	{
		if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirY * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirX * vars->moveSpeed;
	}
	if (keycode == 13) // W
	{
		if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
			vars->posY += vars->dirY * vars->moveSpeed;
	}
	
	if (keycode == 1) // S
	{
		if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}


double ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int calculate_sprites(t_vars *vars)
{
	vars->mapX = 0;
	while (vars->mapX < mapWidth)
	{
		vars->mapY = 0;

		while (vars->mapY < mapHeight)
		{
			if (worldMap[vars->mapX][vars->mapY] == 2)
				vars->num_sprites++;
			vars->mapY++;
		}
		vars->mapX++;
	}
	printf("%d\n", vars->num_sprites);
	return(vars->num_sprites);
}

void sort_sprites_distance(int *order, double *dist, t_vars *vars)
{
	int i;

	i = 0;
	while(i < vars->num_sprites)
	{

	}
}

void textures_to_struc(t_vars *vars)
{
		if (vars->side == 0 && vars->stepX == -1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_norte.textura, &vars->textura_norte.bits_per_pixel, &vars->textura_norte.line_length, &vars->textura_norte.endian);
		
		else if (vars->side == 0 && vars->stepX == 1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_sur.textura, &vars->textura_sur.bits_per_pixel, &vars->textura_sur.line_length, &vars->textura_sur.endian);

		else if (vars->side == 1 && vars->stepY == 1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_este.textura, &vars->textura_este.bits_per_pixel, &vars->textura_este.line_length, &vars->textura_este.endian);

		else if (vars->side == 1 && vars->stepY == -1)
			vars->buffer = (unsigned int*)mlx_get_data_addr(vars->textura_oeste.textura, &vars->textura_oeste.bits_per_pixel, &vars->textura_oeste.line_length, &vars->textura_oeste.endian);
}

int render_frame(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	int x = 0;
	double wallX;
	vars->addr_img = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);

	while (x < screenWidth)
	{
		double cameraX = 2 * x / (double)screenWidth - 1;
		double rayDirX = vars->dirX + vars->planeX * cameraX;
		double rayDirY = vars->dirY + vars->planeY * cameraX;
		vars->mapX = vars->posX;
		vars->mapY = vars->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = ft_abs(1 / rayDirX);
		double deltaDistY = ft_abs(1 / rayDirY);
		double perpWallDist;
		int hit = 0;
		double texPos;
		int texX;

		if (rayDirX < 0)
		{
			vars->stepX = -1;
			sideDistX = (vars->posX - vars->mapX) * deltaDistX;
		}
		else
		{
			vars->stepX = 1;
			sideDistX = (vars->mapX + 1.0 - vars->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			vars->stepY = -1;
			sideDistY = (vars->posY - vars->mapY) * deltaDistY;
		}
		else
		{
			vars->stepY = 1;
			sideDistY = (vars->mapY + 1.0 - vars->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				vars->mapX += vars->stepX;
				vars->side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				vars->mapY += vars->stepY;
				vars->side = 1;
			}
			if (worldMap[vars->mapX][vars->mapY] == 1)
				hit = 1;
		}
		if (vars->side == 0)
			perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / rayDirX;
		else
			perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / rayDirY;

		vars->lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -vars->lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = vars->lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		

		//meter variables en estructura
		textures_to_struc(vars);
		
		if (vars->side == 0)
			wallX = vars->posY + perpWallDist * rayDirY;
		else
			wallX = vars->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
	
		vars->texX = (int)(wallX * ((double)texWidth));
		if (vars->side == 0 && rayDirX > 0)
			vars->texX = texWidth - vars->texX - 1;
		if(vars->side == 1 && rayDirY < 0)
			vars->texX = texWidth - vars->texX - 1;
		
		draw_walls(x, drawStart, drawEnd, 0, vars);
		draw_sky(x, drawStart, drawEnd, 0, vars);
		draw_floor(x, drawStart, drawEnd, 0, vars);

		vars->ZBuffer[x] = perpWallDist;
		vars->buffer = (unsigned int *)mlx_get_data_addr(vars->textura_columna.textura, &vars->textura_columna.bits_per_pixel, &vars->textura_columna.line_length, &vars->textura_columna.endian);
		++x;
	}
		vars->mapX = 0;
		while (vars->mapX < mapWidth)
		{
			vars->mapY = 0;
			while (vars->mapY < mapHeight)
			{
				if (worldMap[vars->mapX][vars->mapY] == 2)
					{
						vars->sprite.x = vars->mapX - vars->posX;
						vars->sprite.y = vars->mapY - vars->posY;
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
					}
				vars->mapY++;
			}
			vars->mapX++;
		}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img);
	return (0);
}
int main()
{
	t_textura textura;
	t_vars vars;
	t_vars textura_norte;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Cube");
	vars.moveSpeed = 0.25;
	vars.rotSpeed = 0.3;
	vars.posX = 22;
	vars.posY = 12;
	vars.dirX = -1;
	vars.dirY = 0;
	vars.planeX = 0;
	vars.planeY = 0.66;
	int x = 0;


	// textures_to_struc(&vars);
	calculate_sprites(&vars);
	//cambiar variables de texturas en la estructura
	load_textures(&vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
	mlx_loop(vars.mlx);
}
