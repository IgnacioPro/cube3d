/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/09 12:17:24 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

void move_up(t_vars *vars)
{
	if (vars->w == 1)
	{
		if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
			vars->posY += vars->dirY * vars->moveSpeed;
	}
}

void move_down(t_vars *vars)
{
    if (vars->s == 1) // S
	{
		if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
}

void move_left(t_vars *vars)
{
    if (vars->a == 1) // A
	{
		if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX -= vars->dirY * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY += vars->dirX * vars->moveSpeed;
	}
}

void move_right(t_vars *vars)
{
    if (vars->d == 1) // D
	{
		if (worldMap[(int)(vars->posX + vars->dirY * vars->moveSpeed)][(int)vars->posY] == 0)
			vars->posX += vars->dirY * vars->moveSpeed;
		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirX * vars->moveSpeed)] == 0)
			vars->posY -= vars->dirX * vars->moveSpeed;
	}
}
