/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2021/01/26 13:18:09 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

void	alloc_map(t_data *data, t_vars *vars)
{
	data->map[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	vars->worldmap[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	data->map[data->c] = ft_memset(data->map[data->c], ' ', data->mapx);
	vars->worldmap[data->c] = ft_memset(vars->worldmap[data->c],
		'1', data->mapx);
	data->map[data->c][data->mapx] = '\0';
	vars->worldmap[data->c][data->mapx] = '\0';
}

// void	print_all(t_data *data)
// {	
// 	// int i;

// 	printf("La resolucion x es: %d\nLa resolucion  y es: %d\n", data->x, data->y);
// 	printf("Norte:%s\n", data->north);
// 	printf("Sur:%s\n", data->south);
// 	printf("Este:%s\n", data->east);
// 	printf("Oeste:%s\n", data->west);
// 	printf("Sprite:%s\n", data->sprite);
// 	printf("Floor 1:%d\n", data->floor[0]);
// 	printf("Floor 2:%d\n", data->floor[1]);
// 	printf("Floor 3:%d\n", data->floor[2]);
// 	printf("Ceiling 1:%d\n", data->ceiling[0]);
// 	printf("Ceiling 2:%d\n", data->ceiling[1]);
// 	printf("Ceiling 3:%d\n", data->ceiling[2]);
// 	printf("\nMapx: %d\n", data->mapx);
// 	printf("Mapy: %d\n", data->mapy);
// 	printf("Map start: %d\n", data->mapstart);
// 	printf("Player X: %d\n", data->playerx);
// 	printf("Player Y: %d\n", data->playery);
// }
