/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:58:33 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/24 18:13:43 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"
#include "./getnextline/get_next_line_bonus.h"



void	load_textures(t_vars *vars, t_data *data)
{
	if (!(vars->norte.img = mlx_xpm_file_to_image(vars->mlx, data->north,
		&vars->norte.height, &vars->norte.width)))
		texture_error();
	if (!(vars->sur.img = mlx_xpm_file_to_image(vars->mlx, data->south,
		&vars->sur.height, &vars->sur.width)))
		texture_error();
	if (!(vars->este.img = mlx_xpm_file_to_image(vars->mlx, data->east,
		&vars->este.height, &vars->este.width)))
		texture_error();
	if (!(vars->oeste.img = mlx_xpm_file_to_image(vars->mlx, data->west,
		&vars->oeste.height, &vars->oeste.width)))
		texture_error();
	if (!(vars->columna.img = mlx_xpm_file_to_image(vars->mlx, data->sprite,
		&vars->columna.height, &vars->columna.width)))
		texture_error();
}

void	textures_to_struc(t_vars *vars)
{
	if (vars->side == 0 && vars->stepX == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->norte.img,
		&vars->norte.bits_per_pixel, &vars->norte.line_length,
		&vars->norte.endian);
	else if (vars->side == 0 && vars->stepX == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->sur.img,
		&vars->sur.bits_per_pixel, &vars->sur.line_length,
		&vars->sur.endian);
	else if (vars->side == 1 && vars->stepY == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->este.img,
		&vars->este.bits_per_pixel, &vars->este.line_length,
		&vars->este.endian);
	else if (vars->side == 1 && vars->stepY == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->oeste.img,
		&vars->oeste.bits_per_pixel, &vars->oeste.line_length,
		&vars->oeste.endian);
}

void	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
}

int		render_frame(t_vars *vars)
{
	vars->imagen.img = mlx_new_image(vars->mlx, vars->screenwidth,
	vars->screenheight);
	vars->imagen.addr = mlx_get_data_addr(vars->imagen.img,
	&vars->imagen.bits_per_pixel, &vars->imagen.line_length,
	&vars->imagen.endian);
	vars->i = 0;
	while (vars->i < vars->screenwidth)
	{
		vars->cameraX = 2 * vars->i / (double)vars->screenwidth - 1;
		vars->rayDirX = vars->dirX + vars->px * vars->cameraX;
		vars->rayDirY = vars->dirY + vars->py * vars->cameraX;
		vars->mapY = (int)vars->posX;
		vars->mapX = (int)vars->posY;
		vars->deltaDistX = fabs(1 / vars->rayDirX);
		vars->deltaDistY = fabs(1 / vars->rayDirY);
		calculate_side_dist(vars);
		calculate_ray(vars);
		calculate_tex_walls(vars);
	}
	render(vars);
	return (0);
}

void	calculate_tex_walls(t_vars *vars)
{
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
	draw_walls(vars->i, vars->drawStart,
	vars->drawEnd, 0, &vars->imagen, vars);
	draw_sky_floor(vars->i, vars->drawStart,
	vars->drawEnd, &vars->imagen, vars);
	vars->ZBuffer[vars->i] = vars->perpWallDist;
	vars->i++;
}

void	calculate_side_dist(t_vars *vars)
{
	vars->hit = 0;
	if (vars->rayDirX < 0)
	{
		vars->stepX = -1;
		vars->sideDistX = (vars->posX - vars->mapY) * vars->deltaDistX;
	}
	else
	{
		vars->stepX = 1;
		vars->sideDistX = (vars->mapY + 1.0 - vars->posX)
		* vars->deltaDistX;
	}
	if (vars->rayDirY < 0)
	{
		vars->stepY = -1;
		vars->sideDistY = (vars->posY - vars->mapX) * vars->deltaDistY;
	}
	else
	{
		vars->stepY = 1;
		vars->sideDistY = (vars->mapX + 1.0 - vars->posY)
		* vars->deltaDistY;
	}
}

void	calculate_ray(t_vars *vars)
{
	while (vars->hit == 0)
	{
		if (vars->sideDistX < vars->sideDistY)
		{
			vars->sideDistX += vars->deltaDistX;
			vars->mapY += vars->stepX;
			vars->side = 0;
		}
		else
		{
			vars->sideDistY += vars->deltaDistY;
			vars->mapX += vars->stepY;
			vars->side = 1;
		}
		if (vars->worldmap[vars->mapY][vars->mapX] == '1')
			vars->hit = 1;
	}
	if (vars->side == 0)
		vars->perpWallDist = (vars->mapY - vars->posX
		+ (1 - vars->stepX) / 2) / vars->rayDirX;
	else
		vars->perpWallDist = (vars->mapX - vars->posY
		+ (1 - vars->stepY) / 2) / vars->rayDirY;
	vars->lineHeight = (int)(vars->screenheight / vars->perpWallDist);
	vars->drawStart = -vars->lineHeight / 2 + vars->screenheight / 2;
}

void	render(t_vars *vars)
{
	vars->buffer = (int *)mlx_get_data_addr(vars->columna.img,
	&vars->columna.bits_per_pixel,
	&vars->columna.line_length, &vars->columna.endian);
	calculate_sprite_dist(vars);
	sort_sprites(vars);
	vars->c = vars->num_sprites;
	sprite_dimensions(vars);
	move_up(vars);
	move_down(vars);
	move_left(vars);
	move_right(vars);
	move_camera(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imagen.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->imagen.img);
}

int		close_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	data_init(t_data *data, t_vars *vars)
{
	data->mapy = 0;
	data->mapx = 0;
	data->coord_check = 0;
	data->c = 0;
	data->n_lines = 0;
	data->rl = 0;
	data->rgb_error = 0;
	vars->dirX = -1;
	vars->dirY = 0;
	vars->px = 0;
	vars->py = 0.66;
}

void	vars_init(t_data *data, t_vars *vars)
{
	vars->moveSpeed = 0.1;
	vars->rotSpeed = 0.1;
	vars->posX = 0;
	vars->posY = 0;
	vars->a = 0;
	vars->d = 0;
	vars->w = 0;
	vars->s = 0;
	vars->left = 0;
	vars->right = 0;
	vars->i = 0;
	vars->screenheight = data->y;
	vars->screenwidth = data->x;
	vars->mapheight = data->mapx;
	vars->mapwidth = data->mapy;
	vars->posX = data->playerx;
	vars->posY = data->playery;
	vars->ZBuffer = (double*)malloc(data->x * sizeof(double));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->screenwidth,
		vars->screenheight, "cub3D");
}

int		main(int argc, char *argv[])
{
	t_vars vars;
	t_data data;

	data.arg1 = argv[1];
	data.arg2 = argv[2];
	data.argc = argc;
	data_init(&data, &vars);
	opening1(&data);
	file_reader(&data);
	errors(&data);
	close(data.fd);
	opening2(&data, &vars);
	opening3(&data, &vars);
	print_all(&data);
	vars_init(&data, &vars);
	load_textures(&vars, &data);
	calculate_sprites(&vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, move_player_release, &vars);
	mlx_hook(vars.win, 17, 0L, close_x, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}
