/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2021/01/15 12:03:27 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

void	map_name_validator(t_data data)
{
	char	*lastfour;
	int		j;

	lastfour = ft_substr(data.arg1, (ft_strlen(data.arg1) - 4), 5);
	j = ft_strncmp(lastfour, ".cub", 4);
	if (j != 0)
	{
		printf("Error. Map name is invalid.\n");
		exit(0);
	}
}

void	save_image_validator(t_data data)
{
	int j;

	j = ft_strncmp(data.arg2, "--save", 6);
	if (j != 0)
	{
		ft_putstr_fd("Error\nSecond argument is invalid. Try '--save'.\n", 2);
		exit(0);
	}
}

int		invalid_map_chars(int c)
{
	if (ft_strchr("012NSEW ", c))
		return (0);
	else
		return (1);
}

void	map_parser(t_data *data)
{
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strdup(data->linea);
	while (trim[i])
	{
		if (invalid_map_chars(trim[i]))
			map_error();
		if (ft_strchr("NSEW", trim[i]))
			data->coord_check++;
		i++;
	}
	data->mapy++;
	if (i > data->mapx)
		data->mapx = i;
	free(trim);
}

void	map_store(t_data *data)
{
	int i;

	i = 0;
	data->map[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	data->map[data->c] = ft_memset(data->map[data->c], ' ', data->mapx);
	data->map[data->c][data->mapx] = '\0';
	while (data->linea[i] != '\0')
	{
		data->map[data->c][i] = data->linea[i];
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
	data->c++;
}

int		check_map(char **map, int row, int col, t_data *data)
{
	char	c;
	int		ok;

	if (row < 0 || col < 0 || row >= data->mapy || col >= data->mapx)
		return (1);
	c = map[row][col];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[row][col] = '3';
	ok = check_map(map, row, col - 1, data);
	ok = ok == 0 ? check_map(map, row, col + 1, data) : ok;
	ok = ok == 0 ? check_map(map, row - 1, col, data) : ok;
	ok = ok == 0 ? check_map(map, row + 1, col, data) : ok;
	return (ok);
}

void	print_all(t_data *data)
{
	int i;

	printf("\nLa resolucion x es: %d\nLa resolucion  y es: %d\n", data->x, data->y);
	printf("Norte:%s\n", data->north);
	printf("Sur:%s\n", data->south);
	printf("Este:%s\n", data->east);
	printf("Oeste:%s\n", data->west);
	printf("Sprite:%s\n", data->sprite);
	printf("Floor 1:%d\n", data->floor[0]);
	printf("Floor 2:%d\n", data->floor[1]);
	printf("Floor 3:%d\n", data->floor[2]);
	printf("Ceiling 1:%d\n", data->ceiling[0]);
	printf("Ceiling 2:%d\n", data->ceiling[1]);
	printf("Ceiling 3:%d\n", data->ceiling[2]);
	printf("\nMapx: %d\n", data->mapx);
	printf("Mapy: %d\n", data->mapy);
	i = 0;
	while (i < data->mapy)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("Map start: %d\n", data->mapstart);
	printf("Player X: %d\n", data->playerx);
	printf("Player Y: %d\n", data->playery);
}

void	vars_init(t_data *data)
{
	data->mapy = 0;
	data->mapx = 0;
	data->coord_check = 0;
	data->c = 0;
	data->n_lines = 0;
	data->rl = 0;
	data->rgb_error = 0;
}

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

int		main(int argc, char *argv[])
{
	t_data	data;

	data.arg1 = argv[1];
	data.arg2 = argv[2];
	data.argc = argc;
	vars_init(&data);
	opening1(&data);
	file_reader(&data);
	errors(&data);
	close(data.fd);
	opening2(&data);
	opening3(&data);
	if (check_map(data.map, data.playerx, data.playery, &data))
		map_error();
	print_all(&data);
	free(data.linea);
	free(data.map);
	return (0);
}
