/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:12:49 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/24 18:13:30 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	sprites_coord(t_vars *vars)
{
	int x;
	int i;
	int y;

	x = 0;
	i = 0;
	while (x < vars->mapwidth)
	{
		y = 0;
		while (y < vars->mapheight)
		{
			if (vars->worldmap[x][y] == '2')
			{
				vars->sprite[i].cx = x;
				vars->sprite[i].cy = y;
				i++;
			}
			y++;
		}
		x++;
	}
}


void	calculate_sprites(t_vars *vars)
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
	sprites_coord(vars);
}