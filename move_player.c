/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/11 13:53:37 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

void move_up(t_vars *vars)
{
	if (vars->w == 1)
	{
		if (vars->posX + vars->dirX * vars->moveSpeed >= 1 && vars->posX + vars->dirX * vars->moveSpeed < (double)mapWidth - 1)
			vars->posX += vars->dirX * vars->moveSpeed;
		if (vars->posY + vars->dirY * vars->moveSpeed >= 1 && vars->posY + vars->dirY * vars->moveSpeed < (double)mapHeight - 1)
			vars->posY += vars->dirY * vars->moveSpeed;
	}
}

void move_down(t_vars *vars)
{
    if (vars->s == 1) // S
	{
		if (vars->posX - vars->dirX * vars->moveSpeed >= 1 && vars->posX - vars->dirX * vars->moveSpeed < (double)mapWidth - 1)
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (vars->posY - vars->dirY * vars->moveSpeed >= 1 && vars->posY - vars->dirY * vars->moveSpeed < (double)mapHeight - 1)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
}

void move_left(t_vars *vars)
{
    if (vars->a == 1) // A
	{
		if (vars->posX - vars->dirY * vars->moveSpeed >= 1 && vars->posX - vars->dirY * vars->moveSpeed < (double)mapWidth - 1)
			vars->posX -= vars->dirY * vars->moveSpeed;
		if (vars->posY += vars->dirX * vars->moveSpeed >= 1 && vars->posY + vars->dirX * vars->moveSpeed < (double)mapHeight - 1)
			vars->posY += vars->dirX * vars->moveSpeed;
	}
}

void move_right(t_vars *vars)
{
    if (vars->d == 1) // D
	{
		if (vars->posX + vars->dirY * vars->moveSpeed >= 1 && vars->posX + vars->dirY * vars->moveSpeed < (double)mapWidth - 1)
			vars->posX += vars->dirY * vars->moveSpeed;
		if (vars->posY - vars->dirX * vars->moveSpeed >= 1 && vars->posY - vars->dirX * vars->moveSpeed < (double)mapHeight - 1)
			vars->posY -= vars->dirX * vars->moveSpeed;
	}
}
