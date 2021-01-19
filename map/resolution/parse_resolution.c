/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:58:07 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/18 19:56:20 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

int		valid_resolution(int c)
{
	if (ft_isdigit(c) || c == 32)
		return (1);
	return (0);
}

void	resolution_format(t_data *data)
{
	int i;

	data->y = -1;
	i = data->i + 1;
	while (data->linea[i] != '\0')
	{
		if (!(valid_resolution(data->linea[i])))
			resolution_error();
		i++;
	}
	data->i++;
}

void	get_resolution(t_data *data)
{
	resolution_format(data);
	if (data->linea[data->i] != ' ')
		resolution_error();
	data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->x = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->y = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	while (data->linea[data->i] != '\0')
	{
		if (data->linea[data->i] != ' ')
			resolution_error();
		data->i++;
	}
	if (data->y <= 0 || data->x <= 0)
		resolution_error();
	data->n_lines++;
	// free(data->linea);
}
