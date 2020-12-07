/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/07 19:20:25 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

void move_up(int keycode, t_vars *vars)
{
   if (keycode == 13) // W
	{
		// if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirX * vars->moveSpeed;
		// if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
			vars->posY += vars->dirY * vars->moveSpeed;
	}
}

void move_down(int keycode, t_vars *vars)
{
    if (keycode == 1) // S
	{
		// if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirX * vars->moveSpeed;
		// if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
}

void move_left(int keycode, t_vars *vars)
{
    if (keycode == 0) // A
	{
		// if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirY * vars->moveSpeed;
		// if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY += vars->dirX * vars->moveSpeed;
	}
}

void move_right(int keycode, t_vars *vars)
{
    if (keycode == 2) // D
	{
		// if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirY * vars->moveSpeed;
		// if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirX * vars->moveSpeed;
	}
}
