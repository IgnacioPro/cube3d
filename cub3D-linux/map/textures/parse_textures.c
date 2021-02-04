/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:41:54 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/28 20:14:15 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	north_texture(t_data *data)
{
	if (data->linea[data->i + 1] == 'O')
	{
		data->i += 2;
		if (data->linea[data->i] != ' ')
			texture_error();
		while (data->linea[data->i] == ' ')
			data->i++;
		data->north = ft_strdup(&data->linea[data->i]);
		while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
			data->i++;
		data->n_lines++;
		data->n_tex++;
	}
	else
		map_error();
}

void	south_texture(t_data *data)
{
	if (data->linea[data->i + 1] == 'O' && data->s_tex == 0)
	{
		data->i += 2;
		if (data->linea[data->i] != ' ')
			texture_error();
		while (data->linea[data->i] == ' ')
			data->i++;
		data->south = ft_strdup(&data->linea[data->i]);
		while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
			data->i++;
		data->n_lines++;
		data->s_tex++;
	}
	else
		map_error();
}

void	east_texture(t_data *data)
{
	if (data->linea[data->i + 1] == 'A' && data->e_tex == 0)
	{
		data->e_tex++;
		data->i += 2;
		if (data->linea[data->i] != ' ')
			texture_error();
		while (data->linea[data->i] == ' ')
			data->i++;
		data->east = ft_strdup(&data->linea[data->i]);
		while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
			data->i++;
		data->n_lines++;
	}
	else
		map_error();
}

void	west_texture(t_data *data)
{
	if (data->linea[data->i + 1] == 'E' && data->w_tex == 0)
	{
		data->w_tex++;
		data->i += 2;
		if (data->linea[data->i] != ' ')
			texture_error();
		while (data->linea[data->i] == ' ')
			data->i++;
		data->west = ft_strdup(&data->linea[data->i]);
		while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
			data->i++;
		data->n_lines++;
	}
	else
		map_error();
}

void	sprite_texture(t_data *data)
{
	data->i++;
	if (ft_strchr("120NSEW", data->linea[data->i]))
		map_error();
	if ((data->linea[data->i] != ' ') && (data->sp_tex == 0))
		map_error();
	if (ft_strchr("120NSEW", data->linea[data->i]))
		map_error();
	while (data->linea[data->i] == ' ')
		data->i++;
	data->sprite = ft_strdup(&data->linea[data->i]);
	while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
	data->n_lines++;
	data->sp_tex++;
}
