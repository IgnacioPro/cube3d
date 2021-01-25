/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:58:33 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 23:06:22 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"
#include "./getnextline/get_next_line_bonus.h"

void	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
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
	vars->dirx = -1;
	vars->diry = 0;
	vars->px = 0;
	vars->py = 0.66;
}

void	vars_init(t_data *data, t_vars *vars)
{
	vars->moveSpeed = 0.15;
	vars->rotSpeed = 0.1;
	vars->posx = 0;
	vars->posy = 0;
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
	vars->posx = data->playerx + 0.5;
	vars->posy = data->playery + 0.5;
	vars->ZBuffer = (double*)malloc(data->x * sizeof(double));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->screenwidth,
		vars->screenheight, "cub3D");
	vars->sky = 65536 * data->ceiling[0] +
	256 * data->ceiling[1] + data->ceiling[2];
	vars->floor = 65536 * data->floor[0] +
	256 * data->floor[1] + data->floor[2];
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
	compare_resolution(&data, &vars);
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
