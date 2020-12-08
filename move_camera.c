/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:20:40 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/12/08 18:44:11 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubelib.h"


void move_camera(int keycode, t_vars *vars)
{
if (keycode == 124) // look right
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
		vars->dirY = vars->oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
		vars->planeY = vars->oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);
	}
	if (keycode == 123) // look left
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
		vars->dirY = vars->oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
		vars->planeY = vars->oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
	}
}