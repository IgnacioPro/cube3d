/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 23:07:06 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_up(t_vars *vars)
{
	if (vars->w == 1)
	{
		if (vars->posx + vars->dirx * vars->moveSpeed > 1 &&
			vars->posx + vars->dirx * vars->moveSpeed < (double)vars->mapwidth - 1)
			vars->posx += vars->dirx * vars->moveSpeed;
		if (vars->posy + vars->diry * vars->moveSpeed > 1 &&
			vars->posy + vars->diry * vars->moveSpeed < (double)vars->mapheight - 1)
			vars->posy += vars->diry * vars->moveSpeed;
	}
	
	// if (vars->w == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx +
	// 		vars->dirx * vars->moveSpeed)][(int)vars->posy] == '0')
	// 		vars->posx += vars->dirx * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->diry * vars->moveSpeed)] == '0')
	// 		vars->posy += vars->diry * vars->moveSpeed;
	// }
	
}

void	move_down(t_vars *vars)
{
	if (vars->s == 1)
	{
		if (vars->posx - vars->dirx * vars->moveSpeed > 1 &&
			vars->posx - vars->dirx * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posx -= vars->dirx * vars->moveSpeed;
		if (vars->posy - vars->diry * vars->moveSpeed > 1 &&
			vars->posy - vars->diry * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posy -= vars->diry * vars->moveSpeed;
	}
	// if (vars->s == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx -
	// 		vars->dirx * vars->moveSpeed)][(int)vars->posy] == '0')
	// 		vars->posx -= vars->dirx * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->diry * vars->moveSpeed)] == '0')
	// 		vars->posy -= vars->diry * vars->moveSpeed;
	// }
}

void	move_right(t_vars *vars)
{
	if (vars->a == 1)
	{
		if (vars->posx - vars->diry * vars->moveSpeed > 1 &&
			vars->posx - vars->diry * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posx -= vars->diry * vars->moveSpeed;
		if (vars->posy + vars->dirx * vars->moveSpeed > 1 &&
			vars->posy + vars->dirx * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posy += vars->dirx * vars->moveSpeed;
	}
	// if (vars->a == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx -
	// 		vars->diry * vars->moveSpeed)][(int)vars->posy] == '0')
	// 		vars->posx -= vars->dirx * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->dirx * vars->moveSpeed)] == '0')
	// 		vars->posy += vars->dirx * vars->moveSpeed;
	// }
}

void	move_left(t_vars *vars)
{
	if (vars->d == 1)
	{
		if (vars->posx + vars->diry * vars->moveSpeed > 1 &&
			vars->posx + vars->diry * vars->moveSpeed < (double)vars->mapwidth - 1.5)
			vars->posx += vars->diry * vars->moveSpeed;
		if (vars->posy - vars->dirx * vars->moveSpeed > 1 &&
			vars->posy - vars->dirx * vars->moveSpeed < (double)vars->mapheight - 1.5)
			vars->posy -= vars->dirx * vars->moveSpeed;
	}
	// if (vars->d == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx  +
	// 		vars->diry * vars->moveSpeed)][(int)vars->posy] == '0')
	// 		vars->posx += vars->diry * vars->moveSpeed;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->dirx * vars->moveSpeed)] == '0')
	// 		vars->posy -= vars->dirx * vars->moveSpeed;
	// }
}
