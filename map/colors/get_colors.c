/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:50:10 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/18 19:56:06 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	floor_color(t_data *data)
{
	data->i++;
	error_check(data);
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->floor[0] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->floor[1] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->floor[2] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] != '\0')
		rgb_error();
	data->n_lines++;
}

void	ceiling_color(t_data *data)
{
	data->i++;
	error_check(data);
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->ceiling[0] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->ceiling[1] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->ceiling[2] = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] != '\0')
		rgb_error();
	data->n_lines++;
}
