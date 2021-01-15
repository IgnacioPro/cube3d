/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:06:35 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/15 12:08:27 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	opening2(t_data *data)
{
	int fd;
	int z;
	int i;

	z = 0;
	i = 0;
	if ((fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	while ((i = get_next_line(fd, &data->linea)) > 0)
	{
		if (z < data->mapstart)
			z++;
		else
			map_parser(data);
	}
	data->map = (char**)malloc(data->mapy * (sizeof(char*)));
	close(fd);
}

void	opening3(t_data *data)
{
	int fd;
	int i;
	int z;

	z = 0;
	if ((fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	while ((i = get_next_line(fd, &data->linea)) > 0)
	{
		if (z < data->mapstart)
			z++;
		else
			map_store(data);
	}
	close(fd);
	if (data->coord_check != 1 || data->n_lines != 8)
		map_error();
}

void	opening1(t_data *data)
{
	if ((data->fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	if (!data->arg1)
		error_opening_map();
	if (data->argc > 3 || data->argc < 2)
	{
		ft_putstr_fd("Error\nNumber of arguments is invalid\n", 2);
		exit(0);
	}
	map_name_validator(*data);
	if (data->argc == 3)
		save_image_validator(*data);
}

void	formatter(t_data *data)
{
	data->i = 0;
	while (data->linea[data->i] == ' ')
		data->i++;
	if (data->linea[data->i] == 'R')
		get_resolution(data);
	else if (data->linea[data->i] == 'N' && data->linea[data->i + 1] == 'O')
		north_texture(data);
	else if (data->linea[data->i] == 'S' && data->linea[data->i + 1] == ' ')
		sprite_texture(data);
	else if (data->linea[data->i] == 'S' && data->linea[data->i + 1] != ' ' &&
		data->linea[data->i + 1] != 'O')
		texture_error();
	else if (data->linea[data->i] == 'S' && data->linea[data->i + 1] == 'O')
		south_texture(data);
	else if (data->linea[data->i] == 'E' && data->linea[data->i + 1] == 'A')
		east_texture(data);
	else if (data->linea[data->i] == 'W' && data->linea[data->i + 1] == 'E')
		west_texture(data);
	else if (data->linea[data->i] == 'F')
		floor_color(data);
	else if (data->linea[data->i] == 'C')
		ceiling_color(data);
}

void	file_reader(t_data *data)
{
	int i;

	while ((i = get_next_line(data->fd, &data->linea)) > 0)
	{
		formatter(data);
		if (data->linea[data->i] == '1' ||
			data->linea[data->i] == '2' ||
			data->linea[data->i] == '0' ||
			data->linea[data->i] == 'N' ||
			data->linea[data->i] == 'S' ||
			data->linea[data->i] == 'E' ||
			data->linea[data->i] == 'W')
		{
			data->mapstart = data->rl;
			break ;
		}
		data->rl++;
	}
}
