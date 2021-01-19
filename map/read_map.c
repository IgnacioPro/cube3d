/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2021/01/19 11:38:25 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

void	print_all(t_data *data)
{
	int i;

	printf("La resolucion x es: %d\nLa resolucion  y es: %d\n", data->x, data->y);
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

// void	vars_init(t_data *data, t_vars *vars)
// {
// 	data->mapy = 0;
// 	data->mapx = 0;
// 	data->coord_check = 0;
// 	data->c = 0;
// 	data->n_lines = 0;
// 	data->rl = 0;
// 	data->rgb_error = 0;
// 	vars->moveSpeed = 0.1;
// 	vars->rotSpeed = 0.1;
// 	vars->posX = 22;
// 	vars->posY = 11;
// 	vars->dirX = -1;
// 	vars->dirY = 0;
// 	vars->planeX = 0;
// 	vars->planeY = 0.66;
// 	vars->a = 0;
// 	vars->d = 0;
// 	vars->w = 0;
// 	vars->s = 0;
// 	vars->left = 0;
// 	vars->right = 0;
// 	vars->i = 0;
// 	vars->screenheight = 480;
// 	vars->screenwidth = 640;
// }

// int		main(int argc, char *argv[])
// {
// 	t_data	data;
// 	t_vars	vars;

// 	data.arg1 = argv[1];
// 	data.arg2 = argv[2];
// 	data.argc = argc;
// 	// vars_init(&data, &vars);
// 	opening1(&data);
// 	file_reader(&data);
// 	errors(&data);
// 	close(data.fd);
// 	opening2(&data);
// 	opening3(&data);
// 	if (check_map(data.map, data.playerx, data.playery, &data))
// 		map_error();
// 	print_all(&data);
// 	free(data.linea);
// 	free(data.map);
// 	// main_raycaster();
// 	return (0);
// }
