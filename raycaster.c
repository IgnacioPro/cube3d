/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:58:33 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/22 20:31:37 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cubelib.h"
#include "./getnextline/get_next_line_bonus.h"

void	my_mlx_pixel_put(t_img *imagen, int x, int y, int color)
{
	char *dst;
	int offset;
	
	offset = (y * imagen->line_length + x *(imagen->bits_per_pixel / 8));
	dst = imagen->addr + (y * imagen->line_length + x * (imagen->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	sprite_dimensions(t_vars *vars)
{
	while (vars->counter-- > 0)
	{
		vars->sprite[vars->counter].x = vars->sprite[vars->counter].coordX - vars->posX + 0.5;
		vars->sprite[vars->counter].y = vars->sprite[vars->counter].coordY - vars->posY + 0.5;
		vars->invDet = 1 / (vars->planeX * vars->dirY - vars->dirX * vars->planeY);
		vars->transformX = vars->invDet * (vars->dirY * vars->sprite[vars->counter].x - vars->dirX * vars->sprite[vars->counter].y);
		vars->transformY = vars->invDet * (-vars->planeY * vars->sprite[vars->counter].x + vars->planeX * vars->sprite[vars->counter].y);
		vars->spriteScreenX = (int)((vars->screenwidth / 2) * (1 + vars->transformX / vars->transformY));

		//calcular altura sprites en pantalla
		vars->spriteHeight = abs((int)(vars->screenheight / (vars->transformY)));
		//calcular lineas
		vars->drawStartY = -vars->spriteHeight / 2 + vars->screenheight / 2;
		if (vars->drawStartY < 0)
			vars->drawStartY = 0;
		vars->drawEndY = vars->spriteHeight / 2 + vars->screenheight / 2;
		if (vars->drawEndY >= vars->screenheight)
			vars->drawEndY = vars->screenheight - 1;
		//calcular anchura sprite
		vars->spriteWidth = abs((int)(vars->screenheight / (vars->transformY)));
		vars->drawStartX = -vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawStartX < 0)
			vars->drawStartX = 0;
		vars->drawEndX = vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawEndX >= vars->screenwidth)
			vars->drawEndX = vars->screenwidth - 1;
		draw_sprite(0, vars);
	}
}

void	load_textures(t_vars *vars, t_data *data)
{
	if (!(vars->norte.img = mlx_xpm_file_to_image(vars->mlx, data->north, &vars->norte.height, &vars->norte.width)))
		texture_error();
	if (!(vars->sur.img = mlx_xpm_file_to_image(vars->mlx, data->south, &vars->sur.height, &vars->sur.width)))
		texture_error();
	if (!(vars->este.img = mlx_xpm_file_to_image(vars->mlx, data->east, &vars->este.height, &vars->este.width)))
		texture_error();
	if (!(vars->oeste.img = mlx_xpm_file_to_image(vars->mlx, data->west, &vars->oeste.height, &vars->oeste.width)))
		texture_error();
	if (!(vars->columna.img = mlx_xpm_file_to_image(vars->mlx, data->sprite, &vars->columna.height, &vars->columna.width)))
		texture_error();
}

int move_player_press(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->w = 1;	
   	if (keycode == 1)
		vars->s = 1;
   	if (keycode == 0)
		vars->a = 1;
   	if (keycode == 2)
   		vars->d = 1;
	if (keycode == 124)
		vars->right = 1;
	if (keycode == 123)
		vars->left = 1;	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int move_player_release(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->w = 0;	
   	if (keycode == 1) 
		vars->s = 0;
   	if (keycode == 0) 
		vars->a = 0;
   	if (keycode == 2)
   		vars->d = 0; 
	if (keycode == 124)
		vars->right = 0;
	if (keycode == 123)
		vars->left = 0;	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// free(vars->sprite);
		exit(0);
	}
	return (0);
}

void calculate_sprite_dist(t_vars *vars)
{
	int i;

	i = vars->num_sprites;
	while (i-- > 0)
		vars->sprite[i].distance = ((vars->posX - vars->sprite[i].coordX) * (vars->posX - vars->sprite[i].coordX) + 
			(vars->posY - vars->sprite[i].coordY) * (vars->posY - vars->sprite[i].coordY));
}

void sort_sprites(t_vars *vars)
{
	t_sprite tmp;

	int i;
	int j;

	j = vars->num_sprites;
	while(j > 0)
	{
		i = 0;
		while (i < vars->num_sprites - 1)
		{
			if (vars->sprite[i].distance > vars->sprite[i + 1].distance)
			{
				tmp = vars->sprite[i];
				vars->sprite[i] = vars->sprite [i +1];
				vars->sprite[i + 1] = tmp;
			}
			i++;
		}
		j--;
	}
}

void calculate_sprites(t_vars *vars)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	while (x < vars->mapwidth)
	{
		y = 0;
		while (y < vars->mapheight)
		{
			if (vars->worldmap[x][y] == '2')
				i++;
			y++;
		}
		x++;
	}
	vars->num_sprites = i;
	vars->sprite = (t_sprite *)malloc(i * sizeof(t_sprite));
	x = 0;
	i = 0;
	while (x < vars->mapwidth)
	{
		y = 0;

		while (y < vars->mapheight)
		{
			if (vars->worldmap[x][y] == '2')
			{
				vars->sprite[i].coordX = y;
				vars->sprite[i].coordY = x;
				i++;
			}
			y++;
		}
		x++;
	}
}


