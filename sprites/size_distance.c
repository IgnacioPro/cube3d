/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:10:18 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 23:01:36 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	sprite_size(t_vars *vars)
{
	if (vars->drawStartY < 0)
		vars->drawStartY = 0;
	vars->drawEndY = vars->spriteHeight / 2 + vars->screenheight / 2;
	if (vars->drawEndY >= vars->screenheight)
		vars->drawEndY = vars->screenheight - 1;
	vars->spriteWidth = abs((int)(vars->screenheight / (vars->t_y)));
	vars->drawStartX = -vars->spriteWidth / 2 + vars->screenx;
	if (vars->drawStartX < 0)
		vars->drawStartX = 0;
	vars->drawEndX = vars->spriteWidth / 2 + vars->screenx;
	if (vars->drawEndX >= vars->screenwidth)
		vars->drawEndX = vars->screenwidth - 1;
}

void	sprite_dimensions(t_vars *vars)
{
	while (vars->c-- > 0)
	{
		vars->sprite[vars->c].x = vars->sprite[vars->c].cx - vars->posx + 0.5;
		vars->sprite[vars->c].y = vars->sprite[vars->c].cy - vars->posy + 0.5;
		vars->invDet = 1 / (vars->px * vars->dirY - vars->dirx * vars->py);
		vars->t_x = vars->invDet * (vars->dirY * vars->sprite[vars->c].x -
			vars->dirx * vars->sprite[vars->c].y);
		vars->t_y = vars->invDet * (-vars->py * vars->sprite[vars->c].x +
			vars->px * vars->sprite[vars->c].y);
		vars->screenx = (int)((vars->screenwidth / 2) *
			(1 + vars->t_x / vars->t_y));
		vars->spriteHeight = abs((int)(vars->screenheight / (vars->t_y)));
		vars->drawStartY = -vars->spriteHeight / 2 + vars->screenheight / 2;
		sprite_size(vars);
		draw_sprite(0, vars);
	}
}

void	calculate_sprite_dist(t_vars *vars)
{
	int i;

	i = vars->num_sprites;
	while (i-- > 0)
		vars->sprite[i].distance = ((vars->posx - vars->sprite[i].cx) *
		(vars->posx - vars->sprite[i].cx) + (vars->posy - vars->sprite[i].cy) *
		(vars->posy - vars->sprite[i].cy));
}

void	sort_sprites(t_vars *vars)
{
	t_sprite	tmp;
	int			i;
	int			j;

	j = vars->num_sprites;
	while (j > 0)
	{
		i = 0;
		while (i < vars->num_sprites - 1)
		{
			if (vars->sprite[i].distance > vars->sprite[i + 1].distance)
			{
				tmp = vars->sprite[i];
				vars->sprite[i] = vars->sprite[i + 1];
				vars->sprite[i + 1] = tmp;
			}
			i++;
		}
		j--;
	}
}