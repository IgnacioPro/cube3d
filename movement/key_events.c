/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:24 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/24 18:04:00 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

int		move_player_press(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->w = 1;
	if (keycode == 1)
		vars->s = 1;
	if (keycode == 0)
		vars->a = 1;
	if (keycode == 2)
		vars->d = 1;
	if (keycode == 124)
		vars->right = 1;
	if (keycode == 123)
		vars->left = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int		move_player_release(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->w = 0;
	if (keycode == 1)
		vars->s = 0;
	if (keycode == 0)
		vars->a = 0;
	if (keycode == 2)
		vars->d = 0;
	if (keycode == 124)
		vars->right = 0;
	if (keycode == 123)
		vars->left = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