void textures_to_struc(t_vars *vars)
{
	if (vars->side == 0 && vars->stepX == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->norte.img, &vars->norte.bits_per_pixel, &vars->norte.line_length, &vars->norte.endian);

	else if (vars->side == 0 && vars->stepX == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->sur.img, &vars->sur.bits_per_pixel, &vars->sur.line_length, &vars->sur.endian);

	else if (vars->side == 1 && vars->stepY == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->este.img, &vars->este.bits_per_pixel, &vars->este.line_length, &vars->este.endian);

	else if (vars->side == 1 && vars->stepY == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->oeste.img, &vars->oeste.bits_per_pixel, &vars->oeste.line_length, &vars->oeste.endian);
}

void		quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
}

int render_frame(t_vars *vars)
{
	vars->imagen.img = mlx_new_image(vars->mlx, vars->screenwidth, vars->screenheight);
	vars->imagen.addr = mlx_get_data_addr(vars->imagen.img, &vars->imagen.bits_per_pixel, &vars->imagen.line_length, &vars->imagen.endian);
	vars->i = 0;

	while (vars->i < vars->screenwidth)
	{
		vars->cameraX = 2 * vars->i / (double)vars->screenwidth - 1;
		vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
		vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
		vars->mapX = (int)vars->posX; // casteado a int
		vars->mapY = (int)vars->posY; // casteado a int
		
		vars->deltaDistX = fabs(1 / vars->rayDirX);
		vars->deltaDistY = fabs(1 / vars->rayDirY);

		// vars->deltaDistX = (vars->rayDirY == 0) ? 0 : ((vars->rayDirX == 0) ? 1 : fabs(1 / vars->rayDirX));
      	// vars->deltaDistY = (vars->rayDirX == 0) ? 0 : ((vars->rayDirY == 0) ? 1 : fabs(1 / vars->rayDirY));
		vars->hit = 0;
		// double texPos;
		// int texX;

		if (vars->rayDirX < 0)
		{
			vars->stepX = -1;
			vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
		}
		else
		{
			vars->stepX = 1;
			vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
		}
		if (vars->rayDirY < 0)
		{
			vars->stepY = -1;
			vars->sideDistY = (vars->posY - vars->mapY) * vars->deltaDistY;
		}
		else
		{
			vars->stepY = 1;
			vars->sideDistY = (vars->mapY + 1.0 - vars->posY) * vars->deltaDistY;
		}
		while (vars->hit == 0)
		{
			if (vars->sideDistX < vars->sideDistY)
			{
				vars->sideDistX += vars->deltaDistX;
				vars->mapX += vars->stepX;
				vars->side = 0;
			}
			else
			{
				vars->sideDistY += vars->deltaDistY;
				vars->mapY += vars->stepY;
				vars->side = 1;
			}
			if (vars->worldmap[vars->mapY][vars->mapX] == '1') //problemas aquí al cocharme con algunos muros
				vars->hit = 1;
		}
		if (vars->side == 0)
			vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;
		else
			vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;

		vars->lineHeight = (int)(vars->screenheight / vars->perpWallDist);
		vars->drawStart = -vars->lineHeight / 2 + vars->screenheight / 2;
		if (vars->drawStart < 0)
			vars->drawStart = 0;
		vars->drawEnd = vars->lineHeight / 2 + vars->screenheight / 2;
		if (vars->drawEnd >= vars->screenheight)
			vars->drawEnd = vars->screenheight - 1;

		textures_to_struc(vars);

		if (vars->side == 0)
			vars->wallX = vars->posY + vars->perpWallDist * vars->rayDirY;
		else
			vars->wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
		vars->wallX -= floor(vars->wallX);

		vars->texX = (int)(vars->wallX * ((double)texWidth));
		if (vars->side == 0 && vars->rayDirX > 0)
			vars->texX = texWidth - vars->texX - 1;
		if (vars->side == 1 && vars->rayDirY < 0)
			vars->texX = texWidth - vars->texX - 1;

		draw_walls(vars->i, vars->drawStart, vars->drawEnd, 0, &vars->imagen, vars);
		draw_sky_floor(vars->i, vars->drawStart, vars->drawEnd,&vars->imagen, vars);
		
		vars->ZBuffer[vars->i] = vars->perpWallDist;
		vars->i++;
	}
	vars->buffer = (int *)mlx_get_data_addr(vars->columna.img, &vars->columna.bits_per_pixel, 
		&vars->columna.line_length, &vars->columna.endian);
	calculate_sprite_dist(vars);
	sort_sprites(vars);
	vars->counter = vars->num_sprites;
	sprite_dimensions(vars);
	move_up(vars);
	move_down(vars);
	move_left(vars);
	move_right(vars);
	move_camera(vars);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->imagen.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->imagen.img);
	return (0);
}

