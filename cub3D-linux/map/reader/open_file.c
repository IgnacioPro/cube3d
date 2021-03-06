/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:06:35 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/30 12:12:39 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	opening1(t_data *data, t_vars *vars)
{
	if (!data->arg1)
		error_opening_map();
	if ((data->fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	if (data->argc > 3 || data->argc < 2)
	{
		ft_putstr_fd("Error\nNumber of arguments is invalid\n", 2);
		exit(0);
	}
	map_name_validator(*data);
	if (data->argc == 3)
		save_image_validator(*data, vars);
}

void	opening2(t_data *data, t_vars *vars)
{
	int fd;
	int z;
	int i;

	z = 0;
	if ((fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	while ((i = get_next_line(fd, &data->linea)) > 0)
	{
		if (z < data->mapstart)
			z++;
		else
			map_parser(data);
		free(data->linea);
	}
	data->map = (char**)malloc(data->mapy * (sizeof(char*)));
	vars->worldmap = (char**)malloc(data->mapy * (sizeof(char*)));
	close(fd);
}

void	opening3(t_data *data, t_vars *vars)
{
	int fd;
	int i;
	int z;

	z = 0;
	if ((fd = open(data->arg1, O_RDONLY)) == -1)
		error_opening_map();
	free(data->linea);
	while ((i = get_next_line(fd, &data->linea)) > 0)
	{
		if (z < data->mapstart)
			z++;
		else
			map_store(data, vars);
		free(data->linea);
	}
	close(fd);
	if (data->coord_check != 1 || data->n_lines != 8)
		map_error();
	if (check_map(data->map, data->playerx, data->playery, data))
		map_error();
}

void	formatter(t_data *data)
{
	if (data->linea[data->i] == 'R')
		get_resolution(data);
	else if (data->linea[data->i] == 'N')
		north_texture(data);
	else if (data->linea[data->i] == 'S' && data->linea[data->i + 1] == ' ')
		sprite_texture(data);
	else if (data->linea[data->i] == 'S')
		south_texture(data);
	else if (data->linea[data->i] == 'E')
		east_texture(data);
	else if (data->linea[data->i] == 'W')
		west_texture(data);
	else if (data->linea[data->i] == 'F')
		floor_color(data);
	else if (data->linea[data->i] == 'C')
		ceiling_color(data);
}

void	file_reader(t_data *data)
{
	while ((get_next_line(data->fd, &data->linea)) > 0)
	{
		data->i = 0;
		while (data->linea[data->i] == ' ')
			data->i++;
		if (ft_strchr("NSEWFCR", data->linea[data->i]))
			formatter(data);
		else if (data->linea[data->i] == '1' ||
			data->linea[data->i] == '2' ||
			data->linea[data->i] == '0' ||
			data->linea[data->i] == 'N' ||
			data->linea[data->i] == 'S' ||
			data->linea[data->i] == 'E' ||
			data->linea[data->i] == 'W')
		{
			data->mapstart = data->rl;
			free(data->linea);
			break ;
		}
		else
			map_error();
		data->rl++;
		free(data->linea);
	}
	element_validator(data);
}
