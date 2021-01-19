/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:41:54 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/18 19:55:16 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	north_texture(t_data *data)
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
}

void	south_texture(t_data *data)
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
}

void	east_texture(t_data *data)
{
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

void	west_texture(t_data *data)
{
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

void	sprite_texture(t_data *data)
{
	data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	data->sprite = ft_strdup(&data->linea[data->i]);
	while (ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
	if (data->sprite == '\0')
		texture_error();
	data->n_lines++;
}
