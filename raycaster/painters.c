/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:53:59 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/28 22:14:08 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	my_mlx_pixel_put(t_img *imagen, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * imagen->line_length + x * (imagen->bits_per_pixel / 8));
	dst = imagen->addr + (y * imagen->line_length + x *
		(imagen->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_walls(int drawstart, int drawend, t_img *img, t_vars *vars)
{
	int color;

	vars->step = 1.0 * vars->tex_y / vars->line_y;
	vars->texpos = (drawstart - vars->screenheight / 2 +
		vars->line_y / 2) * vars->step;
	while (drawstart <= drawend)
	{
		vars->texy = (int)vars->texpos;
		vars->texpos += vars->step;
		color = (unsigned int)vars->buffer[vars->tex_y *
			vars->texy + vars->texx];
		my_mlx_pixel_put(img, vars->i, drawstart, color);
		drawstart++;
	}
}

void	draw_sprite(int color, t_vars *vars)
{
	vars->sp = vars->startx;
	while (vars->sp < vars->drawendx)
	{
		vars->texx = (int)(256 * (vars->sp -
		(-vars->s_width / 2 + vars->screenx))
		* vars->tex_x / vars->s_width) / 256;
		if (vars->t_y > 0 && vars->sp > 0 && vars->sp < vars->screenwidth &&
			vars->t_y < vars->zbuffer[vars->sp])
		{
			vars->si = vars->starty;
			while (vars->si < vars->drawendy)
			{
				vars->sd = (vars->si) * 256 - vars->screenheight *
					128 + vars->sprite_y * 128;
				vars->texy = ((vars->sd * vars->columna.height)
					/ vars->sprite_y) / 256;
				color = (unsigned int)vars->buffer[vars->columna.width
					* vars->texy + vars->texx];
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&vars->imagen, vars->sp, vars->si, color);
				vars->si++;
			}
		}
		vars->sp++;
	}
}

void	draw_sky_floor(int drawstart, int drawend, t_img *img, t_vars *vars)
{
	int j;

	j = 0;
	while (j < (drawstart))
	{
		my_mlx_pixel_put(img, vars->i, j, vars->sky);
		j++;
	}
	j = drawend;
	while (j < vars->screenheight && j > 0)
	{
		my_mlx_pixel_put(img, vars->i, j, vars->floor);
		j++;
	}
}

void	compare_resolution(t_data *data, t_vars *vars)
{
	int screen_size;

	screen_size = mlx_get_screen_size(vars->mlx, &vars->localx, &vars->localy);
	if (data->x < 0 || data->y < 0)
		resolution_error();
	if (data->y > vars->localy)
		data->y = vars->localy;
	if (data->x > vars->localx)
		data->x = vars->localx;
}
