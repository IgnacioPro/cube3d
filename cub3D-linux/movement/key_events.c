/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:24 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/02/03 11:16:51 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

int		move_player_press(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->w = 1;
	if (keycode == 115)
		vars->s = 1;
	if (keycode == 97)
		vars->a = 1;
	if (keycode == 100)
		vars->d = 1;
	if (keycode == 65363)
		vars->right = 1;
	if (keycode == 65361)
		vars->left = 1;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int		move_player_release(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->w = 0;
	if (keycode == 115)
		vars->s = 0;
	if (keycode == 97)
		vars->a = 0;
	if (keycode == 100)
		vars->d = 0;
	if (keycode == 65363)
		vars->right = 0;
	if (keycode == 65361)
		vars->left = 0;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
