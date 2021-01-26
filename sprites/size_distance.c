/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:10:18 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/26 13:20:55 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	sprite_size(t_vars *vars)
{
	if (vars->starty < 0)
		vars->starty = 0;
	vars->drawendy = vars->spriteheight / 2 + vars->screenheight / 2;
	if (vars->drawendy >= vars->screenheight)
		vars->drawendy = vars->screenheight - 1;
	vars->s_width = abs((int)(vars->screenheight / (vars->t_y)));
	vars->startx = -vars->s_width / 2 + vars->screenx;
	if (vars->startx < 0)
		vars->startx = 0;
	vars->drawendx = vars->s_width / 2 + vars->screenx;
	if (vars->drawendx >= vars->screenwidth)
		vars->drawendx = vars->screenwidth - 1;
}

void	sprite_dimensions(t_vars *vars)
{
	while (vars->c-- > 0)
	{
		vars->sprite[vars->c].x = vars->sprite[vars->c].cx - vars->posx + 0.5;
		vars->sprite[vars->c].y = vars->sprite[vars->c].cy - vars->posy + 0.5;
		vars->invdet = 1 / (vars->px * vars->diry - vars->dirx * vars->py);
		vars->t_x = vars->invdet * (vars->diry * vars->sprite[vars->c].x -
			vars->dirx * vars->sprite[vars->c].y);
		vars->t_y = vars->invdet * (-vars->py * vars->sprite[vars->c].x +
			vars->px * vars->sprite[vars->c].y);
		vars->screenx = (int)((vars->screenwidth / 2) *
			(1 + vars->t_x / vars->t_y));
		vars->spriteheight = abs((int)(vars->screenheight / (vars->t_y)));
		vars->starty = -vars->spriteheight / 2 + vars->screenheight / 2;
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
