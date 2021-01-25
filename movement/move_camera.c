/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:20:40 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 23:41:18 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_camera(t_vars *vars)
{
	if (vars->right == 1)
	{
		vars->oldirx = vars->dirx;
		vars->dirx = vars->dirx * cos(-vars->rotSpeed) - vars->diry * sin(-vars->rotSpeed);
		vars->diry = vars->oldirx * sin(-vars->rotSpeed) + vars->diry * cos(-vars->rotSpeed);
		vars->oldplanex = vars->px;
		vars->px = vars->px * cos(-vars->rotSpeed) - vars->py * sin(-vars->rotSpeed);
		vars->py = vars->oldplanex * sin(-vars->rotSpeed) + vars->py * cos(-vars->rotSpeed);
	}
	if (vars->left == 1)
	{
		vars->oldirx = vars->dirx;
		vars->dirx = vars->dirx * cos(vars->rotSpeed) - vars->diry * sin(vars->rotSpeed);
		vars->diry = vars->oldirx * sin(vars->rotSpeed) + vars->diry * cos(vars->rotSpeed);
		vars->oldplanex = vars->px;
		vars->px = vars->px * cos(vars->rotSpeed) - vars->py * sin(vars->rotSpeed);
		vars->py = vars->oldplanex * sin(vars->rotSpeed) + vars->py * cos(vars->rotSpeed);
	}
}
