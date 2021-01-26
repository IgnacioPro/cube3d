/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/26 12:23:12 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_up(t_vars *vars)
{
	if (vars->w == 1)
	{
		if (vars->posx + vars->dirx * SPEED > 1 &&
			vars->posx + vars->dirx * SPEED < (double)vars->mapwidth - 1)
			vars->posx += vars->dirx * SPEED;
		if (vars->posy + vars->diry * SPEED > 1 &&
			vars->posy + vars->diry * SPEED < (double)vars->mapheight - 1)
			vars->posy += vars->diry * SPEED;
	}
	
	// if (vars->w == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx +
	// 		vars->dirx * SPEED)][(int)vars->posy] == '0')
	// 		vars->posx += vars->dirx * SPEED;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->diry * SPEED)] == '0')
	// 		vars->posy += vars->diry * SPEED;
	// }
	// if (vars->w == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posy)][(int)(vars->posx + vars->dirx)] != '1')
	// 		vars->posx += vars->dirx;
	// 	if (vars->worldmap[(int)(vars->posy + vars->diry)][(int)(vars->posx)] != '1')
	// 		vars->posy += vars->diry;
		
	// }
	
}

void	move_down(t_vars *vars)
{
	if (vars->s == 1)
	{
		if (vars->posx - vars->dirx * SPEED > 1 &&
			vars->posx - vars->dirx * SPEED < (double)vars->mapwidth - 1.5)
			vars->posx -= vars->dirx * SPEED;
		if (vars->posy - vars->diry * SPEED > 1 &&
			vars->posy - vars->diry * SPEED < (double)vars->mapheight - 1.5)
			vars->posy -= vars->diry * SPEED;
	}
	// if (vars->s == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx -
	// 		vars->dirx * SPEED)][(int)vars->posy] == '0')
	// 		vars->posx -= vars->dirx * SPEED;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->diry * SPEED)] == '0')
	// 		vars->posy -= vars->diry * SPEED;
	// }
}

void	move_right(t_vars *vars)
{
	if (vars->a == 1)
	{
		if (vars->posx - vars->diry * SPEED > 1 &&
			vars->posx - vars->diry * SPEED < (double)vars->mapwidth - 1.5)
			vars->posx -= vars->diry * SPEED;
		if (vars->posy + vars->dirx * SPEED > 1 &&
			vars->posy + vars->dirx * SPEED < (double)vars->mapheight - 1.5)
			vars->posy += vars->dirx * SPEED;
	}
	// if (vars->a == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx -
	// 		vars->diry * SPEED)][(int)vars->posy] == '0')
	// 		vars->posx -= vars->dirx * SPEED;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->dirx * SPEED)] == '0')
	// 		vars->posy += vars->dirx * SPEED;
	// }
	
}

void	move_left(t_vars *vars)
{
	if (vars->d == 1)
	{
		if (vars->posx + vars->diry * SPEED > 1 &&
			vars->posx + vars->diry * SPEED < (double)vars->mapwidth - 1.5)
			vars->posx += vars->diry * SPEED;
		if (vars->posy - vars->dirx * SPEED > 1 &&
			vars->posy - vars->dirx * SPEED < (double)vars->mapheight - 1.5)
			vars->posy -= vars->dirx * SPEED;
	}
	// if (vars->d == 1)
	// {
	// 	if (vars->worldmap[(int)(vars->posx  +
	// 		vars->diry * SPEED)][(int)vars->posy] == '0')
	// 		vars->posx += vars->diry * SPEED;
		
	// 	if (vars->worldmap[(int)vars->posx][(int)(vars->posy + 
	// 		vars->dirx * SPEED)] == '0')
	// 		vars->posy -= vars->dirx * SPEED;
	// }
}
