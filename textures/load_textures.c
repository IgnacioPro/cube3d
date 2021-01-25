/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:17:12 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/25 23:36:44 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void	load_textures(t_vars *vars, t_data *data)
{
	if (!(vars->norte.img = mlx_xpm_file_to_image(vars->mlx, data->north,
		&vars->norte.height, &vars->norte.width)))
		texture_error();
	if (!(vars->sur.img = mlx_xpm_file_to_image(vars->mlx, data->south,
		&vars->sur.height, &vars->sur.width)))
		texture_error();
	if (!(vars->este.img = mlx_xpm_file_to_image(vars->mlx, data->east,
		&vars->este.height, &vars->este.width)))
		texture_error();
	if (!(vars->oeste.img = mlx_xpm_file_to_image(vars->mlx, data->west,
		&vars->oeste.height, &vars->oeste.width)))
		texture_error();
	if (!(vars->columna.img = mlx_xpm_file_to_image(vars->mlx, data->sprite,
		&vars->columna.height, &vars->columna.width)))
		texture_error();
}

void	textures_to_struc(t_vars *vars)
{
	if (vars->side == 0 && vars->stepx == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->norte.img,
		&vars->norte.bits_per_pixel, &vars->norte.line_length,
		&vars->norte.endian);
	else if (vars->side == 0 && vars->stepx == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->sur.img,
		&vars->sur.bits_per_pixel, &vars->sur.line_length,
		&vars->sur.endian);
	else if (vars->side == 1 && vars->stepy == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->este.img,
		&vars->este.bits_per_pixel, &vars->este.line_length,
		&vars->este.endian);
	else if (vars->side == 1 && vars->stepy == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->oeste.img,
		&vars->oeste.bits_per_pixel, &vars->oeste.line_length,
		&vars->oeste.endian);
}