/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:57:29 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/26 12:18:56 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	calculate_tex_walls(t_vars *vars)
{
	if (vars->drawstart < 0)
		vars->drawstart = 0;
	vars->drawend = vars->line_y / 2 + vars->screenheight / 2;
	if (vars->drawend >= vars->screenheight)
		vars->drawend = vars->screenheight - 1;
	textures_to_struc(vars);
	if (vars->side == 0)
		vars->wallx = vars->posy + vars->pwalldist * vars->rayy;
	else
		vars->wallx = vars->posx + vars->pwalldist * vars->rayx;
	vars->wallx -= floor(vars->wallx);
	vars->texx = (int)(vars->wallx * ((double)TEXWIDTH));
	if (vars->side == 0 && vars->rayx > 0)
		vars->texx = TEXWIDTH - vars->texx - 1;
	if (vars->side == 1 && vars->rayy < 0)
		vars->texx = TEXWIDTH - vars->texx - 1;
	draw_walls(vars->i, vars->drawstart,
	vars->drawend, 0, &vars->imagen, vars);
	draw_sky_floor(vars->i, vars->drawstart,
	vars->drawend, &vars->imagen, vars);
	vars->zbuffer[vars->i] = vars->pwalldist;
	vars->i++;
}

void	calculate_side_dist(t_vars *vars)
{
	vars->hit = 0;
	if (vars->rayx < 0)
	{
		vars->stepx = -1;
		vars->sidedx = (vars->posx - vars->mapy) * vars->ddistx;
	}
	else
	{
		vars->stepx = 1;
		vars->sidedx = (vars->mapy + 1.0 - vars->posx)
		* vars->ddistx;
	}
	if (vars->rayy < 0)
	{
		vars->stepy = -1;
		vars->sidedy = (vars->posy - vars->mapx) * vars->ddisty;
	}
	else
	{
		vars->stepy = 1;
		vars->sidedy = (vars->mapx + 1.0 - vars->posy)
		* vars->ddisty;
	}
}

void	calculate_ray(t_vars *vars)
{
	while (vars->hit == 0)
	{
		if (vars->sidedx < vars->sidedy)
		{
			vars->sidedx += vars->ddistx;
			vars->mapy += vars->stepx;
			vars->side = 0;
		}
		else
		{
			vars->sidedy += vars->ddisty;
			vars->mapx += vars->stepy;
			vars->side = 1;
		}
		if (vars->worldmap[vars->mapy][vars->mapx] == '1')
			vars->hit = 1;
	}
	if (vars->side == 0)
		vars->pwalldist = (vars->mapy - vars->posx
		+ (1 - vars->stepx) / 2) / vars->rayx;
	else
		vars->pwalldist = (vars->mapx - vars->posy
		+ (1 - vars->stepy) / 2) / vars->rayy;
	vars->line_y = (int)(vars->screenheight / vars->pwalldist);
	vars->drawstart = -vars->line_y / 2 + vars->screenheight / 2;
}
