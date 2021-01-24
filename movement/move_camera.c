/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:20:40 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/24 18:00:57 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_camera(t_vars *vars)
{
	if (vars->right == 1)
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
		vars->dirY = vars->oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
		vars->oldPlaneX = vars->px;
		vars->px = vars->px * cos(-vars->rotSpeed) - vars->py * sin(-vars->rotSpeed);
		vars->py = vars->oldPlaneX * sin(-vars->rotSpeed) + vars->py * cos(-vars->rotSpeed);
	}
	if (vars->left == 1)
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
		vars->dirY = vars->oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
		vars->oldPlaneX = vars->px;
		vars->px = vars->px * cos(vars->rotSpeed) - vars->py * sin(vars->rotSpeed);
		vars->py = vars->oldPlaneX * sin(vars->rotSpeed) + vars->py * cos(vars->rotSpeed);
	}
}
