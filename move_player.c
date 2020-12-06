/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:17:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/06 18:38:11 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"

// void move_up(t_vars *vars)
// {
//     if (vars->keycode == 126) //up
// 	{
// 		if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
// 			vars->posX += vars->dirX * vars->moveSpeed;
// 		if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
// 			vars->posY += vars->dirY * vars->moveSpeed;
// 	}
// }

// int move_player(t_vars *vars) //
// {
// 	move_up(vars);

// 	if (vars->keycode == 125) //down
// 	{
// 		if (worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
// 			vars->posX -= vars->dirX * vars->moveSpeed;
// 		if (worldMap[(int)vars->posX][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
// 			vars->posY -= vars->dirY * vars->moveSpeed;
// 	}
// 	if (vars->keycode == 124) //right
// 	{
// 		double oldDirX = vars->dirX;
// 		vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
// 		vars->dirY = oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
// 		double oldPlaneX = vars->planeX;
// 		vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
// 		vars->planeY = oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);
// 	}
// 	if (vars->keycode == 123) //left
// 	{
// 		double oldDirX = vars->dirX;
// 		vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
// 		vars->dirY = oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
// 		double oldPlaneX = vars->planeX;
// 		vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
// 		vars->planeY = oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
// 	}

// 	if (vars->keycode == 0) // // A
// 	{
// 		if (worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)vars->posY] == 0)
// 			vars->posX += vars->dirY * vars->moveSpeed;
// 		if (worldMap[(int)vars->posX][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
// 			vars->posY += vars->dirY * vars->moveSpeed;
// 	}
// 	// if (keycode == 2) // // D
// 	// if (keycode == 13) // // W
// 	// if (keycode == 1) // // S
// 	if (vars->keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	return (0);
// }

