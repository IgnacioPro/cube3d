/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:53:59 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/24 17:50:52 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

void	draw_walls(int x, int drawStart, int drawEnd, int color, t_img *img, t_vars *vars)
{
	vars->step = 1.0 * texHeight / vars->lineHeight;
	vars->texPos = (drawStart - vars->screenheight / 2 + 
	vars->lineHeight / 2) * vars->step;
	while (drawStart <= drawEnd) //cambiado de <=
	{
		vars->texY = (int)vars->texPos;
		vars->texPos += vars->step;
		color = (unsigned int)vars->buffer[texHeight * vars->texY + vars->texX];
		my_mlx_pixel_put(img, x, drawStart, color);
		drawStart++;
	}
}

void	draw_sprite(int color, t_vars *vars)
{
	int sprite;
	int i;
	int d;

	sprite = vars->drawStartX;
	while (sprite < vars->drawEndX)
	{
		vars->texX = (int)(256 * (sprite - (-vars->spriteWidth / 2 +
		vars->screenx))
		* texWidth / vars->spriteWidth) / 256;
		if (vars->t_y > 0.01 && sprite > 0.01 && sprite < vars->screenwidth &&
		vars->t_y < vars->ZBuffer[sprite])
		{
			i = vars->drawStartY;
			while (i < vars->drawEndY)
			{
				d = (i)*256 - vars->screenheight * 128 + vars->spriteHeight * 128;
				vars->texY = ((d * 64) / vars->spriteHeight) / 256;
				color = (unsigned int)vars->buffer[64 * vars->texY + vars->texX];
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&vars->imagen, sprite, i, color);
				i++;
			}
		}
		sprite++;
	}
}

void	draw_sky_floor(int x, int drawStart, int drawEnd, t_img *img, t_vars *vars)
{
	int j;

	j = 0;
	while (j < (drawStart))
	{
		my_mlx_pixel_put(img, x, j, 0x19D9F0);
		j++;
	}
	j = drawEnd;
	while (j < vars->screenheight && j > 0)
	{
		my_mlx_pixel_put(img, x, j, 0xED1010);
		j++;
	}
}
