/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:58:33 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 10:59:13 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"
#include "./getnextline/get_next_line_bonus.h"

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
