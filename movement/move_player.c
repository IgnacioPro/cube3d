/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 13:48:11 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_up(t_vars *vars)
{
	// if (vars->worldmap[(int)vars->posX][(int)vars->posY] != '1')
	// {
	if (vars->w == 1)
	{
		if (vars->posX + vars->dirX * vars->moveSpeed > 1 &&
			vars->posX + vars->dirX * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posX += vars->dirX * vars->moveSpeed;
		if (vars->posY + vars->dirY * vars->moveSpeed > 1 &&
			vars->posY + vars->dirY * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posY += vars->dirY * vars->moveSpeed;
	}
	
	// if (vars->w == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posX +
	// 		vars->dirX * vars->moveSpeed)][(int)vars->posY] == '0')
	// 		vars->posX += vars->dirX * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posX][(int)(vars->posY + 
	// 		vars->dirY * vars->moveSpeed)] == '0')
	// 		vars->posY += vars->dirY * vars->moveSpeed;
	// }
	
}

void	move_down(t_vars *vars)
{
	if (vars->s == 1)
	{
		if (vars->posX - vars->dirX * vars->moveSpeed > 1 &&
			vars->posX - vars->dirX * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posX -= vars->dirX * vars->moveSpeed;
		if (vars->posY - vars->dirY * vars->moveSpeed > 1 &&
			vars->posY - vars->dirY * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posY -= vars->dirY * vars->moveSpeed;
	}
	// if (vars->s == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posX -
	// 		vars->dirX * vars->moveSpeed)][(int)vars->posY] == '0')
	// 		vars->posX -= vars->dirX * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posX][(int)(vars->posY + 
	// 		vars->dirY * vars->moveSpeed)] == '0')
	// 		vars->posY -= vars->dirY * vars->moveSpeed;
	// }
}

void	move_right(t_vars *vars)
{
	if (vars->a == 1)
	{
		if (vars->posX - vars->dirY * vars->moveSpeed > 1 &&
			vars->posX - vars->dirY * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posX -= vars->dirY * vars->moveSpeed;
		if (vars->posY + vars->dirX * vars->moveSpeed > 1 &&
			vars->posY + vars->dirX * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posY += vars->dirX * vars->moveSpeed;
	}
	// if (vars->a == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posX -
	// 		vars->dirY * vars->moveSpeed)][(int)vars->posY] == '0')
	// 		vars->posX -= vars->dirX * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posX][(int)(vars->posY + 
	// 		vars->dirX * vars->moveSpeed)] == '0')
	// 		vars->posY += vars->dirX * vars->moveSpeed;
	// }
}

void	move_left(t_vars *vars)
{
	if (vars->d == 1)
	{
		if (vars->posX + vars->dirY * vars->moveSpeed > 1 &&
			vars->posX + vars->dirY * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posX += vars->dirY * vars->moveSpeed;
		if (vars->posY - vars->dirX * vars->moveSpeed > 1 &&
			vars->posY - vars->dirX * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posY -= vars->dirX * vars->moveSpeed;
	}
	// if (vars->d == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posX  +
	// 		vars->dirY * vars->moveSpeed)][(int)vars->posY] == '0')
	// 		vars->posX += vars->dirY * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posX][(int)(vars->posY + 
	// 		vars->dirX * vars->moveSpeed)] == '0')
	// 		vars->posY -= vars->dirX * vars->moveSpeed;
	// }
}
