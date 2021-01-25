/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:57:29 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 22:59:23 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	calculate_tex_walls(t_vars *vars)
{
	if (vars->drawStart < 0)
		vars->drawStart = 0;
	vars->drawEnd = vars->lineHeight / 2 + vars->screenheight / 2;
	if (vars->drawEnd >= vars->screenheight)
		vars->drawEnd = vars->screenheight - 1;
	textures_to_struc(vars);
	if (vars->side == 0)
		vars->wallX = vars->posy + vars->perpWallDist * vars->rayDirY;
	else
		vars->wallX = vars->posx + vars->perpWallDist * vars->rayDirX;
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
		vars->sideDistX = (vars->posx - vars->mapY) * vars->deltaDistX;
	}
	else
	{
		vars->stepX = 1;
		vars->sideDistX = (vars->mapY + 1.0 - vars->posx)
		* vars->deltaDistX;
	}
	if (vars->rayDirY < 0)
	{
		vars->stepY = -1;
		vars->sideDistY = (vars->posy - vars->mapX) * vars->deltaDistY;
	}
	else
	{
		vars->stepY = 1;
		vars->sideDistY = (vars->mapX + 1.0 - vars->posy)
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
		vars->perpWallDist = (vars->mapY - vars->posx
		+ (1 - vars->stepX) / 2) / vars->rayDirX;
	else
		vars->perpWallDist = (vars->mapX - vars->posy
		+ (1 - vars->stepY) / 2) / vars->rayDirY;
	vars->lineHeight = (int)(vars->screenheight / vars->perpWallDist);
	vars->drawStart = -vars->lineHeight / 2 + vars->screenheight / 2;
}
