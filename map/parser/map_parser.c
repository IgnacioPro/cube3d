/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:16:05 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/20 18:35:08 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

int		invalid_map_chars(int c)
{
	if (ft_strchr("012NSEW ", c))
		return (0);
	else
		return (1);
}

void	map_parser(t_data *data)
{
	// char	*trim;
	int		i;

	i = 0;
	// trim = (char*)malloc(ft_strlen(data->linea) * sizeof(char));
	// trim = ft_strdup(data->linea);
	while (data->linea[i])
	{
		if (invalid_map_chars(data->linea[i]))
			map_error();
		if (ft_strchr("NSEW", data->linea[i]))
			data->coord_check++;
		i++;
	}
	// free(trim);
	// free(data->linea);
	data->mapy++;
	if (i > data->mapx)
		data->mapx = i;
}

void	map_store(t_data *data)
{
	int i;

	i = 0;
	data->map[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	// data->map[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	data->map[data->c] = ft_memset(data->map[data->c], ' ', data->mapx);
	data->map[data->c][data->mapx] = '\0';
	while (data->linea[i] != '\0')
	{
		data->map[data->c][i] = (data->linea[i]);

		if (data->linea[i] == ' ')
			data->map[data->c][i] = ' ';
		if (ft_strchr("NSEW", data->map[data->c][i]))
		{
			data->playerx = data->c;
			data->playery = i;
			data->map[data->playerx][data->playery] = '0';
		}
		i++;
	}
	// data->map[data->c][i] = '\0'; 
	data->c++;
	// free(data->linea);
}

int		check_map(char **map, int row, int col, t_data *data)
{
	int		ok;

	if (row < 0 || col < 0 || row >= data->mapy || col >= data->mapx)
		return (1);
	if (map[row][col] == ' ')
		return (1);
	else if (map[row][col] == '3' || map[row][col] == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col - 1, data);
	ok = ok == 0 ? check_map(map, row, col + 1, data) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col, data) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col, data) : ok;
	return (ok);
}