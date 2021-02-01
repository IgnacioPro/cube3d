/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:02:13 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/02/01 20:35:21 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

int		render_frame(t_vars *vars)
{
	vars->imagen.img = mlx_new_image(vars->mlx, vars->screenwidth,
	vars->screenheight);
	vars->imagen.addr = (unsigned int*)mlx_get_data_addr(vars->imagen.img,
	&vars->imagen.bits_per_pixel, &vars->imagen.line_length,
	&vars->imagen.endian);
	vars->i = 0;
	while (vars->i < vars->screenwidth)
	{
		vars->camx = 2 * vars->i / (double)vars->screenwidth - 1;
		vars->rayx = vars->dirx + vars->px * vars->camx;
		vars->rayy = vars->diry + vars->py * vars->camx;
		vars->mapy = (int)vars->posx;
		vars->mapx = (int)vars->posy;
		vars->ddistx = fabs(1 / vars->rayx);
		vars->ddisty = fabs(1 / vars->rayy);
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