int close_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	vars_init(t_data *data, t_vars *vars)
{
	data->mapy = 0;
	data->mapx = 0;
	data->coord_check = 0;
	data->c = 0;
	data->n_lines = 0;
	data->rl = 0;
	data->rgb_error = 0;
	vars->moveSpeed = 0.1;
	vars->rotSpeed = 0.05;
	vars->posX = 0;
	vars->posY = 0;
	vars->dirX = -1;
	vars->dirY = 0;
	vars->planeX = 0;
	vars->planeY = 0.66;
	vars->a = 0;
	vars->d = 0;
	vars->w = 0;
	vars->s = 0;
	vars->left = 0;
	vars->right = 0;
	vars->i = 0;
}

int main(int argc, char *argv[])
{
	t_vars vars;
	t_data data;

	data.arg1 = argv[1];
	data.arg2 = argv[2];
	data.argc = argc;
	vars_init(&data, &vars);
	opening1(&data);
	file_reader(&data);
	errors(&data);
	close(data.fd);
	opening2(&data, &vars);
	opening3(&data, &vars);
	if (check_map(data.map, data.playerx, data.playery, &data))
		map_error();
	print_all(&data);
	vars.screenheight = data.y;
	vars.screenwidth = data.x;
	vars.mapheight = data.mapx;
	vars.mapwidth = data.mapy;
	vars.posX = data.playery;
	vars.posY = data.playerx;
	vars.ZBuffer = (double*)malloc(data.x * sizeof(double));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.screenwidth, vars.screenheight, "cub3D");
	load_textures(&vars, &data);
	calculate_sprites(&vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, move_player_release, &vars);
	mlx_hook(vars.win, 17, 0L, close_x, &vars);
	printf("Number of sprites: %d\n", vars.num_sprites);
	int i = 0;
	while (i < data.mapy)
	{
		printf("%s\n", vars.worldmap[i]);
		i++;
	}
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	return(0);
}
