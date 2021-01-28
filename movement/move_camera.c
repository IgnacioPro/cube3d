/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:20:40 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/28 20:18:30 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	move_camera(t_vars *vars)
{
	if (vars->right == 1)
	{
		vars->oldirx = vars->dirx;
		vars->dirx = vars->dirx * cos(-ROTATION) - vars->diry * sin(-ROTATION);
		vars->diry = vars->oldirx * sin(-ROTATION) +
			vars->diry * cos(-ROTATION);
		vars->oldplanex = vars->px;
		vars->px = vars->px * cos(-ROTATION) - vars->py * sin(-ROTATION);
		vars->py = vars->oldplanex * sin(-ROTATION) + vars->py * cos(-ROTATION);
	}
	if (vars->left == 1)
	{
		vars->oldirx = vars->dirx;
		vars->dirx = vars->dirx * cos(ROTATION) - vars->diry * sin(ROTATION);
		vars->diry = vars->oldirx * sin(ROTATION) + vars->diry * cos(ROTATION);
		vars->oldplanex = vars->px;
		vars->px = vars->px * cos(ROTATION) - vars->py * sin(ROTATION);
		vars->py = vars->oldplanex * sin(ROTATION) + vars->py * cos(ROTATION);
	}
}
