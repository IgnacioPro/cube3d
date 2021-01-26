/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:25:20 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/26 20:31:19 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	errors(t_data *data)
{
	if (data->ceiling[0] > 255 || data->ceiling[1] > 255 ||
		data->ceiling[2] > 255 || data->floor[0] > 255 ||
		data->floor[1] > 255 ||
		data->floor[2] > 255)
		rgb_error();
	if (data->n_lines != 8)
		map_error();
}

int		valid_rgb(int c)
{
	if (ft_isdigit(c) || c == 44 || c == 32)
		return (1);
	return (0);
}

void	error_check(t_data *data)
{
	int i;

	i = data->i;
	data->comma = 0;
	if (data->linea[i] != ' ')
		data->rgb_error = 1;
	while (data->linea[i] != '\0')
	{
		if (data->linea[i] == ',')
			data->comma++;
		if (data->linea[i] == '-')
			data->rgb_error = 1;
		if (data->linea[i] == ',' && data->linea[i + 1] == ',')
			data->rgb_error = 1;
		if (!(valid_rgb(data->linea[i])))
			data->rgb_error = 1;
		i++;
	}
	if (data->comma != 2)
		data->rgb_error = 1;
	if (data->rgb_error == 1)
		rgb_error();
}
