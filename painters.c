/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:53:59 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/08 18:55:59 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

void draw_walls(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	vars->step = 1 * (double)(texHeight) / vars->lineHeight;
	vars->texPos = (drawStart - screenHeight / 2 + vars->lineHeight / 2) * vars->step;
	while (drawStart <= drawEnd)
	{
		vars->texY = (int)vars->texPos;
		vars->texPos += vars->step;
		color = (unsigned int)vars->buffer[texHeight * vars->texY + vars->texX];
		my_mlx_pixel_put(vars, x, drawStart, color);

		++drawStart;
	}
}

void draw_sprite(int color, t_vars *vars)
{
	int sprite;

	int i;
	int d;

	sprite = vars->drawStartX;
	while (sprite < vars->drawEndX)
	{
		vars->texX = (int)(256 * (sprite - (-vars->spriteWidth / 2 + vars->spriteScreenX)) * texWidth / vars->spriteWidth) / 256;
		if (vars->transformY > 0 && sprite > 0 && sprite < screenWidth && vars->transformY < vars->ZBuffer[sprite])
		{
			i = vars->drawStartY;

			while (i < vars->drawEndY)
			{
				d = (i)*256 - screenHeight * 128 + vars->spriteHeight * 128;
				vars->texY = ((d * 64) / vars->spriteHeight) / 256;
				color = (unsigned int)vars->buffer[64 * vars->texY + vars->texX];
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(vars, sprite, i, color);
				i++;
			}
		}
		sprite++;
	}
}

void draw_sky(int x, int drawStart, t_vars *vars)
{
	int j;

	j = 0;

	while (j < drawStart)
	{
		my_mlx_pixel_put(vars, x, j, 0x19D9F0);
		j++;
	}
}
void draw_floor(int x, int drawStart, int drawEnd, unsigned int color, t_vars *vars)
{
	
	while (drawEnd < screenHeight)
	{
		my_mlx_pixel_put(vars, x, drawEnd, 0xED1010);
		drawEnd++;
	}
}
